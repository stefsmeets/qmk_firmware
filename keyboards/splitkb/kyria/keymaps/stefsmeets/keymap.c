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


enum layers {
    _QWERTY = 0,
    _SYMBOL,
    _NAV,
    _NUM,
    _FUNCTION,
    _ADJUST,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

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


enum unicode_names {
    UC_GRINNING_FACE, // 😃
    UC_BEAMING_FACE, // 😁
    UC_GRINNING_FACE_WITH_SWEAT, // 😅
    UC_ROLLING_LAUGHING, // 🤣
    UC_FACE_TEARS_JOY, // 😂
    UC_WINKING_FACE, // 😉
    UC_SMILING_FACE_HALO, // 😇
    UC_SMILING_FACE_HEARTS, // 🥰
    UC_SMILING_FACE_HEART_EYES, // 😍
    UC_FACE_BLOWING_KISS, // 😘
    UC_FACE_SAVORING_FOOD, // 😋
    UC_ZANY_FACE, // 🤪
    UC_HUGGING_FACE, // 🤗
    UC_SHUSHING_FACE, // 🤫
    UC_THINKING_FACE, // 🤔
    UC_FACE_RAISED_EYEBROW, // 🤨
    UC_NEUTRAL_FACE, // 😐
    UC_SMIRKING_FACE, // 😏
    UC_FACE_ROLLING_EYES, // 🙄
    UC_PENSIVE_FACE, // 😔
    UC_FACE_VOMITING, // 🤮
    UC_WOOZY_FACE, // 🥴
    UC_PLEADING_FACE, // 🥺
    UC_LOUDLY_CRYING_FACE, // 😭
    UC_DISAPPOINTED_FACE, // 😞
    UC_FACE_SYMBOLS_MOUTH, // 🤬
    UC_SMILING_FACE_HORNS, // 😈
    UC_SKULL, // 💀
    UC_PILE_POO, // 💩
    UC_GHOST, // 👻
    UC_ALIEN_MONSTER, // 👾
    UC_RED_HEART, // ❤
    UC_BOMB, // 💣
    UC_WAVING_HAND, // 👋
    UC_OK_HAND, // 👌
    UC_CLAPPING_HANDS, // 👏
    UC_EYES, // 👀
    UC_MAN_FACEPALMING, // 🤦
    UC_TURTLE, // 🐢
    UC_SNAKE, // 🐍
    UC_SPOUTING_WHALE, // 🐳
    UC_DRAGON, // 🐉
    UC_TREX, // 🦖
    UC_ARGENTINA_A, // 🇦
    UC_ARGENTINA_R, // 🇷
    UC_THUMBSDOWN, // 👍
    UC_THUMBSUP, // 👎
};

const uint32_t unicode_map[] PROGMEM = {
    [UC_GRINNING_FACE] = 0x1F603,
    [UC_BEAMING_FACE] = 0x1F601,
    [UC_GRINNING_FACE_WITH_SWEAT] = 0x1F605,
    [UC_ROLLING_LAUGHING] = 0x1F923,
    [UC_FACE_TEARS_JOY] = 0x1F602,
    [UC_WINKING_FACE] = 0x1F609,
    [UC_SMILING_FACE_HALO] = 0x1F607,
    [UC_SMILING_FACE_HEARTS] = 0x1F970,
    [UC_SMILING_FACE_HEART_EYES] = 0x1F60D,
    [UC_FACE_BLOWING_KISS] = 0x1F618,
    [UC_FACE_SAVORING_FOOD] = 0x1F60B,
    [UC_ZANY_FACE] = 0x1F92A,
    [UC_HUGGING_FACE] = 0x1F917,
    [UC_SHUSHING_FACE] = 0x1F92B,
    [UC_THINKING_FACE] = 0x1F914,
    [UC_FACE_RAISED_EYEBROW] = 0x1F928,
    [UC_NEUTRAL_FACE] = 0x1F610,
    [UC_SMIRKING_FACE] = 0x1F60F,
    [UC_FACE_ROLLING_EYES] = 0x1F644,
    [UC_PENSIVE_FACE] = 0x1F614,
    [UC_FACE_VOMITING] = 0x1F92E,
    [UC_WOOZY_FACE] = 0x1F974,
    [UC_PLEADING_FACE] = 0x1F97A,
    [UC_LOUDLY_CRYING_FACE] = 0x1F62D,
    [UC_DISAPPOINTED_FACE] = 0x1F61E,
    [UC_FACE_SYMBOLS_MOUTH] = 0x1F92C,
    [UC_SMILING_FACE_HORNS] = 0x1F608,
    [UC_SKULL] = 0x1F480,
    [UC_PILE_POO] = 0x1F4A9,
    [UC_GHOST] = 0x1F47B,
    [UC_ALIEN_MONSTER] = 0x1F47E,
    [UC_RED_HEART] = 0x2764,
    [UC_BOMB] = 0x1F4A3,
    [UC_WAVING_HAND] = 0x1F44B,
    [UC_OK_HAND] = 0x1F44C,
    [UC_CLAPPING_HANDS] = 0x1F44F,
    [UC_EYES] = 0x1F440,
    [UC_MAN_FACEPALMING] = 0x1F926,
    [UC_TURTLE] = 0x1F422,
    [UC_SNAKE] = 0x1F40D,
    [UC_SPOUTING_WHALE] = 0x1F433,
    [UC_DRAGON] = 0x1F409,
    [UC_TREX] = 0x1F996,
    [UC_ARGENTINA_A] = 0x1F1E6,
    [UC_ARGENTINA_R] = 0x1F1F7,
    [UC_THUMBSDOWN] = 0x1F44E,
    [UC_THUMBSUP] = 0x1F44D,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Base Layer: QWERTY

    [_QWERTY] = LAYOUT(
      KC_ESC ,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P , KC_BSPC,
      SFT_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, SFT_QUO,
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_CAPS, KC_PSCR,    FUNC, QK_LEAD,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LCTL,
                                 KC_LGUI, KC_LALT,     SYM,  KC_SPC, NUM_ENT, SFT_SFT,  KC_SPC,     NAV, KC_BSPC, KC_DEL
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
                                 _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT
    ),

//  Layer: Number

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_ASTR,    KC_4,    KC_5,    KC_6,  KC_DOT, KC_PLUS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_0,    KC_1,    KC_2,    KC_3,  KC_EQL, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  Layer: Function

    [_FUNCTION] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// Adjust Layer: Music, Locks

    [_ADJUST] = LAYOUT(
      _______, _______, _______, KC_VOLU, _______, _______,                                     UM(UC_THUMBSUP),    UM(UC_FACE_SYMBOLS_MOUTH), UM(UC_SMIRKING_FACE),     UM(UC_ZANY_FACE),                UM(UC_WINKING_FACE),      _______,
      _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,                                     UM(UC_WAVING_HAND), UM(UC_GRINNING_FACE),      UM(UC_BEAMING_FACE),      UM(UC_GRINNING_FACE_WITH_SWEAT), UM(UC_FACE_TEARS_JOY),    _______,
      _______, _______, _______, KC_MPLY, KC_MUTE, _______, _______, _______, _______, _______, UM(UC_THUMBSDOWN),  UM(UC_LOUDLY_CRYING_FACE), UM(UC_FACE_ROLLING_EYES), UM(UC_FACE_RAISED_EYEBROW),      UM(UC_DISAPPOINTED_FACE), _______,
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
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {

        oled_write_P(PSTR("Layer: "), false);
        
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n\n"), false);
                oled_write_P(PSTR("q w e r t  y u i o p\n"), false);
                oled_write_P(PSTR("a s d f g  h j k l ;\n"), false);
                oled_write_P(PSTR("z x c v b  n m , . /\n"), false);
                break;
            
            case _NAV:
                oled_write_P(PSTR("Navigation\n\n"), false);
                oled_write_P(PSTR(". b t d up . . . . .\n"), false);
                oled_write_P(PSTR(". < ^ > dn . S C A G\n"), false);
                oled_write_P(PSTR(". h v e .  . . . . .\n"), false);
                break;
            
            case _SYMBOL:
                oled_write_P(PSTR("Symbol\n\n"), false);
                oled_write_P(PSTR("@ _ [ ] ^  ! < > = &\n"), false);
                oled_write_P(PSTR("\\ / { } *  ? ( ) - :\n"), false);
                oled_write_P(PSTR("# $ | ~ `  + % \" ' ;\n"), false);
                break;
            
            case _NUM:
                oled_write_P(PSTR("Number\n\n"), false);
                oled_write_P(PSTR(". . . . .  / 7 8 9 -\n"), false);
                oled_write_P(PSTR("G A C S .  * 4 5 6 ,\n"), false);
                oled_write_P(PSTR(". . . . .  0 1 2 3 =\n"), false);
                break;
            
            case _FUNCTION:
                oled_write_P(PSTR("Function\n\n"), false);
                oled_write_P(PSTR(". . . . .  . 7 8 9 0\n"), false);
                oled_write_P(PSTR("G A C S .  . 4 5 6 1\n"), false);
                oled_write_P(PSTR(". . . . .  . 1 2 3 2\n"), false);
                break;
            
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n\n"), false);
                oled_write_P(PSTR(". . ^ . .  e e e e e\n"), false);
                oled_write_P(PSTR(".<< v >>.  e e e e e\n"), false);
                oled_write_P(PSTR(". . p m .  e e e e e\n"), false);
                break;
            
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("\nNUM ") : PSTR("\n    "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    }
    return false;
}
#endif

