// This file contains the keymap layer definitions
// It is included by keymap.c files in both city42 and mini42 keymaps

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // BASE layer - Colemak
    [_BASE] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q,              KC_W,         KC_F,             KC_P,              KC_G,             KC_J,               KC_L,             KC_U,              KC_Y,         KC_QUOT,              KC_NO,
        KC_NO, LCTL_T(KC_A),      LALT_T(KC_R), LGUI_T(KC_S),     LSFT_T(KC_T),      HYPR_T(KC_D),     HYPR_T(KC_H),       RSFT_T(KC_N),     RGUI_T(KC_E),      RALT_T(KC_I), RCTL_T(KC_O),         KC_NO,
        KC_NO, LT(_BUTTON, KC_Z), KC_X,         KC_C,             KC_V,              KC_B,             KC_K,               KC_M,             KC_COMM,           KC_DOT,       LT(_BUTTON, KC_SLSH), KC_NO,
                                                LT(_FUN, KC_DEL), LT(_NUM, KC_BSPC), LT(_SYM, KC_ENT), LT(_MOUSE, KC_TAB), LT(_NAV, KC_SPC), LT(_MEDIA, KC_ESC)
    ),

    // EXTRA layer - QWERTY variant
    [_EXTRA] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q,              KC_W,         KC_E,             KC_R,              KC_T,             KC_Y,               KC_U,             KC_I,         KC_O,         KC_P,                 KC_NO,
        KC_NO, LCTL_T(KC_A),      LALT_T(KC_S), LGUI_T(KC_D),     LSFT_T(KC_F),      HYPR_T(KC_G),     HYPR_T(KC_H),       RSFT_T(KC_J),     RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_QUOT),      KC_NO,
        KC_NO, LT(_BUTTON, KC_Z), KC_X,         KC_C,             KC_V,              KC_B,             KC_N,               KC_M,             KC_COMM,      KC_DOT,       LT(_BUTTON, KC_SLSH), KC_NO,
                                                LT(_FUN, KC_DEL), LT(_NUM, KC_BSPC), LT(_SYM, KC_ENT), LT(_MOUSE, KC_TAB), LT(_NAV, KC_SPC), LT(_MEDIA, KC_ESC)
    ),

    // TAP layer - Mod-tap adjustments
    [_TAP] = LAYOUT_split_3x6_3(
        KC_NO, KC_TRNS,      KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,      KC_NO,
        KC_NO, LGUI_T(KC_A), KC_TRNS, LCTL_T(KC_S), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RCTL_T(KC_E), KC_TRNS, RGUI_T(KC_O), KC_NO,
        KC_NO, KC_TRNS,      KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,      KC_NO,
                                      KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // NAV layer - Navigation
    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO, KC_PGUP, KC_HOME, KC_UP,   KC_END,   KC_INS,  KC_NO,   TD(TD_BASE), TD(TD_EXTRA), TD(TD_TAP), TD(TD_BOOT), KC_NO,
        KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  CW_TOGG, KC_HYPR, KC_RSFT,     KC_RGUI,      KC_RALT,    KC_RCTL,     KC_NO,
        KC_NO, U_UNDO,  U_CUT,   U_COPY,  U_PASTE,  U_REDO,  KC_NO,   TD(TD_NAV),  TD(TD_NUM),   KC_NO,      KC_NO,       KC_NO,
                                 KC_DEL,  KC_BSPC,  KC_ENT,  KC_NO,   KC_NO,       KC_NO
    ),

    // MOUSE layer
    [_MOUSE] = LAYOUT_split_3x6_3(
        KC_NO, MS_WHLU, MS_WHLL, MS_UP,   MS_WHLR,  KC_NO,   KC_NO,   TD(TD_BASE),  TD(TD_EXTRA), TD(TD_TAP), TD(TD_BOOT), KC_NO,
        KC_NO, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT,  KC_NO,   KC_HYPR, KC_RSFT,      KC_RGUI,      KC_RALT,    KC_RCTL,     KC_NO,
        KC_NO, U_UNDO,  U_CUT,   U_COPY,  U_PASTE,  U_REDO,  KC_NO,   TD(TD_MOUSE), TD(TD_SYM),   KC_NO,      KC_NO,       KC_NO,
                                 MS_BTN3, MS_BTN1,  MS_BTN2, KC_NO,   KC_NO,        KC_NO
    ),

    // MEDIA layer
    [_MEDIA] = LAYOUT_split_3x6_3(
        KC_NO, RM_HUEU, RM_SATU, KC_VOLU, RM_VALU, RM_TOGG, KC_NO,   TD(TD_BASE),  TD(TD_EXTRA), TD(TD_TAP), TD(TD_BOOT), KC_NO,
        KC_NO, RM_NEXT, KC_MPRV, KC_VOLD, KC_MNXT, KC_NO,   KC_HYPR, KC_RSFT,      KC_RGUI,      KC_RALT,    KC_RCTL,     KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TD(TD_MEDIA), TD(TD_FUN),   KC_NO,      KC_NO,       KC_NO,
                                 KC_MUTE, KC_MPLY, KC_MSTP, KC_NO,   KC_NO,        KC_NO
    ),

    // NUM layer
    [_NUM] = LAYOUT_split_3x6_3(
        KC_NO, TD(TD_BOOT), TD(TD_TAP), TD(TD_EXTRA), TD(TD_BASE), MO(_NUMPAD), KC_LBRC, KC_7, KC_8,  KC_9, KC_RBRC, KC_NO,
        KC_NO, KC_LCTL,     KC_LALT,    KC_LGUI,      KC_LSFT,     KC_HYPR,     KC_EQL,  KC_4, KC_5,  KC_6, KC_SCLN, KC_NO,
        KC_NO, KC_NO,       KC_NO,      TD(TD_NAV),   TD(TD_NUM),  KC_NO,       KC_BSLS, KC_1, KC_2,  KC_3, KC_GRV,  KC_NO,
                                        KC_NO,        KC_NO,       KC_NO,       KC_MINS, KC_0, KC_DOT
    ),

    // NUMPAD layer
    [_NUMPAD] = LAYOUT_split_3x6_3(
        KC_NO, TD(TD_BOOT), TD(TD_TAP), TD(TD_EXTRA), TD(TD_BASE),   KC_NO,   KC_KP_SLASH,    KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_NO,
        KC_NO, KC_LCTL,     KC_LALT,    KC_LGUI,      KC_LSFT,       KC_HYPR, KC_KP_ASTERISK, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,  KC_NO,
        KC_NO, KC_NO,       KC_NO,      TD(TD_NAV),   TD(TD_NUMPAD), KC_NO,   KC_KP_ENTER,    KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_EQUAL, KC_NO,
                                        KC_NO,        KC_NO,         KC_NO,   KC_BSPC,        KC_KP_0, KC_KP_DOT
    ),

    // SYM layer
    [_SYM] = LAYOUT_split_3x6_3(
        KC_NO, TD(TD_BOOT), TD(TD_TAP), TD(TD_EXTRA), TD(TD_BASE), KC_NO,   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO,
        KC_NO, KC_LCTL,     KC_LALT,    KC_LGUI,      KC_LSFT,     KC_HYPR, KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN, KC_NO,
        KC_NO, KC_NO,       KC_NO,      TD(TD_MOUSE), TD(TD_SYM),  KC_NO,   KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD, KC_NO,
                                        KC_NO,        KC_NO,       KC_NO,   KC_UNDS, KC_LPRN, KC_RPRN
    ),

    // FUN layer
    [_FUN] = LAYOUT_split_3x6_3(
        KC_NO, TD(TD_BOOT), TD(TD_TAP), TD(TD_EXTRA), TD(TD_BASE), KC_NO,   KC_PSCR, KC_F7,  KC_F8, KC_F9, KC_F12, KC_NO,
        KC_NO, KC_LCTL,     KC_LALT,    KC_LGUI,      KC_LSFT,     KC_HYPR, KC_SCRL, KC_F4,  KC_F5, KC_F6, KC_F11, KC_NO,
        KC_NO, KC_NO,       KC_NO,      TD(TD_MEDIA), TD(TD_FUN),  KC_NO,   KC_PAUS, KC_F1,  KC_F2, KC_F3, KC_F10, KC_NO,
                                        KC_NO,        KC_NO,       KC_NO,   KC_TAB,  KC_SPC, KC_APP
    ),

    // BUTTON layer
    [_BUTTON] = LAYOUT_split_3x6_3(
        KC_NO, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,  U_UNDO,  U_UNDO,  MS_WHLL,  MS_WHLD, MS_WHLU, MS_WHLR, KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_NO,   KC_NO,   KC_LSFT,  KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO, U_UNDO,  U_CUT,   U_COPY,  U_PASTE,  U_REDO,  U_REDO,  U_PASTE,  U_COPY,  U_CUT,   U_UNDO,  KC_NO,
                                          MS_BTN3,  MS_BTN1, MS_BTN2, MS_BTN2,  MS_BTN1, MS_BTN3
    ),
};

