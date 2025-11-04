#pragma once

// Tapping configuration
#define TAPPING_TERM 250
#define HOLD_ON_OTHER_KEY_PRESS
#define CHORDAL_HOLD

// Split keyboard settings
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

// Disable features we don't need
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE

// Enable RGB Matrix
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#endif

