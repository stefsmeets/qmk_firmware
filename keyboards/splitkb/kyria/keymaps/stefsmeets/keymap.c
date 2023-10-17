/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "emoji.h"

enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _GAME,
    _SYMBOL,
    _NAV,
    _NUM,
    _FUNCTION,
    _ADJUST,
}


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK)
#define GAME     DF(_GAME)

#define SYM      MO(_SYMBOL)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define FUNC     MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define SFT_SPC  MT(MOD_LSFT, KC_SPC)
#define SFT_TAB  MT(MOD_LSFT, KC_TAB)
#define SFT_QUO  MT(MOD_RSFT, KC_QUOT)

#define FUN_ENT  LT(_FUNCTION, KC_ENT)
#define NUM_ENT  LT(_NUM, KC_ENT)

// Tap Dance declarations
enum {
  _SFT_SFT
};

void dance_onshot_lsft(tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      set_oneshot_mods(MOD_LSFT);
      break;
    case 2:
      caps_word_toggle();
      break;
  }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Capsword
    [_SFT_SFT] = ACTION_TAP_DANCE_FN(dance_onshot_lsft),
};

#define SFT_SFT  TD(_SFT_SFT)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Base Layer: COLEMAK

    [_COLEMAK] = LAYOUT(
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
      SFT_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O, SFT_QUO,
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_CAPS,    FUNC, KC_PSCR, QK_LEAD,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_DEL,
                                 KC_LGUI, KC_LALT,     SYM,  KC_SPC, NUM_ENT, SFT_SFT,  KC_SPC,     NAV, KC_LEFT, KC_RGHT
    ),

    [_QWERTY] = LAYOUT(
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
      _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_GAME] = LAYOUT(
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
      _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// Layer: Neo symbols
// https://github.com/Dakes/qmk_config/blob/main/kyria/keymaps/dakes/keymap.c
// https://www.neo-layout.org/
// 20231002 Swap position [] and {}

    [_SYMBOL] = LAYOUT(
      _______,   KC_AT, KC_UNDS, KC_LCBR, KC_RCBR, KC_CIRC,                                     KC_EXLM, KC_LABK, KC_RABK,  KC_EQL, KC_AMPR, _______,
      _______, KC_BSLS, KC_SLSH, KC_LBRC, KC_RBRC, KC_ASTR,                                     KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, _______,
      _______, KC_HASH,  KC_DLR, KC_PIPE, KC_TILD, KC_GRV , _______, _______, _______, _______, KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  Layer: Navigation

    [_NAV] = LAYOUT(
      _______, _______, KC_BSPC,  KC_TAB,  KC_DEL, KC_PGUP,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_LEFT,   KC_UP, KC_RGHT, KC_PGDN,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, _______, KC_HOME, KC_DOWN, KC_END,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  Layer: Number

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS,  KC_ENT,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  Layer: Function

    [_FUNCTION] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// Adjust Layer: Music, Emoji

    [_ADJUST] = LAYOUT(
      _______, _______, _______, KC_VOLU, _______,  QWERTY,                                     UM(UC_THUMBSUP),    UM(UC_FACE_SYMBOLS_MOUTH), UM(UC_SMIRKING_FACE),     UM(UC_ZANY_FACE),                UM(UC_WINKING_FACE),      _______,
      _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, COLEMAK,                                     UM(UC_WAVING_HAND), UM(UC_GRINNING_FACE),      UM(UC_BEAMING_FACE),      UM(UC_GRINNING_FACE_WITH_SWEAT), UM(UC_FACE_TEARS_JOY),    _______,
      _______, _______, _______, KC_MPLY, KC_MUTE,    GAME, _______, _______, _______, _______, UM(UC_THUMBSDOWN),  UM(UC_LOUDLY_CRYING_FACE), UM(UC_FACE_ROLLING_EYES), UM(UC_FACE_RAISED_EYEBROW),      UM(UC_DISAPPOINTED_FACE), _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};


// Turn off power led
// https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
void keyboard_pre_init_user(void) {
  setPinOutput(24);
  writePinHigh(24);
}


// https://docs.qmk.fm/#/ref_functions?id=update_tri_layer_statestate-x-y-z
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYMBOL, _ADJUST);
}

#ifdef OLED_ENABLE
    #include "oled.h"
#endif
