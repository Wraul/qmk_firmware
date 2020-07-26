#include "keymap_swedish.h"
#include "wraul.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            // Prints the version of the firmware.
        case M_VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            }
            break;
            // Makes it easier to type { and [ on a Swedish version of Mac OS.
            // Types a { and if combined with a shift it prints a [.
        case M_LCBR:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                unregister_mods(temp_mod);
                clear_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    tap_code16(LALT(KC_8));
                } else {
                    tap_code16(LSFT(LALT(KC_8)));
                }
                register_mods(temp_mod);
                return false;
            }
            break;
            // Makes it easier to type } and ] on a Swedish version of Mac OS.
            // Types a } and if combined with a shift it prints a ].
        case M_RCBR:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                unregister_mods(temp_mod);
                clear_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    tap_code16(LALT(KC_9));
                } else {
                    tap_code16(LSFT(LALT(KC_9)));
                }
                register_mods(temp_mod);
                return false;
            }
            break;
            // Makes it easier to type { and [ on a Swedish version of Windows.
            // Types a { and if combined with a shift it prints a [.
        case M_LCBR_W:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                unregister_mods(temp_mod);
                clear_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    tap_code16(LALT(KC_7));
                } else {
                    tap_code16(ALGR(KC_7));
                }
                register_mods(temp_mod);
                return false;
            }
            break;
            // Makes it easier to type } and ] on a Swedish version of Windows.
            // Types a } and if combined with a shift it prints a ].
        case M_RCBR_W:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                unregister_mods(temp_mod);
                clear_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    tap_code16(LALT(KC_0));
                } else {
                    tap_code16(ALGR(KC_0));
                }
                register_mods(temp_mod);
                return false;
            }
            break;
        // Creates a key that acts like ' but types a | if combined with alt on a
        // Swedish version of Windows.
        case M_PIPE_W:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_ALT) {
                    unregister_mods(temp_mod);
                    clear_oneshot_mods();
                    tap_code16(SE_PIPE);
                    register_mods(temp_mod);
                } else {
                    tap_code(SE_QUOT);
                }
                return false;
            }
            break;
        // Makes it easier to type ~ and ` on a Swedish version of Mac OS.
        // Types a ~ followed by a space to take us out of the combine character mode.
        // If combined with a shift it does the same but prints a `.
        case M_CIRC:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                unregister_mods(temp_mod);
                clear_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    tap_code16(LSFT(SE_ACUT));
                    tap_code(KC_SPC);
                } else {
                    tap_code16(LALT(SE_QUOT));
                    tap_code(KC_SPC);
                }
                register_mods(temp_mod);
                return false;
            }
            break;
        // Compiles the firmware, and adds the flash command based on keyboard
        // bootloader
        case M_MAKE:
            if (!record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                unregister_mods(temp_mod);
                clear_oneshot_mods();
                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP);
#ifndef FLASH_BOOTLOADER
                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
#endif
                {
#if defined(__arm__)  // only run for ARM boards
                    SEND_STRING(":dfu-util");
#elif defined(BOOTLOADER_DFU)       // only run for DFU boards
                    SEND_STRING(":dfu");
#elif defined(BOOTLOADER_HALFKAY)   // only run for teensy boards
                    SEND_STRING(":teensy");
#elif defined(BOOTLOADER_CATERINA)  // only run for Pro Micros
                    SEND_STRING(":avrdude");
#endif                              // bootloader options
                }
                if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
                    SEND_STRING(" -j8 --output-sync");
                }
                SEND_STRING(SS_TAP(X_ENTER));
                register_mods(temp_mod);
                return false;
            }
            break;
        // Creates a key that acts like , but types a < if combined with alt on a
        // Swedish version of Mac OS. Note that this requires that the keyboard is set
        // to ANSI in the keyboard settings pane. As this appears to cause GRV to be
        // interpreted as NUBS
        case M_LABK:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_ALT) {
                    unregister_mods(temp_mod);
                    clear_oneshot_mods();
                    tap_code(KC_GRV);
                    register_mods(temp_mod);
                } else {
                    tap_code(SE_COMM);
                }
                return false;
            }
            break;
        // Creates a key that acts like . but types a > if combined with alt on a
        // Swedish version of Mac OS. Note that this requires that the keyboard is set
        // to ANSI in the keyboard settings pane. As this appears to cause GRV to be
        // interpreted as NUBS
        case M_RABK:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_ALT) {
                    unregister_mods(temp_mod);
                    clear_oneshot_mods();
                    tap_code16(LSFT(KC_GRV));
                    register_mods(temp_mod);
                } else {
                    tap_code(SE_DOT);
                }
                return false;
            }
            break;
        // Creates a key that acts like ' but types a | if combined with alt on a
        // Swedish version of Mac OS.
        case M_PIPE:
            if (record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();

                if ((temp_mod | temp_osm) & MOD_MASK_ALT) {
                    unregister_mods(temp_mod);
                    clear_oneshot_mods();
                    tap_code16(LALT(SE_7));
                    register_mods(temp_mod);
                } else {
                    tap_code(SE_QUOT);
                }
                return false;
            }
            break;
    }
    return process_record_keymap(keycode, record);
}
