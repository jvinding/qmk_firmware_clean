#pragma once

// Layer definitions
enum layers {
    _BASE,
    _EXTRA,
    _TAP,
    _BUTTON,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _NUMPAD,
    _SYM,
    _FUN,
};

// Tap dance definitions
enum tap_dance_indices {
    TD_BASE,
    TD_EXTRA,
    TD_TAP,
    TD_NAV,
    TD_NUM,
    TD_NUMPAD,
    TD_MOUSE,
    TD_SYM,
    TD_MEDIA,
    TD_FUN,
    TD_BOOT,
};

// Macros for common shortcuts
#define U_UNDO LCMD(KC_Z)
#define U_REDO SCMD(KC_Z)
#define U_CUT LCMD(KC_X)
#define U_COPY LCMD(KC_C)
#define U_PASTE LCMD(KC_V)

