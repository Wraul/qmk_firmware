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

// Defines the keycodes used by our macros in process_record_keymap
enum my_keycodes {
  EPRM = KEYMAP_SAFE_RANGE,
  RGB_SLD,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_ergodox(/* Base */
                           // clang-format off
                           /* left hand */
                           /* ┌─────────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
                                M_CIRC,       KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_BSLS,
                           /* ├─────────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ */
                                KC_TAB,       KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     M_LCBR,
                           /* ├─────────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ */
                                KC_LCTL,      KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
                           /* ├─────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         │ */
                                KC_LSFT,      KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_NO,
                           /* └─────────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘ */
                                    KC_GRV,   NO_QUOT,  KC_LSFT,  KC_LALT,  KC_LGUI,
                           /*     └─────────┴─────────┴─────────┴─────────┴─────────┘                     */
                           /*                                                       ┌─────────┬─────────┐ */
                                                                                      KC_LEFT,  KC_RGHT,
                           /*                                             ┌─────────┼─────────┼─────────┤ */
                                                                                                KC_INS,
                           /*                                             │         │         ├─────────┤ */
                                                                            KC_BSPC,  KC_ESC,   KC_DEL,
                           /*                                             └─────────┴─────────┴─────────┘ */
                           /* right hand */
                           /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────────┐ */
                                NO_ACUT,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     NO_PIPE_MAC,
                           /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────────┤ */
                                M_RCBR,   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     NO_AA,
                           /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────────┤ */
                                          KC_H,     KC_J,     KC_K,     KC_L,     NO_OSLH,  NO_AE,
                           /* │         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────────┤ */
                                KC_NO,    KC_N,     KC_M,     M_LBRC,   M_RBRC,   KC_SLSH,  KC_RSFT,
                           /* └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────────┘ */
                                                    KC_RALT,  MO(_FN),  KC_RGUI,  NO_PLUS,  KC_RCTL,
                           /*                     └─────────┴─────────┴─────────┴─────────┴─────────┘     */
                           /* ┌─────────┬─────────┐                                                       */
                                KC_DOWN,  KC_UP,
                           /* ├─────────┼─────────┼─────────┐                                             */
                                KC_HOME,
                           /* ├─────────┤         │         │                                             */
                                KC_END,   KC_ENT,   KC_SPC
                           /* └─────────┴─────────┴─────────┘                                             */
                           // clang-format on
                           ),
    [_FN] = LAYOUT_ergodox(/* Function */
                           // clang-format off
                           /* left hand */
                           /* ┌─────────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
                                _______,      _______,  _______,  _______,  _______,  _______,  _______,
                           /* ├─────────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ */
                                _______,      _______,  KC_UP,    _______,  _______,  _______,  _______,
                           /* ├─────────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ */
                                _______,      KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,
                           /* ├─────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         │ */
                                _______,      _______,  _______,  _______,  M_VRSN,   _______,  _______,
                           /* └─────────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘ */
                                    _______,  _______,  _______,  _______,  _______,
                           /*     └─────────┴─────────┴─────────┴─────────┴─────────┘                     */
                           /*                                                       ┌─────────┬─────────┐ */
                                                                                      _______,  _______,
                           /*                                             ┌─────────┼─────────┼─────────┤ */
                                                                                                _______,
                           /*                                             │         │         ├─────────┤ */
                                                                            _______,  _______,  _______,
                           /*                                             └─────────┴─────────┴─────────┘ */
                           /* right hand */
                           /* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────────┐ */
                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
                           /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────────┤ */
                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
                           /* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────────┤ */
                                          _______,  _______,  _______,  _______,  _______,  _______,
                           /* │         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────────┤ */
                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
                           /* └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────────┘ */
                                                    _______,  _______,  _______,  _______,  _______,
                           /*                     └─────────┴─────────┴─────────┴─────────┴─────────┘     */
                           /* ┌─────────┬─────────┐                                                       */
                                _______,  _______,
                           /* ├─────────┼─────────┼─────────┐                                             */
                                _______,
                           /* ├─────────┤         │         │                                             */
                                _______,  _______,  _______
                           /* └─────────┴─────────┴─────────┘                                             */
                           // clang-format on
                           ),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
        return false;
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
    case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#else
#  ifdef RGBLIGHT_ENABLE
      rgblight_init();
#  endif
#endif
      break;
    case 1:
      ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
      break;
    case 2:
      ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
      break;
    case 3:
      ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
      break;
    default:
      break;
  }

  return state;
};
