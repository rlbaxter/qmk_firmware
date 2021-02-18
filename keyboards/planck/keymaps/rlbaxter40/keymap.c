/* Copyright 2015-2017 Jack Humbert
 *
 * Planck 38 key layout for rlbaxter
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
#include "muse.h"

bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;
bool is_cmd_sft_tab_active = false;
uint16_t cmd_sft_tab_timer = 0;

enum custom_keycodes {
  CMD_TAB = SAFE_RANGE,
  CMD_SFT_TAB,
  WIN_L,
  WIN_R,
  BTAB_L,
  BTAB_R
};

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _EXTRAS
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRAS LT(_EXTRAS, KC_SPC)
#define A_SFT MT(MOD_LSFT, KC_A)
#define SC_SFT MT(MOD_RSFT, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,        KC_P,    XXXXXXX,
  XXXXXXX, A_SFT,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,     KC_L,        SC_SFT,  XXXXXXX,
  XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,      KC_ENT,  XXXXXXX,
  XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   EXTRAS,  KC_SPC,  RAISE,  KC_BSPC,  CMD_SFT_TAB, CMD_TAB, XXXXXXX
),

[_LOWER] = LAYOUT_planck_grid(
  XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
  XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_DQUO, KC_QUES, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, KC_PIPE, XXXXXXX, _______, XXXXXXX,
  XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, BTAB_L,  BTAB_R, XXXXXXX
),

[_RAISE] = LAYOUT_planck_grid(
  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOT, KC_SLSH, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_GRV,  KC_BSLS, XXXXXXX, _______, XXXXXXX,
  XXXXXXX, _______, _______, _______, _______,  _______, _______, _______, _______, WIN_L,   WIN_R,   XXXXXXX
),

[_ADJUST] = LAYOUT_planck_grid(
  XXXXXXX, RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL, XXXXXXX,
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, XXXXXXX,
  XXXXXXX, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  AU_ON,   AU_OFF,  KC_F11,  KC_F12, XXXXXXX,
  XXXXXXX, MU_MOD, _______,  _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

[_EXTRAS] = LAYOUT_planck_grid(
  XXXXXXX,  KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS, KC_P7,   KC_P8,   KC_P9,   KC_BSPC, XXXXXXX,
  XXXXXXX,  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, _______, _______, _______, KC_PSLS, KC_P0,   KC_PDOT, KC_PEQL, XXXXXXX, XXXXXXX
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_TAB:
      if (record->event.pressed) {
        if (!is_cmd_tab_active) {
          is_cmd_tab_active = true;
          register_code(KC_LGUI);
        }
        cmd_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case CMD_SFT_TAB:
      if (record->event.pressed) {
        if (!is_cmd_sft_tab_active) {
          is_cmd_sft_tab_active = true;
          register_code(KC_LGUI);
          register_code(KC_LSFT);
        }
        cmd_sft_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case WIN_L:
      if (record->event.pressed) {
        register_code16(C(KC_LEFT));
      } else {
        unregister_code16(C(KC_LEFT));
      }
      break;
    case WIN_R:
      if (record->event.pressed) {
        register_code16(C(KC_RGHT));
      } else {
        unregister_code16(C(KC_RGHT));
      }
      break;
    case BTAB_L:
      if (record->event.pressed) {
        register_code16(G(A(KC_LEFT)));
      } else {
        unregister_code16(G(A(KC_LEFT)));
      }
      break;
    case BTAB_R:
      if (record->event.pressed) {
        register_code16(G(A(KC_RIGHT)));
      } else {
        unregister_code16(G(A(KC_RIGHT)));
      }
      break;
    }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_cmd_tab_active = false;
    }
  }
  if (is_cmd_sft_tab_active) {
    if (timer_elapsed(cmd_sft_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      unregister_code(KC_LSFT);
      is_cmd_sft_tab_active = false;
    }
  }
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
