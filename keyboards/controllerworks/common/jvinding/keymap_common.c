#include QMK_KEYBOARD_H
#include "keymap_common.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Intercept CW_TOGG when shift is held and send KC_CAPS instead
    if (keycode == CW_TOGG && record->event.pressed) {
        uint8_t mods = get_mods();
        // Check if only shift (and no other modifiers) is held
        if ((mods & MOD_MASK_SHIFT) && !(mods & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI))) {
            // Send Caps Lock toggle instead
            tap_code(KC_CAPS);
            return false; // Prevent further processing
        }
    }
    return true; // Continue normal processing
}

