#pragma once

#define VENDOR_ID       0xA8F8
#define PRODUCT_ID      0x1839
#define DEVICE_VER      0x0001
#define MANUFACTURER    "Bastard Keyboards"
#define PRODUCT         "Charybdis"

// Matrix configuration
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// Split keyboard configuration
#define USE_SERIAL
#define SPLIT_HAND_PIN GP16
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

// Pointing device (trackball) configuration
#define POINTING_DEVICE_DRIVER pmw3610
#define PMW3610_CS_PIN GP20
#define PMW3610_CK_PIN GP8
#define PMW3610_DI_PIN GP17
#define PMW3610_DO_PIN GP17
#define POINTING_DEVICE_ROTATION_90
#define PMW3610_CPI 2000
#define PMW3610_CPI_DIVIDOR 4
#define PMW3610_ORIENTATION_90
#define PMW3610_SNIPE_CPI 800
#define PMW3610_SNIPE_CPI_DIVIDOR 4
#define PMW3610_SCROLL_TICK 40
#define PMW3610_INVERT_X
#define PMW3610_RUN_DOWNSHIFT_TIME_MS 3264
#define PMW3610_REST1_SAMPLE_TIME_MS 20
#define PMW3610_POLLING_RATE_125_SW

// Tap-hold configuration (matching ZMK config)
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 150
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Home row mods configuration
#define BILATERAL_COMBINATIONS
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4

// Combo configuration  
#define COMBO_COUNT 6
#define COMBO_TERM 40
#define COMBO_MUST_HOLD_MODS
#define COMBO_HOLD_TERM 150

// Layer configuration
#define LAYER_STATE_8BIT

// Mouse key settings
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

// RGB/LED configuration (if applicable)
#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#endif