#pragma once

#define MASTER_LEFT
// #define MASTER_RIGHT

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 140
// #define TAPPING_TERM_PER_KEY // bottom of keymap.c - currently not implemented

// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#quick-tap-term
// within this ms to trigger auto-repeat on e.g. homerow
#define QUICK_TAP_TERM 80

// Apply the modifier on keys that are tapped during a short hold of a modtap.
// bottom of keymap.c
#define PERMISSIVE_HOLD_PER_KEY

// Ignore same-hand mods.
#define BILATERAL_COMBINATIONS 150

// number of taps to activate TT
#define TAPPING_TOGGLE 1

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Combo settings
#define COMBO_TERM 30
#define COMBO_TERM_PER_COMBO
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_VARIABLE_LEN
#define COMBO_ONLY_FROM_LAYER 0

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_WHEEL_DELAY    0
#define MOUSEKEY_MAX_SPEED      13
#define MOUSEKEY_TIME_TO_MAX    26


#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_HUE_STEP 8
#   define RGBLIGHT_SAT_STEP 8
#   define RGBLIGHT_VAL_STEP 8
#   define RGBLIGHT_SLEEP       /* the RGB lighting will be switched off when the host goes to sleep */
#   define RGBLIGHT_EFFECT_RGB_TEST
#endif

// Limits the max. amount of layers to 8 to save firmware memory.
#define LAYER_STATE_8BIT

// Shortcut layer creation
#define XXX KC_NO
#define ___ KC_TRNS // transparent

#define LAYOUT_miryoku(\
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT(\
XXX, XXX, XXX, XXX, XXX, XXX,                XXX, XXX, XXX, XXX, XXX, XXX,\
XXX, K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, XXX,\
XXX, K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23, K24, XXX,      XXX, K25, K26, K27, K28, K29, XXX,\
          XXX, XXX, K32, K33, K34,      K35, K36, K37, XXX, XXX\
)
