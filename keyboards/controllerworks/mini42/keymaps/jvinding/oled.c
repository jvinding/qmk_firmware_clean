#include QMK_KEYBOARD_H
#include "../../../common/jvinding/keymap_common.h"
#include "caps_word.h"

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    // Get current layer
    uint8_t layer = get_highest_layer(layer_state);
    
    // Display layer name on first line
    oled_write_P(PSTR("Layer: "), false);
    
    // Map layer to display name
    switch (layer) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _EXTRA:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _TAP:
            oled_write_P(PSTR("Windows\n"), false);
            break;
        case _BUTTON:
            oled_write_P(PSTR("Buttons\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Num Pad\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Functions\n"), false);
            break;
        default:
            oled_write_P(PSTR("Unknown\n"), false);
            break;
    }
    
    // Get lock states
    led_t led_state = host_keyboard_led_state();
    bool caps_word_on = is_caps_word_on();
    
    // Display state indicators on second line with fixed positions
    // CL at position 0-1, CW at 3-4, NL at 6-7, SL at 9-10
    if (led_state.caps_lock) {
        oled_write_P(PSTR("CL"), false);
    } else {
        oled_write_P(PSTR("  "), false);
    }
    
    oled_write_P(PSTR(" "), false); // Space between CL and CW
    
    if (caps_word_on) {
        oled_write_P(PSTR("CW"), false);
    } else {
        oled_write_P(PSTR("  "), false);
    }
    
    oled_write_P(PSTR(" "), false); // Space between CW and NL
    
    if (led_state.num_lock) {
        oled_write_P(PSTR("NL"), false);
    } else {
        oled_write_P(PSTR("  "), false);
    }
    
    oled_write_P(PSTR(" "), false); // Space between NL and SL
    
    if (led_state.scroll_lock) {
        oled_write_P(PSTR("SL"), false);
    } else {
        oled_write_P(PSTR("  "), false);
    }
    
    return false;
}

#endif // OLED_ENABLE

