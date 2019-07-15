/*
 * The Deft layout for the Let's Split Keyboard
 * Deft Version 1.1
 *
 * A keyboard layout designed for efficiency in programming and transferability between ortholinear boards.
 * Deft is currently supported on the following boards:
 * Planck (12x4)
 * Let's Split (12x4 split)
 * CRKBD (Corne) (Helidox)
 *
 * Coming soon to:
 * Ergodoxs
 * XD75
 * Collide39
 * Helix
 * HelixPico
 * BFO-9000
 * Sol 2
 * Miuni32
 *
 * The Deft keyboard layout was designed by Michael Speiser. You can find other Deft layouts at my Github:
 * https://github.com/Speiserm
 *
 * A keymap overview and changelog should be available in the repo you got this software from, or at my repo, listed above.
 *
 * For questions, issues, or feedback, feel free to email me at Speiserm@pm.me.
 *s
 *
 * Flashing:
 *
 * make lets_split:deft:dfu
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Follow my cat:
 * https://twitter.com/BuchaTheCat
 * https://www.instagram.com/BuchaTheCat/
 *
 */

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.  ,-----------------------------------------.
 * | Esc  |  Q   |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Tab  |  A   |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |Shift |  Z   |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |  Up  |  /   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Copy |Lower |Space |  |Enter |Raise | Alt  | Left | Down |Right |
 * `-----------------------------------------'  `-----------------------------------------'
*/
[_QWERTY] = LAYOUT_ortho_4x12( \
   KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, \
   KC_LCTL, KC_LALT, KC_LGUI, C(KC_C),   LOWER,  KC_SPC,  KC_ENT,   RAISE,   KC_RALT, KC_LEFT, KC_DOWN,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------.  ,-----------------------------------------.
 * | Del  | Alt1 | Alt2 | Alt3 | Alt4 |  (   |  |  )   |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  `   |  \   |  =   |  -   |  <   |  |  >   |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |  [   |  |  ]   |      |      |      | Pgup |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |Paste |      |      |  |      |      |      | Home | Pgdn | End  |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_DEL, A(KC_1), A(KC_2), A(KC_3), A(KC_4), S(KC_9), S(KC_0), _______, _______, _______, _______, _______, \
  _______,  KC_GRV,KC_BSLS,KC_EQL, KC_MINS,S(KC_COMM),S(KC_DOT), _______, _______,  _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, KC_PGUP, _______, \
  _______, _______, _______, C(KC_V), _______, _______, _______, _______, _______, KC_HOME,KC_PGDOWN, KC_END \
),

/* Raise
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      | F11  | F12  | F13  | F14  | F15  |  | F16  | F17  | F18  | F19  | Vol+ |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      | Cut  |      |      |  |      |      |      | Play | Vol- | Next |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______, \
  _______,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19, KC_VOLU, _______, \
  _______, _______, _______, C(KC_X), _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_MNXT \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |Reset |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
