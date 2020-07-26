#pragma once

#include "action.h"
#include "quantum.h"
#include "version.h"

enum custom_keycodes {
    M_MAKE = SAFE_RANGE,
    M_VRSN,
    M_LCBR,
    M_RCBR,
    M_LCBR_W,
    M_RCBR_W,
    M_PIPE,
    M_PIPE_W,
    M_CIRC,
    M_LBRC,
    M_RBRC,
    KEYMAP_SAFE_RANGE  // use "KEYMAP_SAFE_RANGE" for keymap specific codes
};

// Swap space in Mac OS
#define W_LSPC LCTL(KC_LEFT)
#define W_RSPC LCTL(KC_RGHT)
