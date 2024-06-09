// Copyright 2023 Alabahuy (@Alabahuy)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* LCD Configuration */
#define LCD_RST_PIN GP17
#define LCD_CS_PIN GP21
#define LCD_DC_PIN GP20

/* ChibiOS SPI definitions */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN NO_PIN

/* Quantum Painter */
#define QUANTUM_PAINTER_DEBUG
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 61440
//#define QUANTUM_PAINTER_TASK_THROTTLE 200

/* Backlight */
#define BACKLIGHT_PWM_DRIVER PWMD3
#define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_A

/* Audio */
//#define AUDIO_PIN GP16
//#define AUDIO_PWM_DRIVER PWMD0
//#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
//#define AUDIO_INIT_DELAY
//#define AUDIO_CLICKY

//#define SPEAKER_SHUTDOWN GP25

#define DEBOUNCE 5

/* Joystick */
#define ANALOG_JOYSTICK_X_AXIS_PIN GP27
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP26
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
