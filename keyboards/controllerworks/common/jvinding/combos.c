#include QMK_KEYBOARD_H
#include "keymap_common.h"
#include "combos.h"

// Combo key sequences
// Note: Z key is LT(_BUTTON, KC_Z) in the keymap, so we use that keycode
const uint16_t PROGMEM combo_xz_cut[] = {KC_X, LT(_BUTTON, KC_Z), COMBO_END};
const uint16_t PROGMEM combo_xc_copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cv_paste[] = {KC_C, KC_V, COMBO_END};

// Combo actions array
combo_t key_combos[COMBO_LENGTH] = {
    [COMBO_XZ_CUT] = COMBO(combo_xz_cut, U_CUT),
    [COMBO_XC_COPY] = COMBO(combo_xc_copy, U_COPY),
    [COMBO_CV_PASTE] = COMBO(combo_cv_paste, U_PASTE),
};

