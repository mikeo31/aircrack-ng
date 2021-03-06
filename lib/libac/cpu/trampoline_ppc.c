/*
 *  Copyright (C) 2018 Joseph Benden <joe@benden.us>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#if defined(__ppc__) || defined(__PPC__)
#ifdef HAS_AUXV
#include <sys/auxv.h>
#include <bits/hwcap.h>
#endif
#else
#error "The wrong CPU architecture file has been included."
#endif

#include "aircrack-ng/cpu/trampoline.h"

void simd_init(void) {}

void simd_destroy(void) {}

int simd_get_supported_features(void)
{
	int result = 0;
#ifdef HAS_AUXV
	long hwcaps = getauxval(AT_HWCAP2);

#if defined(PPC_FEATURE2_ARCH_2_07)
	if (hwcaps & PPC_FEATURE2_ARCH_2_07)
	{
		result |= SIMD_SUPPORTS_POWER8;
	}
#endif
#endif

	return (result);
}
