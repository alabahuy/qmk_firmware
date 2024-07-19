// Copyright 2023 Alabahuy (@Alabahuy)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

#define ADNS5050_SCLK_PIN         F7
#define ADNS5050_SDIO_PIN         F6
#define ADNS5050_CS_PIN           B1

#define POINTING_DEVICE_ROTATION_180
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y

#define USB_POLLING_INTERVAL_MS 1

/* disable debug print */
//#define NO_DEBUG

/* disable print */	
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
