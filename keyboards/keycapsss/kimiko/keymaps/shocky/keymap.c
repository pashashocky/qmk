#include QMK_KEYBOARD_H

#include "keymap.h"

// To make combo dictionary work (see combos.def for definitinos)
#if defined(COMBO_ENABLE)
#    include "g/keymap_combo.h"
#endif


/// key morphs
// 
// Tap: comma | Shift + tap: semicolon | Ctrl + shift + tap: <.
const key_override_t comma_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, ~0, MOD_MASK_CAG, ko_option_no_reregister_trigger);
const key_override_t comma_inner_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_COMM, KC_LT, ~0, MOD_MASK_AG, ko_option_no_reregister_trigger);

// Tap: dot | Shift + tap: colon | Ctrl + shift + tap: >.
const key_override_t dot_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_DOT, KC_COLN, ~0, MOD_MASK_CAG, ko_option_no_reregister_trigger);
const key_override_t dot_inner_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_DOT, KC_GT, ~0, MOD_MASK_AG, ko_option_no_reregister_trigger);

// Tap: qmark | Shift + tap: excl.
const key_override_t q_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_QUES, KC_EXLM, ~0, MOD_MASK_CAG, ko_option_no_reregister_trigger);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&comma_morph,
	&comma_inner_morph,
	&dot_morph,
	&dot_inner_morph,
	&q_morph,
};
/// end key morphs

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_miryoku(
//╭──────────────────┬───────────────┬──────────────────┬──────────────────┬─────────────────╮ ╭─────────────────┬────────────────┬─────────────────┬────────────────┬─────────────────╮
    KC_Q,              KC_W,           KC_F,              KC_P,              KC_B,               KC_J,             KC_L,            KC_U,             KC_Y,            KC_QUOT,
//├──────────────────┼───────────────┼──────────────────┼──────────────────┼─────────────────┤ ├─────────────────┼────────────────┼─────────────────┼────────────────┼─────────────────┤
    HOME_A,            HOME_R,         HOME_S,            HOME_T,            HOME_G,             HOME_M,           HOME_N,          HOME_E,           HOME_I,          HOME_O,
//├──────────────────┼───────────────┼──────────────────┼──────────────────┼─────────────────┤ ├─────────────────┼────────────────┼─────────────────┼────────────────┼─────────────────┤
    KC_Z,              KC_X,           KC_C,              KC_D,              KC_V,               KC_K,             KC_H,            KC_COMM,          KC_DOT,          KC_QUES,
//├──────────────────┼───────────────┼──────────────────┼──────────────────┼─────────────────┤ ├─────────────────┼────────────────┼─────────────────┼────────────────┼─────────────────┤
    ___,               ___,            KC_TAB,            LT(NAV, KC_BSPC),  KC_LSFT,            LT(NAV, KC_ENT),  LT(FUN, KC_SPC), MO(TG(NUM)),      ___,            ___
//                                   ╰──────────────────┴──────────────────┴─────────────────╯ ╰─────────────────┴────────────────┴─────────────────╯
  ),

  [NAV] = LAYOUT_miryoku(
//╭─────────────┬─────────────┬──────────────────┬──────────────────┬─────────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
    KC_ESC,       ___,          KC_LCBR,           KC_RCBR,           KC_MINS,            ___,          KC_BSPC,      ___,          KC_DEL,       ___,
//├─────────────┼─────────────┼──────────────────┼──────────────────┼─────────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    KC_LCTL,      KC_LALT,      LGUI_T(KC_LPRN),   LSFT_T(KC_RPRN),   KC_HYPR,            ___,          KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,
//├─────────────┼─────────────┼──────────────────┼──────────────────┼─────────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    KC_GRV,       KC_UNDS,      KC_LBRC,           KC_RBRC,           KC_TILD,            KC_INS,       KC_HOME,      KC_PGDN,      KC_PGUP,      KC_END,
//├─────────────┼─────────────┼──────────────────┼──────────────────┼─────────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    ___,          ___,          ___,               ___,               ___,                BASE,        KC_TAB,       ___,          ___,          ___
//                            ╰──────────────────┴──────────────────┴─────────────────╯ ╰─────────────┴─────────────┴─────────────╯
  ),

  [FUN] = LAYOUT_miryoku(
//╭────────────────┬───────────────┬──────────────────┬──────────────────┬────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
    KC_F12,          KC_F7,          KC_F8,             KC_F9,             KC_PSCR,       RGB_HUI,      KC_MUTE,      KC_VOLD,      KC_VOLU,      RGB_HUD,
//├────────────────┼───────────────┼──────────────────┼──────────────────┼────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    LCTL_T(KC_F11),  LALT_T(KC_F4),  LGUI_T(KC_F5),     LSFT_T(KC_F6),     ___,           ___,          KC_MPRV,      KC_MPLY,      KC_MNXT,      KC_ENT,
//├────────────────┼───────────────┼──────────────────┼──────────────────┼────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    KC_F10,          KC_F1,          KC_F2,             KC_F3,             ___,           RGB_SAI,      ___,        ___,      ___,          RGB_SAD,
//├────────────────┼───────────────┼──────────────────┼──────────────────┼────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    ___,             ___,            KC_UNDS,           ___,               KC_MINS,       ___,          ___,          ___,          ___,          ___
//                                 ╰──────────────────┴──────────────────┴────────────╯ ╰─────────────┴─────────────┴─────────────╯
  ),

  [NUM] = LAYOUT_miryoku(
//╭────────────────┬───────────────┬──────────────────┬──────────────────┬────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
    ___,             KC_7,           KC_8,              KC_9,              ___,           ___,          ___,          ___,          ___,          ___,
//├────────────────┼───────────────┼──────────────────┼──────────────────┼────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    KC_0,            KC_4,           KC_5,              KC_6,              KC_DOT,        ___,          ___,          ___,          ___,          ___,
//├────────────────┼───────────────┼──────────────────┼──────────────────┼────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    ___,             KC_1,           KC_2,              KC_3,              ___,           ___,          ___,          ___,          ___,          ___,
//├────────────────┼───────────────┼──────────────────┼──────────────────┼────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    ___,             ___,            ___,               ___,               ___,           ___,          ___,          ___,          ___,          ___
//                                 ╰──────────────────┴──────────────────┴────────────╯ ╰─────────────┴─────────────┴─────────────╯
  ),

  [MOUSE] = LAYOUT_miryoku(
//╭────────────────┬───────────────┬──────────────────┬──────────────────┬────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
    ___,             ___,            ___,               ___,               ___,           ___,          KC_PGDN,      ___,          KC_PGUP,      ___,
//├────────────────┼───────────────┼──────────────────┼──────────────────┼────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    ___,             ___,            ___,               ___,               ___,           ___,          KC_MS_L,      KC_MS_D,      KC_MS_U,      KC_MS_R,
//├────────────────┼───────────────┼──────────────────┼──────────────────┼────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    ___,             ___,            ___,               ___,               ___,           ___,          KC_WH_L,      KC_WH_D,      KC_WH_U,      KC_WH_R,
//├────────────────┼───────────────┼──────────────────┼──────────────────┼────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
    ___,             ___,            ___,               ___,               ___,           KC_BTN1,      KC_BTN2,      KC_BTN3,      ___,          ___
//                                 ╰──────────────────┴──────────────────┴────────────╯ ╰─────────────┴─────────────┴─────────────╯
  ),

};


static uint16_t non_combo_input_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Input timer to adjust combo term
  non_combo_input_timer = timer_read();

  switch (keycode) {

    // nav layer home row parenthesis
    case LGUI_T(KC_LPRN):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_LPRN); // send `(` on tab
        return false;
      }
      break;
    case LSFT_T(KC_RPRN):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_RPRN); // send `)` on tab
        return false;
      }
      break;

    }
    return true;
}

// Per key permissive hold settings
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_R:
        case HOME_S:
        case HOME_E:
        case HOME_I:
            return false;  /* disable permissive hold for Alt and Gui */
        default:
            return true;   /* enable per default */
    }
}

// the time of the last input, used to tweak the timing of combos depending on if I'm currently
// in active typing flow (should practically remove any chance of mistriggering combos)
uint16_t get_combo_term(uint16_t index, combo_t *combo) {

  if ((index >= WF_ESC) && (index <= COMMDOT_RCBR)) { // horizontal alpha combos
    return timer_elapsed(non_combo_input_timer) > 300 ? 20 : 5;
  } 

  if (index >= WR_AT) return 40; // vertical combos

  return COMBO_TERM;
  
}
