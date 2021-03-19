/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <arch/cpu.h>
#include <device.h>
#include <init.h>
#include <soc.h>

/**
 * @brief Perform basic hardware initialization at boot.
 *
 * This needs to be run from the very beginning.
 * So the init priority has to be 0 (zero).
 *
 * @return 0
 */
static int mimx8mp_init(const struct device *arg)
{
	ARG_UNUSED(arg);

	return 0;
}

SYS_INIT(mimx8mp_init, PRE_KERNEL_1, 0);
