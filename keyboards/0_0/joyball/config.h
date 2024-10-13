// Copyright 2024 Alabahuy (@Alabahuy)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* ChibiOS SPI definitions */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP19

/* PMW3360 settings */
#define PMW33XX_CS_PIN GP21
#define POINTING_DEVICE_ROTATION_90
//#define POINTING_DEVICE_INVERT_X

/* disable debug print */
//#define NO_DEBUG

/* disable print */	
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
