/* Copyright 2020 tominabox1
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
  _RAISE,
  _LOWER,
  _ADJUST
};

#define LCTLS MT(MOD_LCTL, KC_S)
#define LALTD MT(MOD_LALT, KC_D)
#define LSFTF MT(MOD_LSFT, KC_F)
#define LGUIG MT(MOD_LGUI, KC_G)
#define RGUIH MT(MOD_RGUI, KC_H)
#define RSFTJ MT(MOD_RSFT, KC_J)
#define RALTK MT(MOD_LALT, KC_K)
#define RCTLL MT(MOD_LCTL, KC_L)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


int current_wpm = 0;
uint8_t current_frame = 2; // starts with eye closed
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
int frameDuration = 200;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MUTE, KC_Y,    KC_U,   KC_I,     KC_O,   KC_P,
        KC_A,    LCTLS,   LALTD,   LSFTF,   LGUIG,            RGUIH,   RSFTJ,  RALTK,    RCTLL,  KC_BSPC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_ENT,
                                   LOWER,   KC_LSFT,          KC_SPC,  RAISE
    ),

    [_RAISE] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  XXXXXXX, KC_EQL,  KC_MINS,  KC_SLSH,          KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,  KC_GRV,           KC_QUOT, KC_SCLN, KC_LBRC, KC_RBRC, KC_ESC,
                                   _______,  _______,          _______, _______
    ),

    [_LOWER] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_TAB,  XXXXXXX, KC_PLUS, KC_UNDS, KC_QUES,          KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
        KC_MPLY, KC_MPRV, KC_MNXT, KC_PIPE, KC_TILD,          KC_DQUO, KC_COLN, KC_LCBR, KC_RCBR, KC_ESC,
                                   _______, _______,          _______, _______
    ),

    [_ADJUST] = LAYOUT(
        RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,
                                   _______, _______,          _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
            if (record->event.pressed) {
                current_frame = 1; // make it blink
            }
            break;
    }
    return true;
}

#ifdef OLED_ENABLE  //Special thanks to Sickbabies for this great OLED widget!
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;  // rotates for proper orientation
}

// genearted sprites using instructions found here:
// https://docs.splitkb.com/hc/en-us/articles/360013811280-How-do-I-convert-an-image-for-use-on-an-OLED-display-
// https://javl.github.io/image2cpp/
static const char PROGMEM eye_open[96] = {
    0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x10, 0x98, 0x68, 0x1c, 0x0c, 0x0c, 0x06, 0x06, 0x06,
    0x06, 0x86, 0x06, 0x0c, 0x1c, 0x3c, 0x68, 0x98, 0x30, 0x20, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x0f, 0x19, 0x30, 0x60, 0xc0, 0x80, 0xbf, 0x60, 0x80, 0x00, 0x00, 0x18, 0x18, 0x3c,
    0x1e, 0x1f, 0x0f, 0x00, 0x80, 0xc0, 0x60, 0x9f, 0xc0, 0x40, 0x60, 0x30, 0x19, 0x0f, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const char PROGMEM eye_mid[96] = {
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0xe0, 0x60, 0x20, 0x20, 0x30, 0x30, 0x10, 0x10,
    0x10, 0x90, 0xb0, 0x30, 0x20, 0x20, 0x60, 0xe0, 0x40, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x06, 0x0f, 0x09, 0x18, 0x10, 0x30, 0x3f, 0x60, 0x60, 0x40, 0x44, 0x4c, 0x5c, 0x5c,
    0x5e, 0x5f, 0x4f, 0x40, 0x40, 0x60, 0x70, 0x3f, 0x30, 0x10, 0x18, 0x09, 0x0f, 0x06, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM eye_close[96] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void render_eye(void) {

    // animation
    void animation_phase(void) {
        oled_set_cursor(0,7);
        switch (current_frame) {
            case 1:
            case 3:
                oled_write_raw_P(eye_mid, 96);
                break;
            case 2:
                oled_write_raw_P(eye_close, 96);
                break;
            default:
                oled_write_raw_P(eye_open, 96);

        }
        if (current_frame > 50) {
            // gotta blink every once and a while
            current_frame = 1;
        } else {
            current_frame++;
        }
    }

    // animation timer
    if(timer_elapsed32(anim_timer) > frameDuration) {
        anim_timer = timer_read32();
        current_wpm = get_current_wpm();
        animation_phase();
    }

    // this fixes the screen on and off bug
    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }

}

bool oled_task_user(void) {
    render_eye();
    return false;
}
#endif
