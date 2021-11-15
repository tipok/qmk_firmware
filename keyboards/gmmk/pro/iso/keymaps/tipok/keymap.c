/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2021 tipok

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Mac OS Custom Macros
#define KC_LCKS LCTL(LCMD(KC_Q))  // Lock Screen
#define KC_CSTL LCMD(LSFT(KC_5))  // Screen capture tool

uint8_t current_layer;

enum tipoks_keycodes { TP_EFF1 = SAFE_RANGE, TP_EFF2 };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_CSTL,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_LCKS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_MNXT,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_MPRV,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_MPLY,
        KC_LCTL, KC_LALT, KC_LCMD,                            KC_SPC,                             KC_RCMD, KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_BRMD, KC_BRMU, _______, _______,   _______, _______, _______, _______,   _______, _______, _______, _______, KC_INS,            RESET,
        _______, _______, _______, _______, _______,   _______, _______, _______, _______,   _______, _______, _______, _______, KC_DEL,            _______,
        _______, _______, _______, _______, _______,   _______, _______, _______, _______,   _______, _______, _______, _______,                    _______,
        _______, _______, _______, _______, _______,   _______, _______, _______, _______,   _______, _______, _______, _______, _______,           _______,
        MO(2),   _______, _______, _______, _______,   _______, _______, _______, _______,   _______, _______, _______,          _______, KC_PGUP,  _______,
        _______, _______, _______,                              AG_TOGG,                              _______, _______, _______, KC_HOME, KC_PGDN,  KC_END
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______,   RGB_TOG, RGB_MOD, RGB_RMOD, RGB_M_P, _______, _______, _______, _______, _______,         _______,
        _______, _______, _______, _______, _______,   TP_EFF1, TP_EFF2, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                              _______,                            _______, _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
        case TP_EFF1:
            if (record->event.pressed) {
                // Do something when pressed
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
            } else {
                // Do something else when release
            }
            return false;
        case TP_EFF2:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
            }
            return false;
        default:
            return true;  // Process all other keycodes normally
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
#ifdef CONSOLE_ENABLE
    uprintf("Encoder: index: %d, clockwise: %b \n", index, clockwise);
#endif
    if (clockwise) {
        switch (current_layer) {
            case 2:
                rgblight_increase_val();
                break;
            case 1:
                tap_code(KC_BRMU);
                break;
            default:
                tap_code(KC_VOLU);
                break;
        }
    } else {
        switch (current_layer) {
            case 2:
                rgblight_decrease_val();
                break;
            case 1:
                tap_code(KC_BRMD);
                break;
            default:
                tap_code(KC_VOLD);
                break;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, 0)) {
        current_layer = 0;
    }
    if (layer_state_cmp(state, 1)) {
        current_layer = 1;
    }
    if (layer_state_cmp(state, 2)) {
        current_layer = 2;
    }
    if (layer_state_cmp(state, 3)) {
        current_layer = 3;
    }
#ifdef CONSOLE_ENABLE
    uprintf("Current layer: %d\n", current_layer);
#endif
    return state;
}
