// Copyright 2023 Alabahuy (@Alabahuy)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* Audio */
#define AUDIO_PIN GP15
#define AUDIO_PWM_DRIVER PWMD7
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#define AUDIO_INIT_DELAY
#define AUDIO_CLICKY

/* Haptics */ 
// #define SOLENOID_PIN GP17
// #define SOLENOID_DEFAULT_DWELL 20
// #define SOLENOID_MIN_DWELL 4
// #define HAPTIC_OFF_IN_LOW_POWER 1
// #define NO_HAPTIC_MOD

/* ChibiOS SPI definitions */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP6
#define SPI_MISO_PIN GP16
#define SPI_MOSI_PIN GP7

/* PMW3360 settings */
#define PMW33XX_CS_PIN GP5
#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_INVERT_X

/* disable debug print */
//#define NO_DEBUG

/* disable print */	
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
