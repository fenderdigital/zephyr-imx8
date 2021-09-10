/*
 * Copyright (c) 2020, Manivannan Sadhasivam <mani@kernel.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define OCRAM_ADDR  DT_REG_SIZE(DT_NODELABEL(ocram))

#include <arch/arm/aarch32/cortex_m/scripts/linker.ld>
