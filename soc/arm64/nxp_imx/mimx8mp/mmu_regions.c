/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <devicetree.h>
#include <soc.h>
#include <sys/util.h>
#include <arch/arm64/arm_mmu.h>

static const struct arm_mmu_region mmu_regions[] = {


	MMU_REGION_FLAT_ENTRY("GIC",
			      DT_REG_ADDR_BY_IDX(DT_INST(0, arm_gic), 0),
			      DT_REG_SIZE_BY_IDX(DT_INST(0, arm_gic), 0),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("GIC",
			      DT_REG_ADDR_BY_IDX(DT_INST(0, arm_gic), 1),
			      DT_REG_SIZE_BY_IDX(DT_INST(0, arm_gic), 1),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("CCM",
			      DT_REG_ADDR(DT_INST(0, nxp_imx_ccm)),
			      DT_REG_SIZE(DT_INST(0, nxp_imx_ccm)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("ANA_PLL",
			      DT_REG_ADDR(DT_INST(0, nxp_imx_ana)),
			      DT_REG_SIZE(DT_INST(0, nxp_imx_ana)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("UART",
			      DT_REG_ADDR(DT_INST(0, nxp_imx_iuart)),
			      DT_REG_SIZE(DT_INST(0, nxp_imx_iuart)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

#ifdef CONFIG_COUNTER_MCUX_GPT
	MMU_REGION_FLAT_ENTRY("GPT0",
			      DT_REG_ADDR(DT_INST(0, nxp_imx_gpt)),
			      DT_REG_SIZE(DT_INST(0, nxp_imx_gpt)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("GPT1",
			      DT_REG_ADDR(DT_INST(1, nxp_imx_gpt)),
			      DT_REG_SIZE(DT_INST(1, nxp_imx_gpt)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),
#endif

	MMU_REGION_FLAT_ENTRY("IOMUXC",
			      DT_REG_ADDR(DT_INST(0, nxp_imx_iomuxc)),
			      DT_REG_SIZE(DT_INST(0, nxp_imx_iomuxc)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("GPC",
			      DT_REG_ADDR(DT_INST(0, nxp_imx_gpc)),
			      DT_REG_SIZE(DT_INST(0, nxp_imx_gpc)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("I2C3",
			      DT_REG_ADDR(DT_INST(0, nxp_imx_i2c)),
			      DT_REG_SIZE(DT_INST(0, nxp_imx_i2c)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("SAI1",
			      DT_REG_ADDR(DT_INST(0, nxp_imx_sai)),
			      DT_REG_SIZE(DT_INST(0, nxp_imx_sai)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("SAI2",
			      DT_REG_ADDR(DT_INST(1, nxp_imx_sai)),
			      DT_REG_SIZE(DT_INST(1, nxp_imx_sai)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("SAI3",
			      DT_REG_ADDR(DT_INST(2, nxp_imx_sai)),
			      DT_REG_SIZE(DT_INST(2, nxp_imx_sai)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("SAI5",
			      DT_REG_ADDR(DT_INST(3, nxp_imx_sai)),
			      DT_REG_SIZE(DT_INST(3, nxp_imx_sai)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("SAI6",
			      DT_REG_ADDR(DT_INST(4, nxp_imx_sai)),
			      DT_REG_SIZE(DT_INST(4, nxp_imx_sai)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("SAI7",
			      DT_REG_ADDR(DT_INST(5, nxp_imx_sai)),
			      DT_REG_SIZE(DT_INST(5, nxp_imx_sai)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),

	MMU_REGION_FLAT_ENTRY("AUDIO_BLK_CTRL",
			      DT_REG_ADDR(DT_INST(0, nxp_imx_audio_blk_ctrl)),
			      DT_REG_SIZE(DT_INST(0, nxp_imx_audio_blk_ctrl)),
			      MT_DEVICE_nGnRE | MT_P_RW_U_RW | MT_NS),
};

const struct arm_mmu_config mmu_config = {
	.num_regions = ARRAY_SIZE(mmu_regions),
	.mmu_regions = mmu_regions,
};
