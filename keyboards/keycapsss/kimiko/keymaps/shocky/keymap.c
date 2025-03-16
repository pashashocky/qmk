#include QMK_KEYBOARD_H

#include "keymap.h"

// To make combo dictionary work (see combos.def for definitinos)
#if defined(COMBO_ENABLE)
#    include "g/keymap_combo.h"
#endif


/// key morphs
// 
// Tap: comma | Shift + tap: semicolon | Ctrl + shift + tap: <.
const key_override_t comma_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, ~0, MOD_MASK_CG, ko_option_no_reregister_trigger);
const key_override_t comma_inner_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_COMM, KC_LT, ~0, MOD_MASK_AG, ko_option_no_reregister_trigger);

// Tap: dot | Shift + tap: colon | Ctrl + shift + tap: >.
const key_override_t dot_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_DOT, KC_COLN, ~0, MOD_MASK_CG, ko_option_no_reregister_trigger);
const key_override_t dot_inner_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_DOT, KC_GT, ~0, MOD_MASK_AG, ko_option_no_reregister_trigger);

// Tap: qmark | Shift + tap: excl.
const key_override_t q_morph = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_QUES, KC_EXLM, ~0, MOD_MASK_CAG, ko_option_no_reregister_trigger);

// Shift (: gt
const key_override_t lprn_gt = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_LPRN, KC_LABK, ~0, MOD_MASK_CAG, ko_option_no_reregister_trigger);
const key_override_t rprn_lt = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_RPRN, KC_RABK, ~0, MOD_MASK_CAG, ko_option_no_reregister_trigger);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&comma_morph,
	&comma_inner_morph,
	&dot_morph,
	&dot_inner_morph,
	&q_morph,
	&lprn_gt,
	&rprn_lt
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
    ___,               ___,            KC_TAB,            BSPC_NAV,          MAGIC,              ENT_NAV,          SPC_FUN,         MO(NUM),      ___,            ___
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
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;
uint8_t modifier = 0;


// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

// magic key functionality
void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if ((keycode != MAGIC) || (record->tap.count == 0)) { // MAGIC is a LSFT_T, so hold should not trigger repeat
        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = GET_TAP_KC(keycode);
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { /* repeat action defined here */
        // first check whether last keycode was shift or enter, or we paused for a while. It so morth to OS shift
        if ((last_keycode == KC_SPC) || (last_keycode == KC_ENT) || (last_keycode == KC_BSPC) || (timer_elapsed(non_combo_input_timer) > 500)) {
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
        // process repeat key as usual
        } else { 
            if (record->event.pressed) {
                register_mods(last_modifier);
                register_code16(last_keycode);
            } else {
                unregister_code16(last_keycode);
                unregister_mods(last_modifier);
            }
        }
    }
}

// main processing function
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Process repeat key
  process_repeat_key(keycode, record);
  mod_state = get_mods();
  oneshot_mod_state = get_oneshot_mods();
  
  // Input timer to adjust combo term
  non_combo_input_timer = timer_read();

  switch (keycode) {

    // magic caps
    case MAGIC:
      if (!record->tap.count) {
        if (record->event.pressed) {
          register_mods(MOD_BIT(KC_LSFT));
        } else {
          unregister_mods(MOD_BIT(KC_LSFT));
        }
      }
      break;

    // nav layer home row parenthesis
    case LGUI_T(KC_LPRN):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_LPRN); // send `(` on tap
        return false;
      }
      break;
    case LSFT_T(KC_RPRN):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_RPRN); // send `)` on tap
        return false;
      }
      break;

    }

    return true; // process all the other keys normally
}

// the time of the last input, used to tweak the timing of combos depending on if I'm currently
// in active typing flow (should practically remove any chance of mistriggering combos)
uint16_t get_combo_term(uint16_t index, combo_t *combo) {

  if ((index >= WF_ESC) && (index <= COMMDOT_RCBR)) { // horizontal alpha combos
    return timer_elapsed(non_combo_input_timer) > 150 ? 20 : 20;
  } 

  if (index >= WR_AT) return 40; // vertical combos

  return COMBO_TERM;
  
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


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case SPC_FUN:
    case ENT_NAV:
    case MAGIC:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case SPC_FUN:
    case ENT_NAV:
    case MAGIC:
        return true;
    default:
        return false;
    }
}

