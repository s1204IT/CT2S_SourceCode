/*
 * Based on arch/arm/include/asm/arch-armada100/mfp.h
 * (C) Copyright 2012
 * Marvell Semiconductor <www.marvell.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __PXA1908_MFP_H
#define __PXA1908_MFP_H

/*
 * Frequently used MFP Configuration macros for all PXA1908 family of SoCs
 *
 * offset, pull,pF, drv,dF, edge,eF ,afn,aF
 */

#define GPIO000_KP_MKIN0	(MFP_REG(0x0dc) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO001_KP_MKOUT0	(MFP_REG(0x0e0) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO002_KP_MKIN1	(MFP_REG(0x0e4) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO003_KP_MKOUT1	(MFP_REG(0x0e8) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO004_KP_MKIN2	(MFP_REG(0x0ec) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO005_KP_MKOUT2	(MFP_REG(0x0f0) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO006_KP_MKIN3	(MFP_REG(0x0f4) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO007_GPIO_7		(MFP_REG(0x0f8) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO008_GPIO_8		(MFP_REG(0x0fc) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO009_GPIO_9		(MFP_REG(0x100) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO010_GPIO_10		(MFP_REG(0x104) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO011_GPIO_11		(MFP_REG(0x108) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO012_GPIO_12		(MFP_REG(0x10c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO013_GPIO_13		(MFP_REG(0x110) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO014_GPIO_14		(MFP_REG(0x114) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO015_GPIO_15		(MFP_REG(0x118) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO016_GPIO_16		(MFP_REG(0x11c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO016_KP_DKIN1	(MFP_REG(0x11c) | MFP_AF1 | MFP_DRIVE_MEDIUM |\
				MFP_PULL_HIGH)
#define GPIO017_GPIO_17		(MFP_REG(0x120) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO017_KP_DKIN2	(MFP_REG(0x120) | MFP_AF1 | MFP_DRIVE_MEDIUM |\
				MFP_PULL_HIGH)
#define GPIO018_GPIO_18		(MFP_REG(0x124) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO019_GPIO_19		(MFP_REG(0x128) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO020_GPIO_20		(MFP_REG(0x12c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO021_I2S_BITCLK	(MFP_REG(0x130) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO022_I2S_SYNC	(MFP_REG(0x134) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO023_I2S_DATA_OUT	(MFP_REG(0x138) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO024_I2S_SDATA_IN	(MFP_REG(0x13c) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO025_GSSP_SCLK	(MFP_REG(0x140) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO026_GSSP_SFRM	(MFP_REG(0x144) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO027_GSSP_TXD	(MFP_REG(0x148) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO028_GSSP_RXD	(MFP_REG(0x14c) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO029_GPIO_29		(MFP_REG(0x150) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO030_GPIO_30		(MFP_REG(0x154) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO031_GPIO_31		(MFP_REG(0x158) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO032_GPIO_32		(MFP_REG(0x15c) | MFP_AF0 | MFP_DRIVE_MEDIUM \
				| MFP_PULL_HIGH)
#define GPIO033_SPI_DCLK	(MFP_REG(0x160) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO034_SPI_CS0		(MFP_REG(0x164) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO035_SPI_DIN		(MFP_REG(0x168) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO036_SPI_DOUT	(MFP_REG(0x16c) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO037_MMC2_DATA3	(MFP_REG(0x170) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO038_MMC2_DATA2	(MFP_REG(0x174) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO039_MMC2_DATA1	(MFP_REG(0x178) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO040_MMC2_DATA0	(MFP_REG(0x17c) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO041_MMC2_CMD	(MFP_REG(0x180) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO042_MMC2_CLK	(MFP_REG(0x184) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO043_GPIO_43		(MFP_REG(0x188) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO044_GPIO_44		(MFP_REG(0x18c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO045_UART2_RXD	(MFP_REG(0x190) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO046_UART2_TXD	(MFP_REG(0x194) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO047_UART1_RXD	(MFP_REG(0x198) | MFP_AF6 | MFP_DRIVE_MEDIUM)
#define GPIO048_UART1_TXD	(MFP_REG(0x19c) | MFP_AF6 | MFP_DRIVE_MEDIUM)
#define GPIO049_GPIO_49		(MFP_REG(0x1a0) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO050_GPIO_50		(MFP_REG(0x1a4) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO051_GPIO_51		(MFP_REG(0x1a8) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO051_UART0_RXD	(MFP_REG(0x1a8) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO052_UART0_TXD	(MFP_REG(0x1ac) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO053_CI2C_SCL	(MFP_REG(0x1b0) | MFP_AF2 | MFP_DRIVE_MEDIUM)
#define GPIO054_CI2C_SDA	(MFP_REG(0x1b4) | MFP_AF2 | MFP_DRIVE_MEDIUM)

#define GPIO051_OVT_SCL1	(MFP_REG(0x1a8) | MFP_AF7 | MFP_DRIVE_MEDIUM)
#define GPIO052_OVT_SDA1	(MFP_REG(0x1ac) | MFP_AF7 | MFP_DRIVE_MEDIUM)
#define GPIO053_OVT_SCL0	(MFP_REG(0x1b0) | MFP_AF7 | MFP_DRIVE_MEDIUM)
#define GPIO054_OVT_SDA0	(MFP_REG(0x1b4) | MFP_AF7 | MFP_DRIVE_MEDIUM)

#define GPIO067_CCIC_IN7	(MFP_REG(0x1b8) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO068_CCIC_IN6	(MFP_REG(0x1bc) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO069_CCIC_IN5	(MFP_REG(0x1c0) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO070_CCIC_IN4	(MFP_REG(0x1c4) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO071_CCIC_IN3	(MFP_REG(0x1c8) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO072_CCIC_IN2	(MFP_REG(0x1cc) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO073_CCIC_IN1	(MFP_REG(0x1d0) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO074_CCIC_IN0	(MFP_REG(0x1d4) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO073_GPS_I2C_SCL	(MFP_REG(0x1d0) | MFP_AF7 | MFP_DRIVE_MEDIUM)
#define GPIO074_GPS_I2C_SDA	(MFP_REG(0x1d4) | MFP_AF7 | MFP_DRIVE_MEDIUM)
#define GPIO073_CI2C_SCL_3	(MFP_REG(0x1d0) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO074_CI2C_SDA_3	(MFP_REG(0x1d4) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO075_CAM_HSYNC	(MFP_REG(0x1d8) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO076_CAM_VSYNC	(MFP_REG(0x1dc) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO077_CAM_MCLK	(MFP_REG(0x1e0) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO078_CAM_PCLK	(MFP_REG(0x1e4) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO079_GPIO_79		(MFP_REG(0x1e8) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO080_GPIO_80		(MFP_REG(0x1ec) | MFP_AF0 | MFP_DRIVE_MEDIUM)

#define GPIO079_CI2C_SCL	(MFP_REG(0x1e8) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define GPIO080_CI2C_SDA	(MFP_REG(0x1ec) | MFP_AF1 | MFP_DRIVE_MEDIUM)

#define GPIO081_GPIO_81		(MFP_REG(0x1f0) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO082_GPIO_82		(MFP_REG(0x1f4) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO083_GPIO_83		(MFP_REG(0x1f8) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO084_GPIO_84		(MFP_REG(0x1fc) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO085_GPIO_85		(MFP_REG(0x200) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO086_GPIO_86		(MFP_REG(0x204) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO087_CI2C_SCL_2	(MFP_REG(0x208) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO088_CI2C_SDA_2	(MFP_REG(0x20c) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO089_GPS_CLK		(MFP_REG(0x210) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO090_CMMB_CLK	(MFP_REG(0x214) | MFP_AF5 | MFP_DRIVE_MEDIUM)
#define GPIO091_GPIO_91		(MFP_REG(0x218) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO092_GPIO_92		(MFP_REG(0x21c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO093_GPIO_93		(MFP_REG(0x220) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO094_GPIO_94		(MFP_REG(0x224) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO095_GPIO_95		(MFP_REG(0x228) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO096_GPIO_96		(MFP_REG(0x22c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO097_GPIO_97		(MFP_REG(0x230) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO098_GPIO_98		(MFP_REG(0x234) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define GPIO124_GPIO_124	(MFP_REG(0x0d0) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_DAT7_MMC1_DAT7	(MFP_REG(0x084) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_DAT6_MMC1_DAT6	(MFP_REG(0x088) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_DAT5_MMC1_DAT5	(MFP_REG(0x08c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_DAT4_MMC1_DAT4	(MFP_REG(0x090) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_DAT3_MMC1_DAT3	(MFP_REG(0x094) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_DAT2_MMC1_DAT2	(MFP_REG(0x098) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_DAT1_MMC1_DAT1	(MFP_REG(0x09c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_DAT0_MMC1_DAT0	(MFP_REG(0x0a0) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_CMD_MMC1_CMD	(MFP_REG(0x0a4) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_CLK_MMC1_CLK	(MFP_REG(0x0a8) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_CD_MMC1_CD		(MFP_REG(0x0ac) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define MMC1_WP_MMC1_WP		(MFP_REG(0x0b0) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define ND_IO8_GPIO100		(MFP_REG(0x020) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_IO7_MMC3_DAT7	(MFP_REG(0x024) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_IO6_MMC3_DAT6	(MFP_REG(0x028) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_IO5_MMC3_DAT5	(MFP_REG(0x02c) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_IO4_MMC3_DAT4	(MFP_REG(0x030) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_IO3_MMC3_DAT3	(MFP_REG(0x034) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_IO2_MMC3_DAT2	(MFP_REG(0x038) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_IO1_MMC3_DAT1	(MFP_REG(0x03c) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_IO0_MMC3_DAT0	(MFP_REG(0x040) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_CLE_SM_OEN_MMC3_CMD	(MFP_REG(0x05c) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define SM_SCLK_MMC3_CLK	(MFP_REG(0x064) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_RDY0_GPIO_108	(MFP_REG(0x068) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define VCXO_OUT_PWM_4		(MFP_REG(0x0d8) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ANT_SW4_GPIO_28		(MFP_REG(0x26c) | MFP_AF6 | MFP_DRIVE_MEDIUM)
#define SM_ADV_GPIO_0		(MFP_REG(0x074) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_RDY1_GPIO_1		(MFP_REG(0x078) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define SM_ADVMUX_GPIO_2	(MFP_REG(0x07c) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define SM_BEN0_GPIO_126	(MFP_REG(0x06c) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define SM_BEN1_GPIO_127	(MFP_REG(0x070) | MFP_AF0 | MFP_DRIVE_MEDIUM)
#define SM_CSN0_GPIO_103	(MFP_REG(0x04c) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define SM_CSN1_GPIO_104	(MFP_REG(0x050) | MFP_AF1 | MFP_DRIVE_MEDIUM)
#define ND_CS1N3_GPIO_102	(MFP_REG(0x048) | MFP_AF1 | MFP_DRIVE_MEDIUM)

#define GPIO004_GPIO_4		(MFP_REG(0x0ec) | MFP_AF0 | MFP_DRIVE_MEDIUM)

#endif /* __PXA1908_MFP_H */
