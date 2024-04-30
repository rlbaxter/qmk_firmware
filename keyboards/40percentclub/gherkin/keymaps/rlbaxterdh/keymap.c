/*
 * Gherkin colemak dh layout for rlbaxter
 */
#include QMK_KEYBOARD_H

enum layer_names {
  _COLEMAK,
  _RAISE,
  _LOWER,
  _ADJUST,
};

#define LCTLR MT(MOD_LCTL, KC_R)
#define LALTS MT(MOD_LALT, KC_S)
#define LSFTT MT(MOD_LSFT, KC_T)
#define LGUIG MT(MOD_LGUI, KC_G)
#define RGUIM MT(MOD_RGUI, KC_M)
#define RSFTN MT(MOD_RSFT, KC_N)
#define RALTE MT(MOD_LALT, KC_E)
#define RCTLI MT(MOD_LCTL, KC_I)
#define RAISE LT(_RAISE, KC_O)
#define LOWER LT(_LOWER, KC_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_ortho_3x10(
    KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,  KC_J,  KC_L,  KC_U,    KC_Y,   KC_BSPC,
    LOWER, LCTLR, LALTS, LSFTT, LGUIG, RGUIM, RSFTN, RALTE,   RCTLI,  RAISE,
    KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,  KC_K,  KC_H,  KC_COMM, KC_DOT, KC_ENT
  ),

  [_RAISE] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, KC_EQL,  KC_MINS, KC_SLSH, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
    KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, KC_GRV,  KC_QUOT, KC_SCLN, KC_LBRC, KC_RBRC, KC_ESC
  ),

  [_LOWER] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    _______, _______, KC_PLUS, KC_UNDS, KC_QUES, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
    KC_MPLY, KC_MPRV, KC_MNXT, KC_PIPE, KC_TILD, KC_DQUO, KC_COLN, KC_LCBR, KC_RCBR, KC_ESC
  ),

  [_ADJUST] = LAYOUT_ortho_3x10(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

const uint16_t PROGMEM kl_space[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM hl_tab[] = {KC_H, KC_L, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(kl_space, KC_SPC),
    COMBO(hl_tab, KC_TAB),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
