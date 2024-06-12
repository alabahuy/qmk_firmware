// Copyright 2023 Alabahuy (@Alabahuy)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

#define ADNS5050_SCLK_PIN GP18
#define ADNS5050_SDIO_PIN GP19
#define ADNS5050_CS_PIN   GP21

#define POINTING_DEVICE_ROTATION_270

#define DEBOUNCE 5

/* disable debug print */
//#define NO_DEBUG

/* disable print */	
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
