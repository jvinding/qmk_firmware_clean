#pragma once

#include QMK_KEYBOARD_H
#include "keymap_common.h"

// Combo definitions
enum combo_events {
    COMBO_XZ_CUT,
    COMBO_XC_COPY,
    COMBO_CV_PASTE,
    COMBO_LENGTH
};

// Combo key arrays
extern const uint16_t PROGMEM combo_xz_cut[];
extern const uint16_t PROGMEM combo_xc_copy[];
extern const uint16_t PROGMEM combo_cv_paste[];

// Combo actions array
extern combo_t key_combos[COMBO_LENGTH];

