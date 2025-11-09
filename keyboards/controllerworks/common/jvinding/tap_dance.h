#pragma once

#include QMK_KEYBOARD_H
#include "keymap_common.h"

// Forward declarations for tap dance handlers
void base_finished(tap_dance_state_t *state, void *user_data);
void base_reset(tap_dance_state_t *state, void *user_data);
void extra_finished(tap_dance_state_t *state, void *user_data);
void extra_reset(tap_dance_state_t *state, void *user_data);
void tap_finished(tap_dance_state_t *state, void *user_data);
void tap_reset(tap_dance_state_t *state, void *user_data);
void nav_finished(tap_dance_state_t *state, void *user_data);
void nav_reset(tap_dance_state_t *state, void *user_data);
void num_finished(tap_dance_state_t *state, void *user_data);
void num_reset(tap_dance_state_t *state, void *user_data);
void numpad_finished(tap_dance_state_t *state, void *user_data);
void numpad_reset(tap_dance_state_t *state, void *user_data);
void mouse_finished(tap_dance_state_t *state, void *user_data);
void mouse_reset(tap_dance_state_t *state, void *user_data);
void sym_finished(tap_dance_state_t *state, void *user_data);
void sym_reset(tap_dance_state_t *state, void *user_data);
void media_finished(tap_dance_state_t *state, void *user_data);
void media_reset(tap_dance_state_t *state, void *user_data);
void fun_finished(tap_dance_state_t *state, void *user_data);
void fun_reset(tap_dance_state_t *state, void *user_data);
void boot_finished(tap_dance_state_t *state, void *user_data);
void boot_reset(tap_dance_state_t *state, void *user_data);

// Tap dance actions array (must be included in keymap.c for introspection)
tap_dance_action_t tap_dance_actions[] = {
    [TD_BASE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, base_finished, base_reset),
    [TD_EXTRA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, extra_finished, extra_reset),
    [TD_TAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_finished, tap_reset),
    [TD_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_finished, nav_reset),
    [TD_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_finished, num_reset),
    [TD_NUMPAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, numpad_finished, numpad_reset),
    [TD_MOUSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mouse_finished, mouse_reset),
    [TD_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_finished, sym_reset),
    [TD_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, media_finished, media_reset),
    [TD_FUN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fun_finished, fun_reset),
    [TD_BOOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, boot_finished, boot_reset),
};

