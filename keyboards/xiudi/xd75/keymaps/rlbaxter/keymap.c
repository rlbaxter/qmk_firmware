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

enum layers_names {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

#define LCTLS MT(MOD_LCTL, KC_S)
#define LALTD MT(MOD_LALT, KC_D)
#define LSFTF MT(MOD_LSFT, KC_F)
#define LGUIG MT(MOD_LGUI, KC_G)
#define RGUIH MT(MOD_RGUI, KC_H)
#define RSFTJ MT(MOD_RSFT, KC_J)
#define RALTK MT(MOD_LALT, KC_K)
#define RCTLL MT(MOD_LCTL, KC_L)

#define LCTLR MT(MOD_LCTL, KC_R)
#define LALTS MT(MOD_LALT, KC_S)
#define LSFTT MT(MOD_LSFT, KC_T)
// #define LGUIG MT(MOD_LGUI, KC_G)
#define RGUIM MT(MOD_RGUI, KC_M)
#define RSFTN MT(MOD_RSFT, KC_N)
#define RALTE MT(MOD_LALT, KC_E)
#define RCTLI MT(MOD_LCTL, KC_I)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define WIN_L C(KC_LEFT)
#define WIN_R C(KC_RIGHT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, KC_Y,    KC_U,   KC_I,     KC_O,   KC_P,
  KC_A,    LCTLS,   LALTD,   LSFTF,   LGUIG,   XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, RGUIH,   RSFTJ,  RALTK,    RCTLL,  KC_BSPC,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_ENT,
  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_LSFT, XXXXXXX, KC_PLUS, KC_0,    KC_DOT,  XXXXXXX, KC_SPC,  RAISE,  KC_TAB,   WIN_L,  WIN_R
),

[_COLEMAK] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, KC_J,    KC_L,   KC_U,     KC_Y,   KC_BSPC,
  KC_A,    LCTLR,   LALTS,   LSFTT,   LGUIG,   XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, RGUIM,   RSFTN,  RALTE,    RCTLI,  KC_O,
  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, KC_K,    KC_H,   KC_COMM,  KC_DOT, KC_ENT,
  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_LSFT, XXXXXXX, KC_PLUS, KC_0,    KC_DOT,  XXXXXXX, KC_SPC,  RAISE,  KC_TAB,   WIN_L,  WIN_R
),

[_RAISE] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  XXXXXXX, XXXXXXX, KC_EQL,  KC_MINS,  KC_SLSH, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS,  KC_GRV,  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   XXXXXXX, KC_QUOT, KC_SCLN, KC_LBRC, KC_RBRC, KC_ESC,
  _______, _______, _______, _______,  _______, XXXXXXX, KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  XXXXXXX, XXXXXXX, KC_PLUS, KC_UNDS, KC_QUES, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  KC_MPLY, KC_MPRV, KC_MNXT, KC_PIPE, KC_TILD, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   XXXXXXX, KC_DQUO, KC_COLN, KC_LCBR, KC_RCBR, KC_ESC,
  _______, _______, _______, _______, _______, XXXXXXX, KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,  COLEMAK, XXXXXXX, QK_BOOT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  }
  return true;
}
