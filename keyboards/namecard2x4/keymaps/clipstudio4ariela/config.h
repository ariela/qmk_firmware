/* Copyright 2018 takashiski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// place overrides here

#define TAPPING_TERM 300

#ifdef RGBLIGHT_ENABLE
#include "ws2812.h"
#endif

#undef RGBLED_NUM
#define RGBLED_NUM 1

#if defined(RGBLIGHT_ENABLE) && !defined(IOS_DEVICE_ENABLE)
    #define USB_MAX_POWER_CONSUMPTION 400
#else
    #define USB_MAX_POWER_CONSUMPTION 100
#endif
