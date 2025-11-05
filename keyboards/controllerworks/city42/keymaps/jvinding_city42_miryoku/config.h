#pragma once

// Tapping configuration
#define TAPPING_TERM 250
#define CHORDAL_HOLD

// Split keyboard settings
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

// Disable features we don't need
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE

// Enable RGB Matrix - disable all effects and animations
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_NONE
#    define RGB_MATRIX_DISABLE_KEYCODES  // Disable RGB keycodes to prevent mode changes
#    define RGB_MATRIX_DISABLE_TIMEOUT 0  // Disable timeout
#    define RGB_MATRIX_DISABLE_WHEN_USB_SUSPENDED  // Disable when suspended
#endif

// Trackpad configuration (Cirque Pinnacle)
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP16
#define POINTING_DEVICE_CS_PIN GP17

#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_1X
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE

