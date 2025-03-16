#pragma once

#include QMK_KEYBOARD_H
//
// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;
uint8_t cur_mod_state;
uint8_t cur_oneshot_mod_state;
uint16_t last_keycode;

enum layers { BASE, NAV, FUN, NUM, MOUSE };

#define MAGIC LT(0, KC_NO)

// momentary mouse
#define MO_MOUSE MO(MOUSE)

// thumbs
#define BSPC_NAV LT(NAV, KC_BSPC)
#define ENT_NAV LT(NAV, KC_ENT)
#define SPC_FUN LT(FUN, KC_SPC)

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define HOME_G HYPR_T(KC_G)

// Right-hand home row mods
#define HOME_M HYPR_T(KC_M)
#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)
