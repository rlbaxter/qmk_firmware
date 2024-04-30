/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _EXTRAS
};

#define LCTLR MT(MOD_LCTL, KC_R)
#define LALTS MT(MOD_LALT, KC_S)
#define LSFTT MT(MOD_LSFT, KC_T)
#define LGUIG MT(MOD_LGUI, KC_G)
#define RGUIM MT(MOD_RGUI, KC_M)
#define RSFTN MT(MOD_RSFT, KC_N)
#define RALTE MT(MOD_LALT, KC_E)
#define RCTLI MT(MOD_LCTL, KC_Io


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRAS LT(_EXTRAS, KC_TAB)
#define WIN_L C(KC_LEFT)
#define WIN_R C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_planck_grid(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    XXXXXXX, XXXXXXX, KC_J,    KC_L,   KC_U,     KC_Y,   KC_BSPC,
  KC_A,    LCTLR,   LALTS,   LSFTT,   LGUIG,   XXXXXXX, XXXXXXX, RGUIM,   RSFTN,  RALTE,    RCTLI,  KC_O,
  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, XXXXXXX, KC_K,    KC_H,   KC_COMM,  KC_DOT, KC_ENT,
  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_LSFT, XXXXXXX, XXXXXXX, KC_SPC,  RAISE,  EXTRAS,   WIN_L,  WIN_R
),

[_RAISE] = LAYOUT_planck_grid(
  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  XXXXXXX, XXXXXXX, KC_EQL,  KC_MINS,  KC_SLSH, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS,  KC_GRV,  XXXXXXX, XXXXXXX, KC_QUOT, KC_SCLN, KC_LBRC, KC_RBRC, KC_ESC,
  _______, _______, _______, _______,  _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_planck_grid(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  XXXXXXX, XXXXXXX, KC_PLUS, KC_UNDS, KC_QUES, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  KC_MPLY, KC_MPRV, KC_MNXT, KC_PIPE, KC_TILD, XXXXXXX, XXXXXXX, KC_DQUO, KC_COLN, KC_LCBR, KC_RCBR, KC_ESC,
  _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
  QK_BOOT, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   XXXXXXX, XXXXXXX, MI_OFF,  AU_ON,   AU_OFF,  KC_F11,  KC_F12,
  MU_MOD, _______,  _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX
),

[_EXTRAS] = LAYOUT_planck_grid(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_P7,   KC_P8,   KC_P9,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS, KC_P4,   KC_P5,   KC_P6,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_P1,   KC_P2,   KC_P3,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, _______, KC_P0,   KC_PDOT
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
