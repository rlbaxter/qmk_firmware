/* Copyright 2017 Wunder
 *
 * XD75 layout for rlbaxter
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

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define WIN_L C(KC_LEFT)
#define WIN_R C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, KC_H,    KC_J,   KC_K,     KC_L,    KC_BSPC,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_ENT,
  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_LSFT, XXXXXXX, KC_PLUS, KC_0,    KC_DOT,  XXXXXXX, KC_SPC,  RAISE,  KC_TAB,   WIN_L,   WIN_R
),

[_LOWER] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  XXXXXXX, XXXXXXX, KC_PLUS, KC_UNDS, KC_QUES, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DQUO, KC_COLN, KC_LCBR, KC_RCBR, KC_ESC,
  _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT
),

[_RAISE] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  XXXXXXX, XXXXXXX, KC_EQL,  KC_MINS, KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, KC_SCLN, KC_LBRC, KC_RBRC, KC_ESC,
  _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU
),

[_ADJUST] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}