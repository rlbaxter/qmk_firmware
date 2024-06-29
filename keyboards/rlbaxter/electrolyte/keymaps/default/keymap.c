/*
Copyright 2024 rlbaxter

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers_names {
  _QWERTY,
  _RAISE,
  _LOWER,
  _ADJUST,
  _EXTRAS
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define EXTRAS LT(_EXTRAS, KC_TAB)
#define WIN_L C(KC_LEFT)
#define WIN_R C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x10(
  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,    KC_J,  KC_K,    KC_L,   KC_BSPC,
  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT, KC_ENT,
  KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_LSFT, RAISE, EXTRAS,  WIN_L,  WIN_R
),

[_RAISE] = LAYOUT_ortho_4x10(
  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  XXXXXXX, XXXXXXX, KC_EQL,  KC_MINS,  KC_SLSH, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_DEL,
  KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS,  KC_GRV,  KC_QUOT, KC_SCLN, KC_LBRC, KC_RBRC, KC_ESC,
  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_ortho_4x10(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  XXXXXXX, XXXXXXX, KC_PLUS, KC_UNDS, KC_QUES, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR,
  KC_MPLY, KC_MPRV, KC_MNXT, KC_PIPE, KC_TILD, KC_DQUO, KC_COLN, KC_LCBR, KC_RCBR, KC_ESC,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_ortho_4x10(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
),

[_EXTRAS] = LAYOUT_ortho_4x10(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_7,    KC_8, KC_9,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_4,    KC_5, KC_6,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR, KC_1,    KC_2, KC_3,
  _______, _______, _______, _______, _______, _______, KC_SLSH, _______, KC_0, KC_DOT
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}