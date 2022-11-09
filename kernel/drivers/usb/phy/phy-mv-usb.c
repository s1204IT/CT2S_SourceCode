/*
 * Copyright (C) 2011 Marvell International Ltd. All rights reserved.
 * Author: Chao Xie <chao.xie@marvell.com>
 *	   Neil Zhang <zhangwm@marvell.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/proc_fs.h>
#include <linux/clk.h>
#include <linux/of.h>
#include <linux/workqueue.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>

#include <linux/usb.h>
#include <linux/usb/ch9.h>
#include <linux/usb/otg.h>
#include <linux/usb/gadget.h>
#include <linux/usb/hcd.h>
#include <linux/usb/mv_usb2_phy.h>
#include <linux/platform_data/mv_usb.h>
#include <linux/pm_qos.h>
#include <linux/regs-addr.h>

#include "phy-mv-usb.h"
#include <../drivers/clk/mmp/clk.h>

#define	DRIVER_DESC	"Marvell USB OTG transceiver driver"
#define	DRIVER_VERSION	"Jan 20, 2010"
#define MAX_RETRY_TIMES 60
#define RETRY_SLEEP_MS  1000

#define APMU_SD_ROT_WAKE_CLR 0x7C
#define USB_OTG_ID_WAKEUP_EN (1<<8)
#define USB_OTG_ID_WAKEUP_CLR (1<<18)

MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION(DRIVER_VERSION);
MODULE_LICENSE("GPL");

static const char driver_name[] = "mv-otg";

static int otg_force_host_mode;

static char *state_string[] = {
	"undefined",
	"b_idle",
	"b_srp_init",
	"b_peripheral",
	"b_wait_acon",
	"b_host",
	"a_idle",
	"a_wait_vrise",
	"a_wait_bcon",
	"a_host",
	"a_suspend",
	"a_peripheral",
	"a_wait_vfall",
	"a_vbus_err"
};

/* need to write APMU register to enable USBID wakeup/irq */
void mv_otg_usbid_wakeup_en(int en)
{
	u32 tmp32;
	void __iomem *apmu_base = get_apmu_base_va();
	tmp32 = __raw_readl(apmu_base + APMU_SD_ROT_WAKE_CLR);
	if (en)
		tmp32 |= USB_OTG_ID_WAKEUP_EN;
	else
		tmp32 &= ~USB_OTG_ID_WAKEUP_EN;
	__raw_writel(tmp32, apmu_base + APMU_SD_ROT_WAKE_CLR);

}

/* need to write APMU register to clear USBID wakeup/irq */
void mv_otg_usbid_wakeup_clear(void)
{
	u32 tmp32;
	void __iomem *apmu_base = get_apmu_base_va();
	tmp32 = __raw_readl(apmu_base + APMU_SD_ROT_WAKE_CLR);

	/* to clear APMU USBID wakeup/irq, first wirte 1, then write 0 */
	tmp32 |= USB_OTG_ID_WAKEUP_CLR;
	__raw_writel(tmp32, apmu_base + APMU_SD_ROT_WAKE_CLR);
	tmp32 &= ~USB_OTG_ID_WAKEUP_CLR;
	__raw_writel(tmp32, apmu_base + APMU_SD_ROT_WAKE_CLR);

}

static int mv_otg_set_vbus(struct usb_otg *otg, bool on)
{
	struct mv_otg *mvotg = container_of(otg->phy, struct mv_otg, phy);
	int ret;
	/* set constraint before turn on vbus */
	if (on) {
		pm_stay_awake(&mvotg->pdev->dev);
		pm_qos_update_request(&mvotg->qos_idle, mvotg->lpm_qos);
	}

	if (mvotg->pdata->set_vbus) {
		ret = mvotg->pdata->set_vbus(on);
	}
	else {
		ret = pxa_usb_extern_call(mvotg->pdata->id, vbus, set_vbus, on);
	}

	/* release constraint after turn off vbus */
	if (!on) {
		pm_qos_update_request(&mvotg->qos_idle,
			PM_QOS_CPUIDLE_BLOCK_DEFAULT_VALUE);
		pm_relax(&mvotg->pdev->dev);
	}

	return ret;
}

static int mv_otg_set_host(struct usb_otg *otg,
			   struct usb_bus *host)
{
	otg->host = host;

	return 0;
}

static int mv_otg_set_peripheral(struct usb_otg *otg,
				 struct usb_gadget *gadget)
{
	otg->gadget = gadget;

	return 0;
}

static void mv_otg_run_state_machine(struct mv_otg *mvotg,
				     unsigned long delay)
{
	dev_dbg(&mvotg->pdev->dev, "transceiver is updated\n");
	if (!mvotg->qwork)
		return;

	queue_delayed_work(mvotg->qwork, &mvotg->work, delay);
}

static void mv_otg_timer_await_bcon(unsigned long data)
{
	struct mv_otg *mvotg = (struct mv_otg *) data;

	mvotg->otg_ctrl.a_wait_bcon_timeout = 1;

	dev_info(&mvotg->pdev->dev, "B Device No Response!\n");

	if (spin_trylock(&mvotg->wq_lock)) {
		mv_otg_run_state_machine(mvotg, 0);
		spin_unlock(&mvotg->wq_lock);
	}
}

static int mv_otg_cancel_timer(struct mv_otg *mvotg, unsigned int id)
{
	struct timer_list *timer;

	if (id >= OTG_TIMER_NUM)
		return -EINVAL;

	timer = &mvotg->otg_ctrl.timer[id];

	if (timer_pending(timer))
		del_timer(timer);

	return 0;
}

static int mv_otg_set_timer(struct mv_otg *mvotg, unsigned int id,
			    unsigned long interval,
			    void (*callback) (unsigned long))
{
	struct timer_list *timer;

	if (id >= OTG_TIMER_NUM)
		return -EINVAL;

	timer = &mvotg->otg_ctrl.timer[id];
	if (timer_pending(timer)) {
		dev_err(&mvotg->pdev->dev, "Timer%d is already running\n", id);
		return -EBUSY;
	}

	init_timer(timer);
	timer->data = (unsigned long) mvotg;
	timer->function = callback;
	timer->expires = jiffies + interval;
	add_timer(timer);

	return 0;
}

static int mv_otg_reset(struct mv_otg *mvotg)
{
	unsigned int loops;
	u32 tmp;

	/* Stop the controller */
	tmp = readl(&mvotg->op_regs->usbcmd);
	tmp &= ~USBCMD_RUN_STOP;
	writel(tmp, &mvotg->op_regs->usbcmd);

	/* Reset the controller to get default values */
	writel(USBCMD_CTRL_RESET, &mvotg->op_regs->usbcmd);

	loops = 500;
	while (readl(&mvotg->op_regs->usbcmd) & USBCMD_CTRL_RESET) {
		if (loops == 0) {
			dev_err(&mvotg->pdev->dev,
				"Wait for RESET completed TIMEOUT\n");
			return -ETIMEDOUT;
		}
		loops--;
		udelay(20);
	}

	writel(0x0, &mvotg->op_regs->usbintr);
	tmp = readl(&mvotg->op_regs->usbsts);
	writel(tmp, &mvotg->op_regs->usbsts);

	return 0;
}

static void mv_otg_init_irq(struct mv_otg *mvotg)
{
	u32 otgsc;

	mvotg->irq_en = OTGSC_INTR_A_SESSION_VALID
	    | OTGSC_INTR_A_VBUS_VALID;
	mvotg->irq_status = OTGSC_INTSTS_A_SESSION_VALID
	    | OTGSC_INTSTS_A_VBUS_VALID;

	if ((mvotg->pdata->extern_attr & MV_USB_HAS_VBUS_DETECTION) == 0) {
		mvotg->irq_en |= OTGSC_INTR_B_SESSION_VALID
		    | OTGSC_INTR_B_SESSION_END;
		mvotg->irq_status |= OTGSC_INTSTS_B_SESSION_VALID
		    | OTGSC_INTSTS_B_SESSION_END;
	}

	if ((mvotg->pdata->extern_attr & MV_USB_HAS_IDPIN_DETECTION) == 0) {
		mvotg->irq_en |= OTGSC_INTR_USB_ID;
		mvotg->irq_status |= OTGSC_INTSTS_USB_ID;
	}

	otgsc = readl(&mvotg->op_regs->otgsc);
	otgsc |= mvotg->irq_en;
	writel(otgsc, &mvotg->op_regs->otgsc);
}

static void mv_otg_start_host(struct mv_otg *mvotg, int on)
{
#ifdef CONFIG_USB
	struct usb_otg *otg = mvotg->phy.otg;
	struct usb_hcd *hcd;

	if (!otg->host) {
		int retry = 0;
		while (retry < MAX_RETRY_TIMES) {
			retry++;
			msleep(RETRY_SLEEP_MS);
			if (otg->host)
				break;
		}

		if (!otg->host) {
			dev_err(mvotg->phy.dev, "otg->host is not set!\n");
			return;
		}
	}

	dev_info(&mvotg->pdev->dev, "%s host\n", on ? "start" : "stop");

	hcd = bus_to_hcd(otg->host);

	if (on)
		usb_add_hcd(hcd, hcd->irq, IRQF_SHARED);
	else
		usb_remove_hcd(hcd);
#endif /* CONFIG_USB */
}

static void mv_otg_start_periphrals(struct mv_otg *mvotg, int on)
{
	struct usb_otg *otg = mvotg->phy.otg;

	if (!otg->gadget) {
		int retry = 0;
		while (retry < MAX_RETRY_TIMES) {
			retry++;
			msleep(RETRY_SLEEP_MS);
			if (otg->gadget)
				break;
		}

		if (!otg->gadget) {
			dev_err(mvotg->phy.dev, "otg->gadget is not set!\n");
			return;
		}
	}

	dev_info(mvotg->phy.dev, "gadget %s\n", on ? "on" : "off");

	if (on)
		usb_gadget_vbus_connect(otg->gadget);
	else
		usb_gadget_vbus_disconnect(otg->gadget);
}

static void otg_clock_enable(struct mv_otg *mvotg)
{
	clk_enable(mvotg->clk);
}

static void otg_clock_disable(struct mv_otg *mvotg)
{
	clk_disable(mvotg->clk);
}

static int mv_otg_enable_internal(struct mv_otg *mvotg)
{
	int retval = 0;

	if (mvotg->active)
		return 0;

	dev_dbg(&mvotg->pdev->dev, "otg enabled\n");

	otg_clock_enable(mvotg);
	retval = usb_phy_init(mvotg->outer_phy);
	if (retval) {
		dev_err(&mvotg->pdev->dev,
			"failed to initialize phy %d\n", retval);
		otg_clock_disable(mvotg);
		return retval;
	}

	mvotg->active = 1;

	return 0;

}

static int mv_otg_enable(struct mv_otg *mvotg)
{
	if (mvotg->clock_gating)
		return mv_otg_enable_internal(mvotg);

	return 0;
}

static void mv_otg_disable_internal(struct mv_otg *mvotg)
{
	if (mvotg->active) {
		dev_dbg(&mvotg->pdev->dev, "otg disabled\n");
		usb_phy_shutdown(mvotg->outer_phy);
		otg_clock_disable(mvotg);
		mvotg->active = 0;
	}
}

static void mv_otg_disable(struct mv_otg *mvotg)
{
	if (mvotg->clock_gating)
		mv_otg_disable_internal(mvotg);
}

static void mv_otg_update_inputs(struct mv_otg *mvotg)
{
	struct mv_otg_ctrl *otg_ctrl = &mvotg->otg_ctrl;
	u32 otgsc;

	otgsc = readl(&mvotg->op_regs->otgsc);

	if (mvotg->pdata->extern_attr & MV_USB_HAS_VBUS_DETECTION) {
		unsigned int vbus;
		pxa_usb_extern_call(mvotg->pdata->id, vbus, get_vbus, &vbus);
		if (vbus == VBUS_HIGH) {
			otg_ctrl->b_sess_vld = 1;
			otg_ctrl->b_sess_end = 0;
		} else {
			otg_ctrl->b_sess_vld = 0;
			otg_ctrl->b_sess_end = 1;
		}
	} else {
		otg_ctrl->b_sess_vld = !!(otgsc & OTGSC_STS_B_SESSION_VALID);
		otg_ctrl->b_sess_end = !!(otgsc & OTGSC_STS_B_SESSION_END);
	}

	if (mvotg->pdata->extern_attr & MV_USB_HAS_IDPIN_DETECTION) {
		unsigned int id;
		pxa_usb_extern_call(mvotg->pdata->id, idpin, get_idpin, &id);
		otg_ctrl->id = !!id;
	} else {
		otg_ctrl->id = !!(otgsc & OTGSC_STS_USB_ID);
	}

	if (mvotg->pdata->otg_force_a_bus_req && !otg_ctrl->id)
		otg_ctrl->a_bus_req = 1;

	if (otg_force_host_mode) {
		otg_ctrl->id = 0;
		otg_ctrl->a_bus_req = 1;
	}

	otg_ctrl->a_sess_vld = !!(otgsc & OTGSC_STS_A_SESSION_VALID);
	otg_ctrl->a_vbus_vld = !!(otgsc & OTGSC_STS_A_VBUS_VALID);

	dev_dbg(&mvotg->pdev->dev, "%s: ", __func__);
	dev_dbg(&mvotg->pdev->dev, "id %d\n", otg_ctrl->id);
	dev_dbg(&mvotg->pdev->dev, "b_sess_vld %d\n", otg_ctrl->b_sess_vld);
	dev_dbg(&mvotg->pdev->dev, "b_sess_end %d\n", otg_ctrl->b_sess_end);
	dev_dbg(&mvotg->pdev->dev, "a_vbus_vld %d\n", otg_ctrl->a_vbus_vld);
	dev_dbg(&mvotg->pdev->dev, "a_sess_vld %d\n", otg_ctrl->a_sess_vld);
}

static void mv_otg_update_state(struct mv_otg *mvotg)
{
	struct mv_otg_ctrl *otg_ctrl = &mvotg->otg_ctrl;
	struct usb_phy *phy = &mvotg->phy;
	int old_state = phy->state;

	switch (old_state) {
	case OTG_STATE_UNDEFINED:
		phy->state = OTG_STATE_B_IDLE;
		/* FALL THROUGH */
	case OTG_STATE_B_IDLE:
		if (otg_ctrl->id == 0)
			phy->state = OTG_STATE_A_IDLE;
		else if (otg_ctrl->b_sess_vld)
			phy->state = OTG_STATE_B_PERIPHERAL;
		break;
	case OTG_STATE_B_PERIPHERAL:
		if (!otg_ctrl->b_sess_vld || otg_ctrl->id == 0)
			phy->state = OTG_STATE_B_IDLE;
		break;
	case OTG_STATE_A_IDLE:
		if (otg_ctrl->id)
			phy->state = OTG_STATE_B_IDLE;
		else if (!(otg_ctrl->a_bus_drop) &&
			 (otg_ctrl->a_bus_req || otg_ctrl->a_srp_det))
			phy->state = OTG_STATE_A_WAIT_VRISE;
		break;
	case OTG_STATE_A_WAIT_VRISE:
		if (otg_ctrl->a_vbus_vld)
			phy->state = OTG_STATE_A_WAIT_BCON;
		break;
	case OTG_STATE_A_WAIT_BCON:
		if (otg_ctrl->id || otg_ctrl->a_bus_drop
		    || otg_ctrl->a_wait_bcon_timeout) {
			mv_otg_cancel_timer(mvotg, A_WAIT_BCON_TIMER);
			mvotg->otg_ctrl.a_wait_bcon_timeout = 0;
			phy->state = OTG_STATE_A_WAIT_VFALL;
			otg_ctrl->a_bus_req = 0;
		} else if (!otg_ctrl->a_vbus_vld) {
			mv_otg_cancel_timer(mvotg, A_WAIT_BCON_TIMER);
			mvotg->otg_ctrl.a_wait_bcon_timeout = 0;
			phy->state = OTG_STATE_A_VBUS_ERR;
		} else if (otg_ctrl->b_conn) {
			mv_otg_cancel_timer(mvotg, A_WAIT_BCON_TIMER);
			mvotg->otg_ctrl.a_wait_bcon_timeout = 0;
			phy->state = OTG_STATE_A_HOST;
		}
		break;
	case OTG_STATE_A_HOST:
		if (otg_ctrl->id || !otg_ctrl->b_conn
		    || otg_ctrl->a_bus_drop)
			phy->state = OTG_STATE_A_WAIT_BCON;
		else if (!otg_ctrl->a_vbus_vld)
			phy->state = OTG_STATE_A_VBUS_ERR;
		break;
	case OTG_STATE_A_WAIT_VFALL:
		if (otg_ctrl->id
		    || (!otg_ctrl->b_conn && otg_ctrl->a_sess_vld)
		    || otg_ctrl->a_bus_req)
			phy->state = OTG_STATE_A_IDLE;
		break;
	case OTG_STATE_A_VBUS_ERR:
		if (otg_ctrl->id || otg_ctrl->a_clr_err
		    || otg_ctrl->a_bus_drop) {
			otg_ctrl->a_clr_err = 0;
			phy->state = OTG_STATE_A_WAIT_VFALL;
		}
		break;
	default:
		break;
	}
}

static void mv_otg_work(struct work_struct *work)
{
	struct mv_otg *mvotg;
	struct usb_phy *phy;
	struct usb_otg *otg;
	int old_state;

	mvotg = container_of(to_delayed_work(work), struct mv_otg, work);

run:
	/* work queue is single thread, or we need spin_lock to protect */
	phy = &mvotg->phy;
	otg = phy->otg;
	old_state = phy->state;

	if (!mvotg->active)
		return;

	mv_otg_update_inputs(mvotg);
	mv_otg_update_state(mvotg);

	if (old_state != phy->state) {
		dev_info(&mvotg->pdev->dev, "change from state %s to %s\n",
			 state_string[old_state],
			 state_string[phy->state]);

		switch (phy->state) {
		case OTG_STATE_B_IDLE:
			otg->default_a = 0;
			if (old_state == OTG_STATE_B_PERIPHERAL ||
				old_state == OTG_STATE_UNDEFINED)
				mv_otg_start_periphrals(mvotg, 0);
			mv_otg_reset(mvotg);
			mv_otg_disable(mvotg);
			break;
		case OTG_STATE_B_PERIPHERAL:
			mv_otg_enable(mvotg);
			mv_otg_start_periphrals(mvotg, 1);
			break;
		case OTG_STATE_A_IDLE:
			otg->default_a = 1;
			mv_otg_enable(mvotg);
			if (old_state == OTG_STATE_A_WAIT_VFALL)
				mv_otg_start_host(mvotg, 0);
			mv_otg_reset(mvotg);
			break;
		case OTG_STATE_A_WAIT_VRISE:
			mv_otg_set_vbus(otg, 1);
			break;
		case OTG_STATE_A_WAIT_BCON:
			if (old_state != OTG_STATE_A_HOST)
				mv_otg_start_host(mvotg, 1);
			mv_otg_set_timer(mvotg, A_WAIT_BCON_TIMER,
					 T_A_WAIT_BCON,
					 mv_otg_timer_await_bcon);
			/*
			 * Now, we directly enter A_HOST. So set b_conn = 1
			 * here. In fact, it need host driver to notify us.
			 */
			mvotg->otg_ctrl.b_conn = 1;
			break;
		case OTG_STATE_A_HOST:
			break;
		case OTG_STATE_A_WAIT_VFALL:
			/*
			 * Now, we has exited A_HOST. So set b_conn = 0
			 * here. In fact, it need host driver to notify us.
			 */
			mvotg->otg_ctrl.b_conn = 0;
			mv_otg_set_vbus(otg, 0);
			break;
		case OTG_STATE_A_VBUS_ERR:
			break;
		default:
			break;
		}
		goto run;
	}
}

static irqreturn_t mv_otg_irq(int irq, void *dev)
{
	struct mv_otg *mvotg = dev;
	u32 otgsc;

	/* if otg clock is not enabled, otgsc read out will be 0 */
	if (!mvotg->active)
		mv_otg_enable(mvotg);

	otgsc = readl(&mvotg->op_regs->otgsc);
	writel(otgsc | mvotg->irq_en, &mvotg->op_regs->otgsc);

	if (!(mvotg->pdata->extern_attr & MV_USB_HAS_IDPIN_DETECTION)) {
		mv_otg_usbid_wakeup_clear();
		if (mvotg->otg_ctrl.id != (!!(otgsc & OTGSC_STS_USB_ID))) {
			mv_otg_run_state_machine(mvotg, 0);
			return IRQ_HANDLED;
		}
	}

	/*
	 * if we have vbus, then the vbus detection for B-device
	 * will be done by mv_otg_inputs_irq().
	 */
	if (mvotg->pdata->extern_attr & MV_USB_HAS_VBUS_DETECTION)
		if ((otgsc & OTGSC_STS_USB_ID) &&
		    !(otgsc & OTGSC_INTSTS_USB_ID))
			return IRQ_NONE;

	if ((otgsc & mvotg->irq_status) == 0)
		return IRQ_NONE;

	mv_otg_run_state_machine(mvotg, 0);

	return IRQ_HANDLED;
}

static int mv_otg_notifier_callback(struct notifier_block *nb,
                                unsigned long val, void *v)
{
	struct mv_otg *mvotg = container_of(nb, struct mv_otg, notifier);

	/* The clock may disabled at this time */
	if (!mvotg->active) {
		mv_otg_enable(mvotg);
		mv_otg_init_irq(mvotg);
	}

	mv_otg_run_state_machine(mvotg, 0);

	return 0;
}

static int mv_otg_notifier_charger_callback(struct notifier_block *nb,
					unsigned long val, void *v)
{
	struct mv_otg *mvotg =
		container_of(nb, struct mv_otg, notifier_charger);

	mvotg->charger_type = val;
	if (mvotg->charger_type == DCP_CHARGER) {
		mv_otg_reset(mvotg);
		mv_otg_disable(mvotg);
	}

	return 0;
}

static ssize_t
get_a_bus_req(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct mv_otg *mvotg = dev_get_drvdata(dev);
	return scnprintf(buf, PAGE_SIZE, "%d\n",
			 mvotg->otg_ctrl.a_bus_req);
}

static ssize_t
set_a_bus_req(struct device *dev, struct device_attribute *attr,
	      const char *buf, size_t count)
{
	struct mv_otg *mvotg = dev_get_drvdata(dev);

	if (count > 2)
		return -1;

	/* We will use this interface to change to A device */
	if (mvotg->phy.state != OTG_STATE_B_IDLE
	    && mvotg->phy.state != OTG_STATE_A_IDLE)
		return -1;

	/* The clock may disabled and we need to set irq for ID detected */
	mv_otg_enable(mvotg);
	mv_otg_init_irq(mvotg);

	if (buf[0] == '1') {
		mvotg->otg_ctrl.a_bus_req = 1;
		mvotg->otg_ctrl.a_bus_drop = 0;
		dev_dbg(&mvotg->pdev->dev,
			"User request: a_bus_req = 1\n");

		if (spin_trylock(&mvotg->wq_lock)) {
			mv_otg_run_state_machine(mvotg, 0);
			spin_unlock(&mvotg->wq_lock);
		}
	}

	return count;
}

static DEVICE_ATTR(a_bus_req, S_IRUGO | S_IWUSR, get_a_bus_req,
		   set_a_bus_req);

static ssize_t
set_a_clr_err(struct device *dev, struct device_attribute *attr,
	      const char *buf, size_t count)
{
	struct mv_otg *mvotg = dev_get_drvdata(dev);
	if (!mvotg->phy.otg->default_a)
		return -1;

	if (count > 2)
		return -1;

	if (buf[0] == '1') {
		mvotg->otg_ctrl.a_clr_err = 1;
		dev_dbg(&mvotg->pdev->dev,
			"User request: a_clr_err = 1\n");
	}

	if (spin_trylock(&mvotg->wq_lock)) {
		mv_otg_run_state_machine(mvotg, 0);
		spin_unlock(&mvotg->wq_lock);
	}

	return count;
}

static DEVICE_ATTR(a_clr_err, S_IWUSR, NULL, set_a_clr_err);

static ssize_t
get_a_bus_drop(struct device *dev, struct device_attribute *attr,
	       char *buf)
{
	struct mv_otg *mvotg = dev_get_drvdata(dev);
	return scnprintf(buf, PAGE_SIZE, "%d\n",
			 mvotg->otg_ctrl.a_bus_drop);
}

static ssize_t
set_a_bus_drop(struct device *dev, struct device_attribute *attr,
	       const char *buf, size_t count)
{
	struct mv_otg *mvotg = dev_get_drvdata(dev);
	if (!mvotg->phy.otg->default_a)
		return -1;

	if (count > 2)
		return -1;

	if (buf[0] == '0') {
		mvotg->otg_ctrl.a_bus_drop = 0;
		dev_dbg(&mvotg->pdev->dev,
			"User request: a_bus_drop = 0\n");
	} else if (buf[0] == '1') {
		mvotg->otg_ctrl.a_bus_drop = 1;
		mvotg->otg_ctrl.a_bus_req = 0;
		dev_dbg(&mvotg->pdev->dev,
			"User request: a_bus_drop = 1\n");
		dev_dbg(&mvotg->pdev->dev,
			"User request: and a_bus_req = 0\n");
	}

	if (spin_trylock(&mvotg->wq_lock)) {
		mv_otg_run_state_machine(mvotg, 0);
		spin_unlock(&mvotg->wq_lock);
	}

	return count;
}

static DEVICE_ATTR(a_bus_drop, S_IRUGO | S_IWUSR,
		   get_a_bus_drop, set_a_bus_drop);

static ssize_t
get_otg_mode(struct device *dev, struct device_attribute *attr, char *buf)
{
	char *state = otg_force_host_mode ? "host" : "client";
	return sprintf(buf, "OTG mode: %s\n", state);
}

static ssize_t
set_otg_mode(struct device *dev, struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct mv_otg *mvotg = dev_get_drvdata(dev);
	char *usage = "Usage: $echo host/client to switch otg mode";
	char buff[16], *b;

	strncpy(buff, buf, sizeof(buff));
	b = strim(buff);
	pr_info("OTG state is %s\n", state_string[mvotg->phy.state]);
	if (!strcmp(b, "host")) {
		if (mvotg->phy.state == OTG_STATE_B_PERIPHERAL) {
			pr_err("Failed to swich mode, pls don't connect to PC!\n");
			return count;
		}
		otg_force_host_mode = 1;
	} else if (!strcmp(b, "client")) {
		otg_force_host_mode = 0;
	} else {
		pr_err("%s\n", usage);
		return count;
	}
	mv_otg_run_state_machine(mvotg, 0);

	return count;
}
static DEVICE_ATTR(otg_mode, S_IRUGO | S_IWUSR, get_otg_mode, set_otg_mode);

static struct attribute *inputs_attrs[] = {
	&dev_attr_a_bus_req.attr,
	&dev_attr_a_clr_err.attr,
	&dev_attr_a_bus_drop.attr,
	&dev_attr_otg_mode.attr,
	NULL,
};

static struct attribute_group inputs_attr_group = {
	.name = "inputs",
	.attrs = inputs_attrs,
};

int mv_otg_remove(struct platform_device *pdev)
{
	struct mv_otg *mvotg = platform_get_drvdata(pdev);

	device_init_wakeup(&pdev->dev, 0);

	sysfs_remove_group(&mvotg->pdev->dev.kobj, &inputs_attr_group);

	if (mvotg->qwork) {
		flush_workqueue(mvotg->qwork);
		destroy_workqueue(mvotg->qwork);
	}

	if (mvotg->pdata->extern_attr
		& (MV_USB_HAS_VBUS_DETECTION | MV_USB_HAS_IDPIN_DETECTION))
		pxa_usb_unregister_notifier(mvotg->pdata->id, &mvotg->notifier);

	mv_otg_disable(mvotg);

	clk_unprepare(mvotg->clk);

	pm_qos_remove_request(&mvotg->qos_idle);

	usb_remove_phy(&mvotg->phy);

	return 0;
}

static void mv_otg_phy_bind_device(struct mv_otg *mvotg)
{
	const char *device_name;
	struct device_node *np = (mvotg->phy.dev)->of_node;

	if (!of_property_read_string(np, "marvell,udc-name", &device_name))
		usb_bind_phy(device_name, MV_USB2_OTG_PHY_INDEX,
						dev_name(mvotg->phy.dev));

	if (!of_property_read_string(np, "marvell,ehci-name", &device_name))
		usb_bind_phy(device_name, MV_USB2_OTG_PHY_INDEX,
						dev_name(mvotg->phy.dev));
}

static int mv_otg_probe(struct platform_device *pdev)
{
	struct mv_usb_platform_data *pdata = pdev->dev.platform_data;
	struct mv_otg *mvotg;
	struct usb_otg *otg;
	struct resource *r;
	int retval = 0, i;
	struct device_node *np = pdev->dev.of_node;
	const __be32 *prop;
	unsigned int proplen;

	if (get_usb_ownship_from_cmdline()) {
		dev_info(&pdev->dev, "TDM has occupied usb already!\n");
		return -EPERM;
	}

	if (pdata == NULL) {
		dev_err(&pdev->dev, "failed to get platform data\n");
		return -ENODEV;
	}

	mvotg = devm_kzalloc(&pdev->dev, sizeof(*mvotg), GFP_KERNEL);
	if (!mvotg) {
		dev_err(&pdev->dev, "failed to allocate memory!\n");
		return -ENOMEM;
	}

	otg = devm_kzalloc(&pdev->dev, sizeof(*otg), GFP_KERNEL);
	if (!otg)
		return -ENOMEM;

	platform_set_drvdata(pdev, mvotg);

	mvotg->pdev = pdev;
	mvotg->pdata = pdata;

	mvotg->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(mvotg->clk))
		return PTR_ERR(mvotg->clk);
	clk_prepare(mvotg->clk);

	mvotg->qwork = create_singlethread_workqueue("mv_otg_queue");
	if (!mvotg->qwork) {
		dev_dbg(&pdev->dev, "cannot create workqueue for OTG\n");
		return -ENOMEM;
	}

	INIT_DELAYED_WORK(&mvotg->work, mv_otg_work);

	/* OTG common part */
	mvotg->pdev = pdev;
	mvotg->phy.dev = &pdev->dev;
	mvotg->phy.type = USB_PHY_TYPE_USB2;
	mvotg->phy.otg = otg;
	mvotg->phy.label = driver_name;
	mvotg->phy.state = OTG_STATE_UNDEFINED;

	otg->phy = &mvotg->phy;
	otg->set_host = mv_otg_set_host;
	otg->set_peripheral = mv_otg_set_peripheral;
	otg->set_vbus = mv_otg_set_vbus;

	mv_otg_phy_bind_device(mvotg);

	for (i = 0; i < OTG_TIMER_NUM; i++)
		init_timer(&mvotg->otg_ctrl.timer[i]);

	r = platform_get_resource(mvotg->pdev,
					 IORESOURCE_MEM, 0);
	if (r == NULL) {
		dev_err(&pdev->dev, "no I/O memory resource defined\n");
		retval = -ENODEV;
		goto err_destroy_workqueue;
	}

	mvotg->cap_regs = devm_ioremap(&pdev->dev, r->start, resource_size(r));
	if (mvotg->cap_regs == NULL) {
		dev_err(&pdev->dev, "failed to map I/O memory\n");
		retval = -EFAULT;
		goto err_destroy_workqueue;
	}

	mvotg->outer_phy = devm_usb_get_phy_dev(&pdev->dev, MV_USB2_PHY_INDEX);
	if (IS_ERR_OR_NULL(mvotg->outer_phy)) {
		retval = PTR_ERR(mvotg->outer_phy);
		if (retval != -EPROBE_DEFER)
			dev_err(&pdev->dev, "can not find outer phy\n");
		goto err_destroy_workqueue;
	}

	/* we will acces controller register, so enable the udc controller */
	retval = mv_otg_enable_internal(mvotg);
	if (retval) {
		dev_err(&pdev->dev, "mv otg enable error %d\n", retval);
		goto err_destroy_workqueue;
	}

	mvotg->op_regs =
		(struct mv_otg_regs __iomem *) ((unsigned long) mvotg->cap_regs
			+ (readl(mvotg->cap_regs) & CAPLENGTH_MASK));

	if (pdata->extern_attr
		& (MV_USB_HAS_VBUS_DETECTION | MV_USB_HAS_IDPIN_DETECTION)) {
		mvotg->notifier.notifier_call = mv_otg_notifier_callback;
		pxa_usb_register_notifier(mvotg->pdata->id, &mvotg->notifier);
		if (pdata->extern_attr & MV_USB_HAS_VBUS_DETECTION) {
			mvotg->clock_gating = 1;
			pxa_usb_extern_call(mvotg->pdata->id, vbus, init);
		}
		if (pdata->extern_attr & MV_USB_HAS_IDPIN_DETECTION)
			pxa_usb_extern_call(mvotg->pdata->id, idpin, init);
	}

	mvotg->notifier_charger.notifier_call =
		mv_otg_notifier_charger_callback;
	mv_udc_register_client(&mvotg->notifier_charger);

	if (pdata->disable_otg_clock_gating)
		mvotg->clock_gating = 0;

	mv_otg_reset(mvotg);
	mv_otg_init_irq(mvotg);

	r = platform_get_resource(mvotg->pdev, IORESOURCE_IRQ, 0);
	if (r == NULL) {
		dev_err(&pdev->dev, "no IRQ resource defined\n");
		retval = -ENODEV;
		goto err_disable_clk;
	}

	mvotg->irq = r->start;
	if (devm_request_irq(&pdev->dev, mvotg->irq, mv_otg_irq, IRQF_SHARED,
			driver_name, mvotg)) {
		dev_err(&pdev->dev, "Request irq %d for OTG failed\n",
			mvotg->irq);
		mvotg->irq = 0;
		retval = -ENODEV;
		goto err_disable_clk;
	}

	retval = usb_add_phy_dev(&mvotg->phy);
	if (retval < 0) {
		dev_err(&pdev->dev, "can't register transceiver, %d\n",
			retval);
		goto err_disable_clk;
	}

	prop = of_get_property(np, "lpm-qos", &proplen);
	if (!prop) {
		pr_err("lpm-qos config in DT for mv_otg is not defined\n");
		goto err_disable_clk;
	} else
		mvotg->lpm_qos = be32_to_cpup(prop);

	mvotg->qos_idle.name = mvotg->pdev->name;
	pm_qos_add_request(&mvotg->qos_idle, PM_QOS_CPUIDLE_BLOCK,
			PM_QOS_CPUIDLE_BLOCK_DEFAULT_VALUE);

	retval = sysfs_create_group(&pdev->dev.kobj, &inputs_attr_group);
	if (retval < 0) {
		dev_dbg(&pdev->dev,
			"Can't register sysfs attr group: %d\n", retval);
		goto err_remove_otg_phy;
	}

	spin_lock_init(&mvotg->wq_lock);
	if (spin_trylock(&mvotg->wq_lock)) {
		mv_otg_run_state_machine(mvotg, 2 * HZ);
		spin_unlock(&mvotg->wq_lock);
	}

	dev_info(&pdev->dev,
		 "successful probe OTG device %s clock gating.\n",
		 mvotg->clock_gating ? "with" : "without");

	device_init_wakeup(&pdev->dev, 1);
	if (!(pdata->extern_attr & MV_USB_HAS_IDPIN_DETECTION)) {
		enable_irq_wake(mvotg->irq);
		mv_otg_usbid_wakeup_en(1);
	}

	return 0;

err_remove_otg_phy:
	usb_remove_phy(&mvotg->phy);
	pm_qos_remove_request(&mvotg->qos_idle);
err_disable_clk:
	mv_otg_disable_internal(mvotg);
	if (pdata->extern_attr
		& (MV_USB_HAS_VBUS_DETECTION | MV_USB_HAS_IDPIN_DETECTION))
		pxa_usb_unregister_notifier(mvotg->pdata->id, &mvotg->notifier);
err_destroy_workqueue:
	flush_workqueue(mvotg->qwork);
	destroy_workqueue(mvotg->qwork);

	return retval;
}

#ifdef CONFIG_PM
static int mv_otg_suspend(struct platform_device *pdev, pm_message_t state)
{
	struct mv_otg *mvotg = platform_get_drvdata(pdev);

	if (!mvotg->clock_gating)
		mv_otg_disable_internal(mvotg);

	mvotg->phy.state = OTG_STATE_UNDEFINED;

	return 0;
}

static int mv_otg_resume(struct platform_device *pdev)
{
	struct mv_otg *mvotg = platform_get_drvdata(pdev);
	u32 otgsc;
	static unsigned int charger_type;

	if (mvotg->pdata->charger_detect) {
		mvotg->charger_type = mvotg->pdata->charger_detect();
	}
	else {
		if ((mvotg->charger_type == DCP_CHARGER) ||
			(charger_type == mvotg->charger_type))
			return 0;
	}

	mv_otg_enable_internal(mvotg);

	otgsc = readl(&mvotg->op_regs->otgsc);
	otgsc |= mvotg->irq_en;
	writel(otgsc, &mvotg->op_regs->otgsc);

	if (spin_trylock(&mvotg->wq_lock)) {
		mv_otg_run_state_machine(mvotg, 0);
		spin_unlock(&mvotg->wq_lock);
	}

	charger_type = mvotg->charger_type;

	return 0;
}
#endif

static const struct of_device_id mv_otg_dt_match[] = {
	{ .compatible = "marvell,mv-otg" },
	{},
};
MODULE_DEVICE_TABLE(of, mv_udc_dt_match);

static struct platform_driver mv_otg_driver = {
	.probe = mv_otg_probe,
	.remove = __exit_p(mv_otg_remove),
	.driver = {
		   .owner = THIS_MODULE,
		   .of_match_table = of_match_ptr(mv_otg_dt_match),
		   .name = driver_name,
		   },
#ifdef CONFIG_PM
	.suspend = mv_otg_suspend,
	.resume = mv_otg_resume,
#endif
};
module_platform_driver(mv_otg_driver);
