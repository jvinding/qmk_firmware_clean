#pragma once

// Tapping configuration
#define TAPPING_TERM 250
#define CHORDAL_HOLD

// Split keyboard settings
// #define SPLIT_TRANSPORT_MIRROR
// #define SPLIT_LAYER_STATE_ENABLE
// #define SPLIT_LED_STATE_ENABLE
// #define SPLIT_MODS_ENABLE

// Disable features we don't need
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE

#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 175

// Enable RGB Matrix - disable all effects and animations
#ifdef RGB_MATRIX_ENABLE
// #    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_NONE
// #    define RGB_MATRIX_DISABLE_KEYCODES  // Disable RGB keycodes to prevent mode changes
// #    define RGB_MATRIX_DISABLE_TIMEOUT 0  // Disable timeout
#    define RGB_MATRIX_DISABLE_WHEN_USB_SUSPENDED  // Disable when suspended
#endif
