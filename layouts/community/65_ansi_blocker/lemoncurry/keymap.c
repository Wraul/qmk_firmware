/* Copyright 2019 Mathias Andersson
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
#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "wraul.h"

enum my_layers {
  _QW,
  _FN,
};

// Defines the keycodes used by our macros in process_record_user
/* enum custom_keycodes { QMKBEST = KEYMAP_SAFE_RANGE, QMKURL }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_65_ansi_blocker(/* Base */
                            // clang-format off
                            /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────────────────────────┬─────────┐ */
                                 KC_ESC,   SE_1,     SE_2,     SE_3,     SE_4,     SE_5,     SE_6,     SE_7,     SE_8,     SE_9,     SE_0,     SE_PLUS,  SE_ACUT,            KC_BSPC,            KC_DEL,
                            /* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────────────────────────┼─────────┤ */
                                    KC_TAB,     SE_Q,     SE_W,     SE_E,     SE_R,     SE_T,     SE_Y,     SE_U,     SE_I,     SE_O,     SE_P,     SE_ARNG,  SE_DIAE,         M_PIPE_W,         KC_HOME,
                            /* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴────────────────────────┼─────────┤ */
                                     KC_CAPS,      SE_A,     SE_S,     SE_D,     SE_F,     SE_G,     SE_H,     SE_J,     SE_K,     SE_L,     SE_ODIA,  SE_ADIA,             KC_ENT,              KC_PGUP,
                            /* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴────────────────────┬──────────┼─────────┤ */
                                       KC_LSFT,        SE_Z,     SE_X,     SE_C,     SE_V,     SE_B,     SE_N,     SE_M,     M_LABK,   M_RABK,   SE_MINS,          KC_RSFT,           KC_UP,     KC_PGDN,
                            /* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┴─┬───────────┬──┬─────────┼──────────┼─────────┤ */
                                  KC_LCTL,    KC_LGUI,    KC_LALT,                                  KC_SPC,                                      KC_RALT,    MO(_FN),       KC_LEFT,  KC_DOWN,   KC_RGHT
                            /* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────────────────┴───────────┴───────────┘  └─────────┴──────────┴─────────┘ */
                            // clang-format on
                            ),
    [_FN] = LAYOUT_65_ansi_blocker(/* Function */
                            // clang-format off
                            /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────────────────────────┬─────────┐ */
                                 SE_SECT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             RGB_TOG,            KC_INS,
                            /* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────────────────────────┼─────────┤ */
                                    _______,    _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,         _______,          KC_END,
                            /* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴────────────────────────┼─────────┤ */
                                     KC_LCTL,      KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,             RGB_HUI,
                            /* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴────────────────────┬──────────┼─────────┤ */
                                       _______,        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,           RGB_MOD,   RGB_SAI,
                            /* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┴─┬───────────┬──┬─────────┼──────────┼─────────┤ */
                                  _______,    _______,    _______,                                  _______,                                     _______,    _______,       RGB_SPI,  RGB_RMOD,  RGB_VAI
                            /* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────────────────┴───────────┴───────────┘  └─────────┴──────────┴─────────┘ */
                            // clang-format on
                            ),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  /* switch (keycode) { */
  /*   case QMKBEST: */
  /*     if (record->event.pressed) { */
  /*       // when keycode QMKBEST is pressed */
  /*       SEND_STRING("QMK is the best thing ever!"); */
  /*     } else { */
  /*       // when keycode QMKBEST is released */
  /*     } */
  /*     break; */
  /*   case QMKURL: */
  /*     if (record->event.pressed) { */
  /*       // when keycode QMKURL is pressed */
  /*       SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER)); */
  /*     } else { */
  /*       // when keycode QMKURL is released */
  /*     } */
  /*     break; */
  /* } */
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
