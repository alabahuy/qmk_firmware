// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "pointing_device.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ A │
     * └───┘
     */
    [0] = LAYOUT_ortho_1x3(
        KC_BTN2, KC_BTN1, KC_BTN3
    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    } 
    return true;
}
#endif

void pointing_device_init_user(void) {
    // Set DPI to 1200
    pointing_device_set_cpi(1200);
}
