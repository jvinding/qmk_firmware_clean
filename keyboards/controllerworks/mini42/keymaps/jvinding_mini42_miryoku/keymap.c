#include QMK_KEYBOARD_H

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

// Custom keycodes
enum custom_keycodes {
    KC_REDO = SAFE_RANGE,
};

// Tap dance definitions
enum tap_dance_indices {
    TD_BASE,
    TD_EXTRA,
    TD_TAP,
    TD_NAV,
    TD_NUM,
    TD_MOUSE,
    TD_SYM,
    TD_MEDIA,
    TD_FUN,
    TD_BOOT,
};

// Tap dance state structure
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Determine current tap dance state
uint8_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return 1; // Single tap
        else return 2; // Single hold
    } else if (state->count == 2) {
        if (state->interrupted) return 3; // Double single tap
        else if (state->pressed) return 4; // Double hold
        else return 5; // Double tap
    } else return 6;
}

// Tap dance state instances
static tap base_tap_state = {.is_press_action = true, .state = 0};
static tap extra_tap_state = {.is_press_action = true, .state = 0};
static tap tap_tap_state = {.is_press_action = true, .state = 0};
static tap nav_tap_state = {.is_press_action = true, .state = 0};
static tap num_tap_state = {.is_press_action = true, .state = 0};
static tap mouse_tap_state = {.is_press_action = true, .state = 0};
static tap sym_tap_state = {.is_press_action = true, .state = 0};
static tap media_tap_state = {.is_press_action = true, .state = 0};
static tap fun_tap_state = {.is_press_action = true, .state = 0};
static tap boot_tap_state = {.is_press_action = true, .state = 0};

// Tap dance finished handlers
void base_finished(tap_dance_state_t *state, void *user_data) {
    base_tap_state.state = cur_dance(state);
    if (base_tap_state.state == 5) { // Double tap
        layer_move(_BASE);
    }
}

void base_reset(tap_dance_state_t *state, void *user_data) {
    base_tap_state.state = 0;
}

void extra_finished(tap_dance_state_t *state, void *user_data) {
    extra_tap_state.state = cur_dance(state);
    if (extra_tap_state.state == 5) { // Double tap
        layer_move(_EXTRA);
    }
}

void extra_reset(tap_dance_state_t *state, void *user_data) {
    extra_tap_state.state = 0;
}

void tap_finished(tap_dance_state_t *state, void *user_data) {
    tap_tap_state.state = cur_dance(state);
    if (tap_tap_state.state == 5) { // Double tap
        layer_move(_TAP);
    }
}

void tap_reset(tap_dance_state_t *state, void *user_data) {
    tap_tap_state.state = 0;
}

void nav_finished(tap_dance_state_t *state, void *user_data) {
    nav_tap_state.state = cur_dance(state);
    if (nav_tap_state.state == 5) { // Double tap
        layer_move(_NAV);
    }
}

void nav_reset(tap_dance_state_t *state, void *user_data) {
    nav_tap_state.state = 0;
}

void num_finished(tap_dance_state_t *state, void *user_data) {
    num_tap_state.state = cur_dance(state);
    if (num_tap_state.state == 5) { // Double tap
        layer_move(_NUM);
    }
}

void num_reset(tap_dance_state_t *state, void *user_data) {
    num_tap_state.state = 0;
}

void mouse_finished(tap_dance_state_t *state, void *user_data) {
    mouse_tap_state.state = cur_dance(state);
    if (mouse_tap_state.state == 5) { // Double tap
        layer_move(_MOUSE);
    }
}

void mouse_reset(tap_dance_state_t *state, void *user_data) {
    mouse_tap_state.state = 0;
}

void sym_finished(tap_dance_state_t *state, void *user_data) {
    sym_tap_state.state = cur_dance(state);
    if (sym_tap_state.state == 5) { // Double tap
        layer_move(_SYM);
    }
}

void sym_reset(tap_dance_state_t *state, void *user_data) {
    sym_tap_state.state = 0;
}

void media_finished(tap_dance_state_t *state, void *user_data) {
    media_tap_state.state = cur_dance(state);
    if (media_tap_state.state == 5) { // Double tap
        layer_move(_MEDIA);
    }
}

void media_reset(tap_dance_state_t *state, void *user_data) {
    media_tap_state.state = 0;
}

void fun_finished(tap_dance_state_t *state, void *user_data) {
    fun_tap_state.state = cur_dance(state);
    if (fun_tap_state.state == 5) { // Double tap
        layer_move(_FUN);
    }
}

void fun_reset(tap_dance_state_t *state, void *user_data) {
    fun_tap_state.state = 0;
}

void boot_finished(tap_dance_state_t *state, void *user_data) {
    boot_tap_state.state = cur_dance(state);
    if (boot_tap_state.state == 5) { // Double tap
        reset_keyboard();
    }
}

void boot_reset(tap_dance_state_t *state, void *user_data) {
    boot_tap_state.state = 0;
}

// Tap dance actions array
tap_dance_action_t tap_dance_actions[] = {
    [TD_BASE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, base_finished, base_reset),
    [TD_EXTRA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, extra_finished, extra_reset),
    [TD_TAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_finished, tap_reset),
    [TD_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_finished, nav_reset),
    [TD_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_finished, num_reset),
    [TD_MOUSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mouse_finished, mouse_reset),
    [TD_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_finished, sym_reset),
    [TD_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, media_finished, media_reset),
    [TD_FUN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fun_finished, fun_reset),
    [TD_BOOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, boot_finished, boot_reset),
};

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_REDO:
                register_code(KC_LGUI);
                register_code(KC_Y);
                unregister_code(KC_Y);
                unregister_code(KC_LGUI);
                return false;
        }
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
// Layer color definitions
static const RGB layer_colors[] = {
    [_BASE] = {RGB_WHITE},
    [_EXTRA] = {RGB_RED},
    [_TAP] = {RGB_SPRINGGREEN},
    [_BUTTON] = {RGB_PINK},
    [_NAV] = {RGB_CYAN},
    [_MOUSE] = {RGB_YELLOW},
    [_MEDIA] = {RGB_PURPLE},
    [_NUM] = {RGB_BLUE},
    [_NUMPAD] = {RGB_TURQUOISE},
    [_SYM] = {RGB_GREEN},
    [_FUN] = {RGB_ORANGE},
};

// Helper function to get layer color
static RGB get_layer_color(uint8_t layer) {
    if (layer < sizeof(layer_colors) / sizeof(layer_colors[0])) {
        return layer_colors[layer];
    }
    return (RGB){RGB_WHITE}; // Default color
}

// Helper function to get target layer from a keycode
static int8_t get_layer_for_keycode(uint16_t keycode) {
    // Check for layer-tap keys (LT)
    if (IS_QK_LAYER_TAP(keycode)) {
        return QK_LAYER_TAP_GET_LAYER(keycode);
    }

    // Check for tap dance keys that activate layers
    if (IS_QK_TAP_DANCE(keycode)) {
        uint8_t td_index = QK_TAP_DANCE_GET_INDEX(keycode);
        switch (td_index) {
            case TD_BASE: return _BASE;
            case TD_EXTRA: return _EXTRA;
            case TD_TAP: return _TAP;
            case TD_NAV: return _NAV;
            case TD_NUM: return _NUM;
            case TD_MOUSE: return _MOUSE;
            case TD_SYM: return _SYM;
            case TD_MEDIA: return _MEDIA;
            case TD_FUN: return _FUN;
            case TD_BOOT: return -1; // Boot doesn't activate a layer
            default: return -1;
        }
    }

    return -1; // Keycode doesn't activate a layer
}

// Helper function to resolve keycode through layers (handles KC_TRNS)
static uint16_t resolve_keycode(keypos_t keypos, layer_state_t state) {
    // Check layers from highest to lowest
    for (int8_t layer = 31; layer >= 0; layer--) {
        if (!(state & (1UL << layer))) {
            continue; // Layer not active
        }
        uint16_t keycode = keymap_key_to_keycode(layer, keypos);
        if (keycode != KC_TRNS && keycode != KC_NO) {
            return keycode;
        }
    }
    // Check default layer
    for (int8_t layer = 31; layer >= 0; layer--) {
        if (!(default_layer_state & (1UL << layer))) {
            continue;
        }
        uint16_t keycode = keymap_key_to_keycode(layer, keypos);
        if (keycode != KC_TRNS && keycode != KC_NO) {
            return keycode;
        }
    }
    return KC_NO;
}

// Set RGB colors based on layers
bool rgb_matrix_indicators_user(void) {
    layer_state_t combined_state = layer_state | default_layer_state;
    uint8_t current_layer = get_highest_layer(combined_state);

    // Iterate through all matrix positions
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];

            // Skip if no LED at this position
            if (led_index == NO_LED) {
                continue;
            }

            // Resolve keycode through layers (handles KC_TRNS)
            keypos_t keypos = {.row = row, .col = col};
            uint16_t keycode = resolve_keycode(keypos, combined_state);

            // If keycode is KC_NO, set to off
            if (keycode == KC_NO) {
                rgb_matrix_set_color(led_index, 0, 0, 0);
                continue;
            }

            // Check if keycode activates a layer
            int8_t target_layer = get_layer_for_keycode(keycode);
            if (target_layer >= 0) {
                // Key activates a layer, show that layer's color
                RGB color = get_layer_color(target_layer);
                rgb_matrix_set_color(led_index, color.r, color.g, color.b);
            } else {
                // Key doesn't activate a layer, show current layer's color
                RGB color = get_layer_color(current_layer);
                rgb_matrix_set_color(led_index, color.r, color.g, color.b);
            }
        }
    }

    return false;
}

// Set underglow color based on active layer
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t active_layer = get_highest_layer(state | default_layer_state);
    RGB color = get_layer_color(active_layer);
    rgb_matrix_set_color_all(color.r, color.g, color.b);
    return state;
}
#endif // RGB_MATRIX_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // BASE layer - Colemak
    [_BASE] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_NO,
        KC_NO, LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), HYPR_T(KC_D), HYPR_T(KC_H), RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O), KC_NO,
        KC_NO, LT(_BUTTON, KC_Z), KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  LT(_BUTTON, KC_SLSH), KC_NO,
                                            LT(_FUN, KC_DEL), LT(_NUM, KC_BSPC), LT(_SYM, KC_ENT), LT(_MOUSE, KC_TAB), LT(_NAV, KC_SPC), LT(_MEDIA, KC_ESC)
    ),

    // EXTRA layer - QWERTY variant
    [_EXTRA] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_NO, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), HYPR_T(KC_G), HYPR_T(KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_QUOT), KC_NO,
        KC_NO, LT(_BUTTON, KC_Z), KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  LT(_BUTTON, KC_SLSH), KC_NO,
                                            LT(_FUN, KC_DEL), LT(_NUM, KC_BSPC), LT(_SYM, KC_ENT), LT(_MOUSE, KC_TAB), LT(_NAV, KC_SPC), LT(_MEDIA, KC_ESC)
    ),

    // TAP layer - Mod-tap adjustments
    [_TAP] = LAYOUT_split_3x6_3(
        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_NO, LGUI_T(KC_A), KC_TRNS, LCTL_T(KC_S), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RCTL_T(KC_E), KC_TRNS, RGUI_T(KC_O), KC_NO,
        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // NAV layer - Navigation
    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_NO,   TD(TD_BASE), TD(TD_EXTRA), TD(TD_TAP), TD(TD_BOOT), KC_NO,
        KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, CW_TOGG, KC_HYPR, KC_RSFT,    KC_RGUI,      KC_RALT,    KC_RCTL,    KC_NO,
        KC_NO, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, KC_REDO, KC_NO,   TD(TD_NAV), TD(TD_NUM),   KC_NO,      KC_NO,      KC_NO,
                                            KC_DEL,  KC_BSPC,   KC_ENT,       KC_NO,      KC_NO,      KC_NO
    ),

    // MOUSE layer
    [_MOUSE] = LAYOUT_split_3x6_3(
        KC_NO, MS_WHLU, MS_WHLL, MS_UP,   MS_WHLR, KC_NO,   KC_NO,   TD(TD_BASE), TD(TD_EXTRA), TD(TD_TAP), TD(TD_BOOT), KC_NO,
        KC_NO, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, KC_NO,   KC_HYPR, KC_RSFT,    KC_RGUI,      KC_RALT,    KC_RCTL,    KC_NO,
        KC_NO, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, KC_REDO, KC_NO,   TD(TD_MOUSE), TD(TD_SYM),   KC_NO,      KC_NO,      KC_NO,
                                            MS_BTN3, MS_BTN1,    MS_BTN2,      KC_NO,      KC_NO,      KC_NO
    ),

    // MEDIA layer
    [_MEDIA] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,   KC_NO,   KC_VOLU, KC_NO,   KC_NO,   KC_NO,   TD(TD_BASE), TD(TD_EXTRA), TD(TD_TAP), TD(TD_BOOT), KC_NO,
        KC_NO, KC_NO,   KC_MPRV, KC_VOLD, KC_MNXT, KC_NO,   KC_HYPR, KC_RSFT,    KC_RGUI,      KC_RALT,    KC_RCTL,    KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TD(TD_MEDIA), TD(TD_FUN),   KC_NO,      KC_NO,      KC_NO,
                                            KC_MUTE, KC_MPLY,    KC_MSTP,      KC_NO,      KC_NO,      KC_NO
    ),

    // NUM layer
    [_NUM] = LAYOUT_split_3x6_3(
        KC_NO, TD(TD_BOOT), TD(TD_TAP), TD(TD_EXTRA), TD(TD_BASE), MO(_NUMPAD), KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_NO,
        KC_NO, KC_LCTL,    KC_LALT,    KC_LGUI,      KC_LSFT,     KC_HYPR,     KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN, KC_NO,
        KC_NO, KC_NO,      KC_NO,      TD(TD_NAV),   TD(TD_NUM),   KC_NO,       KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,  KC_NO,
                                            KC_NO,  KC_NO,      KC_NO,      KC_MINS, KC_0,    KC_DOT
    ),

    // NUMPAD layer
    [_NUMPAD] = LAYOUT_split_3x6_3(
        KC_NO, TD(TD_BOOT), TD(TD_TAP), TD(TD_EXTRA), TD(TD_BASE), KC_NO,      KC_KP_SLASH, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_NO,
        KC_NO, KC_LCTL,    KC_LALT,    KC_LGUI,      KC_LSFT,     KC_HYPR,    KC_KP_ASTERISK, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_NO,
        KC_NO, KC_NO,      KC_NO,      TD(TD_NAV),   TD(TD_NUM),   KC_NO,      KC_KP_ENTER, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_EQUAL, KC_NO,
                                            KC_NO,  KC_NO,      KC_NO,      KC_BSPC, KC_KP_0, KC_KP_DOT
    ),

    // SYM layer
    [_SYM] = LAYOUT_split_3x6_3(
        KC_NO, TD(TD_BOOT), TD(TD_TAP), TD(TD_EXTRA), TD(TD_BASE), KC_NO,      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO,
        KC_NO, KC_LCTL,    KC_LALT,    KC_LGUI,      KC_LSFT,     KC_HYPR,    KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN, KC_NO,
        KC_NO, KC_NO,      KC_NO,      TD(TD_MOUSE), TD(TD_SYM),   KC_NO,      KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD, KC_NO,
                                            KC_NO,  KC_NO,      KC_NO,      KC_UNDS, KC_LPRN, KC_RPRN
    ),

    // FUN layer
    [_FUN] = LAYOUT_split_3x6_3(
        KC_NO, TD(TD_BOOT), TD(TD_TAP), TD(TD_EXTRA), TD(TD_BASE), KC_NO,      KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_NO,
        KC_NO, KC_LCTL,    KC_LALT,    KC_LGUI,      KC_LSFT,     KC_HYPR,    KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_NO,
        KC_NO, KC_NO,      KC_NO,      TD(TD_MEDIA), TD(TD_FUN),   KC_NO,      KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_NO,
                                            KC_NO,  KC_NO,      KC_NO,      KC_TAB,  KC_SPC,  KC_APP
    ),

    // BUTTON layer
    [_BUTTON] = LAYOUT_split_3x6_3(
        KC_NO, MS_WHLL,   MS_WHLD,   MS_WHLU,   MS_WHLR,   KC_UNDO,  KC_UNDO,  MS_WHLL,   MS_WHLD,   MS_WHLU,   MS_WHLR,   KC_NO,
        KC_NO, KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,    KC_NO,    KC_LSFT,   KC_LCTL,   KC_LALT,   KC_LGUI,   KC_NO,
        KC_NO, KC_UNDO,   KC_CUT,    KC_COPY,   KC_PASTE,  KC_REDO,  KC_REDO,  KC_PASTE,  KC_COPY,   KC_CUT,    KC_UNDO,   KC_NO,
                                            MS_BTN3, MS_BTN1,    MS_BTN2,      MS_BTN2,  MS_BTN1, MS_BTN3
    ),
};

