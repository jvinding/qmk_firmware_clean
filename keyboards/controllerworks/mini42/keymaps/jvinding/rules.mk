TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes

RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no

CAPS_WORD_ENABLE = yes
# CAPS_WORD_INVERT_ON_SHIFT = yes

AUTO_SHIFT_ENABLE = yes

# Include additional source files from common directory
SRC += ../../../common/jvinding/tap_dance.c
SRC += ../../../common/jvinding/keymap_common.c
SRC += ../../../common/jvinding/combos.c
SRC += rgb.c
SRC += oled.c
