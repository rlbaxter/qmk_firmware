#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, 
		KC_U, KC_I, KC_O, KC_P, MT(MOD_LSFT, KC_A), KC_S, 
		KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, 
		MT(MOD_LSFT, KC_L), LT(1, KC_ENT), LT(3, KC_Z), MT(MOD_LCTL, KC_X), MT(MOD_LALT, KC_C), MT(MOD_LGUI, KC_V), 
		KC_BSPC, KC_SPC, MT(MOD_LGUI, KC_B), MT(MOD_LALT, KC_N), MT(MOD_LCTL, KC_M), LT(2, KC_ESC)
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, 
		KC_7, KC_8, KC_9, KC_0, KC_TAB, KC_BSLS, 
		KC_GRV, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_SCLN, 
		KC_QUOT, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, 
		KC_BSPC, KC_SPC, KC_COMM, KC_DOT, KC_SLSH, KC_NO
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, 
		KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TAB, KC_PIPE, 
		KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_COLN, 
		KC_DQUO, KC_NO, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, 
		KC_BSPC, KC_SPC, KC_LABK, KC_RABK, KC_QUES, KC_NO
  ),

  [3] = LAYOUT_ortho_3x10(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, 
		KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
		KC_F13, KC_F14, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_UP, KC_NO, KC_NO, RESET, KC_NO, KC_NO, 
		KC_BSPC, KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT
  )

};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}
