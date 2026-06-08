#include QMK_KEYBOARD_H

// =========================================================
//  Keymap – AL Custom 60 (5×12 = 60 key)
//
//  Layout fisik (sesuaikan dengan PCB kamu):
//  Row 0 : ESC  1    2    3    4    5    6    7    8    9    0    BSPC
//  Row 1 : TAB  Q    W    E    R    T    Y    U    I    O    P    DEL
//  Row 2 : CAPS A    S    D    F    G    H    J    K    L    ;    ENT
//  Row 3 : LSFT Z    X    C    V    B    N    M    ,    .    /    RSFT
//  Row 4 : LCTL LGUI LALT [  S P A C E B A R  ]   RALT APP  FN   ◄    ►
//
//  Catatan Row 4 spacebar:
//    Jika spacebar-mu satu switch (mis. 7u), biarkan [4,3]=SPC dan
//    [4,4]~[4,6]=KC_NO.  Jika ada beberapa switch di area spacebar,
//    sesuaikan sendiri.
// =========================================================

enum layers {
    _BASE = 0,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ── Layer 0: Base ──────────────────────────────────────────
    [_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,

        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,

        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,

        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_NO,   KC_NO,
        KC_NO,   KC_RALT, KC_APP,  MO(_FN), KC_LEFT, KC_RIGHT
    ),

    // ── Layer 1: FN (tahan FN key) ─────────────────────────────
    // Row 0 : `~   F1   F2   F3   F4   F5   F6   F7   F8   F9  F10   F11
    // Row 1 : F12  ---  ---  ---  ---  ---  ---  ---  ---  --- PSCR  INS
    // Row 2 : ---  ---  ---  ---  ---  ---  ---  ---  ---  ---  ---  ---
    // Row 3 : ---  ---  ---  ---  ---  ---  ---  ---  PGDN PGUP HOME  END
    // Row 4 : ---  ---  ---  ---  ---  ---  ---  ---  ---  [FN] MPRV MNXT
    [_FN] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,

        KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_INS,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, KC_HOME, KC_END,

        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_MPRV, KC_MNXT
    ),
};

// =========================================================
//  Encoder (opsional – hapus jika tidak ada rotary encoder)
// =========================================================
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (clockwise) {
//         tap_code(KC_VOLU);
//     } else {
//         tap_code(KC_VOLD);
//     }
//     return false;
// }

// =========================================================
//  Custom keycodes (tambahkan di sini jika perlu)
// =========================================================
// enum custom_keycodes {
//     MY_KEY = SAFE_RANGE,
// };
//
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case MY_KEY:
//             if (record->event.pressed) {
//                 SEND_STRING("Hello from AL Custom 60!");
//             }
//             return false;
//     }
//     return true;
// }
