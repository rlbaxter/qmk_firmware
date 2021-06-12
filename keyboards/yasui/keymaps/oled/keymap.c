/* Copyright 2021 Regan Palmer
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
#include "yasui.h"

enum layers_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _EXTRAS
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRAS LT(_EXTRAS, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,   KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,     KC_L,   KC_BSPC,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_ENT,
  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_LSFT, KC_SPC,  RAISE,  EXTRAS,   XXXXXXX, XXXXXXX
),

[_LOWER] = KEYMAP(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  XXXXXXX, KC_MPLY, KC_PLUS, KC_UNDS, KC_QUES, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  XXXXXXX, KC_MPRV, KC_MNXT, KC_PIPE, KC_TILD, KC_DQUO, KC_COLN, KC_LCBR, KC_RCBR, KC_ESC,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
),

[_RAISE] = KEYMAP(
  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  XXXXXXX, KC_MUTE, KC_EQL,  KC_MINS,  KC_SLSH, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  XXXXXXX, KC_VOLD, KC_VOLU, KC_BSLS,  KC_GRV,  KC_QUOT, KC_SCLN, KC_LBRC, KC_RBRC, KC_ESC,
  _______, _______, _______, _______,  _______, _______, _______, _______, XXXXXXX, XXXXXXX
),

[_ADJUST] = KEYMAP(
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
),

[_EXTRAS] = KEYMAP(
  KC_PPLS, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_PMNS, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_PAST, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_P0,   KC_PDOT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, _______, XXXXXXX, XXXXXXX
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
        case 0:
             if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
            break;
        case 1:
            if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
            break;
		case 2:
			if (clockwise) {
            tap_code(KC_MS_WH_RIGHT);
        } else {
            tap_code(KC_MS_WH_LEFT);
        }
			break;
        case 3:
             if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
            break;
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {return OLED_ROTATION_180;}

char wpm[10];

void oled_task_user(void) {
    sprintf(wpm, "WPM: %03d", get_current_wpm());

    // Host Keyboard Layer Status
    oled_write_P(PSTR("       yasui \n"), false);
    oled_write_P(PSTR(" Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _EXTRAS:
            oled_write_P(PSTR("Extras\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    oled_write_P(PSTR(" "), false);
    oled_write(wpm, false);
}
