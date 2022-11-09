/*
 * (C) Copyright 2013
 * Marvell Semiconductors Ltd. <www.marvell.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>

#define cpu_relax() barrier()

uint32_t sg_d2_b0_ops[] = {
	0xea000006,
	0xeafffffe,
	0xeafffffe,
	0xeafffffe,
	0xeafffffe,
	0xeafffffe,
	0xeafffffe,
	0xeafffffe,
	0xe3a0520d,
	0xe3855825,
	0xe3851024,
	0xe3a02103,
	0xe3822903,
	0xe3822001,
	0xe5812000,
	0xe3851030,
	0xe5912000,
	0xe3822060,
	0xe5812000,
	0xe3851028,
	0xe5912000,
	0xe3c22001,
	0xe38550c4,
	0xe5950000,
	0xe3c00901,
	0xe3800501,
	0xe5850000,
	0xe3a0520d,
	0xe3855827,
	0xe3a004d3,
	0xe5850000,
	0xe3a05335,
	0xe3855805,
	0xe3850020,
	0xe3a01000,
	0xe5801000,
	0xe3a0520d,
	0xe3855825,
	0xe38500c0,
	0xe3a01000,
	0xe5801000,
	0xe38500a0,
	0xe3a0100f,
	0xe5801000,
	0xe38550c4,
	0xe3a004ff,
	0xe3800aa7,
	0xe5850000,
	0xe3a054d1,
	0xe3850801,
	0xe3800028,
	0xe3a01001,
	0xe5801000,
	0xee074f90,
	0xe1a00000,
	0xeafffffd
};



uint32_t sg_d2_a0_ops[] = {
	0xe3a0520d,
	0xe3855825,
	0xe3851024,
	0xe3a02103,
	0xe3822903,
	0xe3822001,
	0xe5812000,
	0xe3851030,
	0xe5912000,
	0xe3822060,
	0xe5812000,
	0xe3851028,
	0xe5912000,
	0xe3c22001,
	0xe3a05335,
	0xe3855805,
	0xe5950000,
	0xe3c00901,
	0xe3800501,
	0xe5850000,
	0xe3850a01,
	0xe3800088,
	0xe3a01083,
	0xe5801000,
	0xe3a0620d,
	0xe3866827,
	0xe3a004d3,
	0xe5860000,
	0xe3850020,
	0xe3a01000,
	0xe5801000,
	0xe3850020,
	0xe3800a01,
	0xe5901000,
	0xe3c11004,
	0xe5801000,
	0xe3a004fe,
	0xe3800712,
	0xe3800a06,
	0xe5850000,
	0xe3851a01,
	0xe5810000,
	0xe3a054d1,
	0xe3850801,
	0xe3800028,
	0xe3a01001,
	0xe5801000,
	0xee074f90,
	0xe1a00000,
	0xeafffffd
};

uint32_t msa_d2_ops[] = {
	0x6b6be140,
	0x0000e100,
	0xd101e148,
	0x0010e108,
	0xe1099300,
	0xe1499ffc,
	0x3271d1e0,
	0xe19c327e,
	0xe19d0000,
	0xe19e0000,
	0xe19f0000,
	0xe10a0000,
	0xe14a0000,
	0x9111d027,
	0xe1026002,
	0x504a03e8,
	0x00643221,
	0x00000000,
	0x00000000,
	0x00000000,
	0x20000000,
	0x0035e800,
	0x0004e100,
	0x34094281,
	0xffe0e151,
	0xba709d08,
	0xe141b870,
	0x3401d101,
	0xe10a9f00,
	0xe14a1004,
	0x9110ffe0,
	0xb941bb40,
	0x0008e100,
	0xe1404280,
	0x3208d101,
	0x60089309,
	0x00249f08,
	0x00249310,
	0x0000e100,
	0xe1404280,
	0x3200d101,
	0x93016001,
	0x91002001,
	0xb920bb20,
	0x1c020e18,
	0x91002063,
	0xb910bb10,
	0x4a104f80,
	0x1300e112,
	0xffe0e152,
	0x91009f10,
	0xb900bb00,
	0x4f804a50,
	0x9f104a10,
	0xba909100,
	0x4a58b890,
	0x4a104f80,
	0x91009f10,
	0xb880ba80,
	0x4a584a50,
	0x4a104f80,
	0x91009f10,
	0xb8d0bad0,
	0x4a004f80,
	0x9f104a10,
	0xbac09100,
	0x4a50b8c0,
	0x4a004f80,
	0x9f104a10,
	0xbab09100,
	0x4a58b8b0,
	0x4a004f80,
	0x9f104a10,
	0xbaa09100,
	0x4a50b8a0,
	0x4f804a58,
	0x4a104a00,
	0x91009f10,
	0xb932bb30,
	0xe1804f82,
	0x56824005,
	0x91029f12,
	0xb8e2bae2,
	0x4f824a52,
	0x9f125682,
	0xbaf29102,
	0x4a5ab8f2,
	0x56824f82,
	0x91029f12,
	0xb9b2bbb2,
	0x4a5a4a52,
	0x56024f82,
	0x91009f10,
	0x93006408,
	0x93012f99,
	0x91002001,
	0xb9e0bbe0,
	0x1c020e18,
	0x91002067,
	0xb9d0bbd0,
	0x4a104f80,
	0x0300e112,
	0xffe0e152,
	0x91009f10,
	0xb9c0bbc0,
	0x4f804a50,
	0x9f104a10,
	0xbb609100,
	0x4a58b960,
	0x4a104f80,
	0x91009f10,
	0xb950bb50,
	0x4a584a50,
	0x4a104f80,
	0x91009f10,
	0xb990bb90,
	0x4a004f80,
	0x9f104a10,
	0xbb809100,
	0x4a50b980,
	0x4a004f80,
	0x9f104a10,
	0xbb709100,
	0x4a58b970,
	0x4a004f80,
	0x9f104a10,
	0xbba09100,
	0x4a50b9a0,
	0x4f804a58,
	0x4a104a00,
	0x91009f10,
	0xb812ba10,
	0xe1804f82,
	0x56824005,
	0x91029f12,
	0xffdae63a,
	0xffdae43a,
	0x4f824a52,
	0x9f125682,
	0xba629102,
	0x4a5ab862,
	0x56824f82,
	0x91029f12,
	0xffd8e63a,
	0xffd8e43a,
	0x4a5a4a52,
	0x56024f82,
	0x91009f10,
	0x93006408,
	0x93012f95,
	0x91002001,
	0xffd7e638,
	0xffd7e438,
	0x1c020e38,
	0x9100201d,
	0xffd6e638,
	0xffd6e438,
	0x4a004f68,
	0x1300e112,
	0xffe0e152,
	0x91009f10,
	0xffcfe638,
	0xffcfe438,
	0x4a004f68,
	0x0300e112,
	0xffe0e152,
	0x91009f10,
	0x93006408,
	0x93012fdd,
	0x91002001,
	0xffcee638,
	0xffcee438,
	0x1c020e18,
	0x9100208b,
	0xffd3e638,
	0xffd3e438,
	0x4a104f80,
	0x1300e112,
	0xffe0e152,
	0x91009f10,
	0xffd2e638,
	0xffd2e438,
	0x4f804a50,
	0x9f104a10,
	0xe6389100,
	0xe438ffd1,
	0x4a58ffd1,
	0x4a104f80,
	0x91009f10,
	0xffd0e638,
	0xffd0e438,
	0x4a584a50,
	0x4a104f80,
	0x91009f10,
	0xffd9e638,
	0xffd9e438,
	0x9f104f80,
	0xe6389100,
	0xe438ffd4,
	0x4a50ffd4,
	0x9f104f80,
	0xe6389100,
	0xe438ffd5,
	0x4a58ffd5,
	0x9f104f80,
	0xba209100,
	0x4a50b820,
	0x4f804a58,
	0x91009f10,
	0xb850ba50,
	0x4a104f80,
	0x0300e112,
	0xffe0e152,
	0x91009f10,
	0xb840ba40,
	0x4f804a50,
	0x9f104a10,
	0xba309100,
	0x4a58b830,
	0x4a104f80,
	0x91009f10,
	0xffdce638,
	0xffdce438,
	0x4a584a50,
	0x4a104f80,
	0x91009f10,
	0xffdbe638,
	0xffdbe438,
	0x9f104f80,
	0xba009100,
	0x4a50b800,
	0x9f104f80,
	0xe6389100,
	0xe438ffdf,
	0x4a58ffdf,
	0x9f104f80,
	0xe6389100,
	0xe438ffde,
	0x4a50ffde,
	0x4f804a58,
	0x91009f10,
	0x93006408,
	0x9d002f6f,
	0xffdde638,
	0xffdde438,
	0x00249f08,
	0xbbf09108,
	0x9310b9f0,
	0xe8010024,
	0x00100000,
	0xe80005f4,
	0xe10c0006,
	0xe14c200c,
	0xe100ffa8,
	0x42860000,
	0xd408e146,
	0x00249326,
	0x0034e100,
	0xe1404280,
	0x3200d025,
	0xc60463e0,
	0x4289c201,
	0x83efe141,
	0x00249301,
	0x0128e108,
	0xf00ee148,
	0xbbd19101,
	0x4cf9b9d1,
	0x00249301,
	0x0100e108,
	0xf00ee148,
	0xbbe19101,
	0x4280b9e1,
	0xfe3fe140,
	0x4a005401,
	0x00249300,
	0xe1082001,
	0xe1480118,
	0x9100f00e,
	0xb9f1bbf0,
	0x00e0e180,
	0x0c005401,
	0x20021402,
	0xe10d2ff3,
	0xe14d2000,
	0xe107ffa8,
	0xe1474000,
	0x932ffe08,
	0xe3ff0024,
	0x0024fde9,
	0x5050e108,
	0xffd0e148,
	0x93006008,
	0xe1000024,
	0x42800010,
	0xd101e140,
	0xe1003200,
	0xe140beef,
	0x9300dead,
	0x4ae06000,
	0x932f9320,
	0x00200024,
	0x00000024,
	0x00000000,
	0x00000000,
	0x93260000,
	0x20000024
};

void release_seagull(void)
{
#if 0
	uint32_t dummy_read_apb = 0;
#endif
//	uint32_t timeout = 0;

	if (((*(uint32_t *)0xd4050004) & 0xf) == 0xb) {
		printf("Seagull/MSA is in D2 state already\n");
		return;
	}

#if 0
	*(uint32_t *)(0xD4050000) &= ~(1 << 14); /*CPCR*/
	dummy_read_apb = *(uint32_t *)(0xD4050000);
	*(uint32_t *)(0xD405000c) = 0x001F0500; /*POCR*/
	dummy_read_apb = *(uint32_t *)(0xD405000c);
	*(uint32_t *)(0xD4050038) = 0x00000005; /*SCCR*/
	dummy_read_apb = *(uint32_t *)(0xD4050038);
#endif

	if (!cpu_is_pxa1928_a0())
		*(uint32_t *)0xd4051088 = 0x00000083;

	/* SW REMAP FOR CP CORE */
	*(uint32_t *)0xd4051084 = 0x00010600; /*mapp to 0x06000000*/
	/* Seagull clocks */
	*(uint32_t *)0xd4050000 |= (0x3 << 25);
	*(uint32_t *)0xd4051000 |= (0x3 << 25);
	*(uint32_t *)0xd4282c64 = 0x00000000;
	*(uint32_t *)0xd4282c68 = 0x00000000;
	*(uint32_t *)0xd4050020 &= ~(0x00000008);/*Fabric reset*/
	*(uint32_t *)0xd4282a44 &= ~(0x00800000); /*Fab 11 div1*/
	/* Seagull reset */
	*(uint32_t *)0xd4051020 &= ~(0x00000080); /*Seagull reset*/

//	timeout = 100;
	while (((*(volatile uint32_t *)0xd4050004) & 0xf) != 0xb)
	{
		cpu_relax();
//		if(--timeout == 0)
//			break;
		mdelay(10);
	}
//	if (timeout != 0)
//		printf("CP is in idle!\n");
//	else
//		printf("Warning: CP is NOT in idle!\n");

	if (cpu_is_pxa1928_a0())
		*(uint32_t *)0xd4051204 = 0x00000000;

}

static void comm_d2(void)
{
	void *dest;
	/* set BB_F_SLP in PMUM_SCCR to vote VCXO_SD */
	*(uint32_t *)0xd4050038 |= (0x1 << 2);

	dest = (void *)0x06000000;
	if (cpu_is_pxa1928_a0())
		memcpy(dest, sg_d2_a0_ops, (ARRAY_SIZE(sg_d2_a0_ops) * 4));
	else
		memcpy(dest, sg_d2_b0_ops, (ARRAY_SIZE(sg_d2_b0_ops) * 4));
	dest = (void *)0x07000000;
	memcpy(dest, msa_d2_ops, (ARRAY_SIZE(msa_d2_ops) * 4));
	flush_dcache_all();
	release_seagull();
}

int do_cp_d2(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	printf("put Seagull/MSA into D2 state\n");
	comm_d2();
	printf("done\n");

	return 0;
}

U_BOOT_CMD(
	cp_d2,       2,      1,      do_cp_d2,
	"Release Seagull/MSA from reset and put them into D2 state",
	"[ op number ]"
);
