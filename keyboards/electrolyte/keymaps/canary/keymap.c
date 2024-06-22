#include QMK_KEYBOARD_H

enum layers_names {
  _CANARY,
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
#define RCTLI MT(MOD_LCTL, KC_I)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRAS LT(_EXTRAS, KC_TAB)
#define WIN_L C(KC_LEFT)
#define WIN_R C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CANARY] = LAYOUT(
  KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,    KC_Z,    KC_F,   KC_O,     KC_U,   KC_BSPC,
  KC_C,    LCTLR,   LALTS,   LSFTT,   LGUIG,   RGUIM,   RSFTN,  RALTE,    RCTLI,  KC_A,
  KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,    KC_X,    KC_H,   KC_COMM,  KC_DOT, KC_ENT,
  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_LSFT, KC_SPC,  RAISE,  EXTRAS,   WIN_L,  WIN_R
),

[_LOWER] = LAYOUT(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  XXXXXXX, XXXXXXX, KC_PLUS, KC_UNDS, KC_QUES, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  KC_MPLY, KC_MPRV, KC_MNXT, KC_PIPE, KC_TILD, KC_DQUO, KC_COLN, KC_LCBR, KC_RCBR, KC_ESC,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  XXXXXXX, XXXXXXX, KC_EQL,  KC_MINS,  KC_SLSH, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS,  KC_GRV,  KC_QUOT, KC_SCLN, KC_LBRC, KC_RBRC, KC_ESC,
  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
),

[_EXTRAS] = LAYOUT(
  KC_PLUS, KC_7, KC_8, KC_9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   _______,
  KC_MINS, KC_4, KC_5, KC_6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   _______,
  KC_ASTR, KC_1, KC_2, KC_3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   _______,
  KC_SLSH, KC_0, KC_0, KC_DOT, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______,   _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
