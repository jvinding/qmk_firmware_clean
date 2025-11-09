#include QMK_KEYBOARD_H
#include "keymap_common.h"

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
static tap numpad_tap_state = {.is_press_action = true, .state = 0};
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

void numpad_finished(tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = cur_dance(state);
    if (numpad_tap_state.state == 5) { // Double tap
        layer_move(_NUM);
    }
}

void numpad_reset(tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = 0;
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

