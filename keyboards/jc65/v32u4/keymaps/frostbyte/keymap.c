#include "v32u4.h"

#define _BASE 0
#define _NAV 1
#define _FN 2
#define _GAMING 3

#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = KEYMAP(
      KC_ESC,   KC_1,    KC_2,     KC_3,       KC_4,     KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_BSLS, KC_BSLS, KC_INS,
      KC_TAB,   KC_Q,    KC_W,     KC_E,       KC_R,     KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSPC,          KC_DEL,
      MO(_NAV), KC_A,    KC_S,     KC_D,       KC_F,     KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, KC_ENT,                    KC_PGUP,
      KC_LSFT,  KC_NUBS, KC_Z,     KC_X,       KC_C,     KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, KC_UP,            MO(_FN),
      KC_LCTL,  KC_LGUI, KC_LALT,  KC_SPACE,             KC_SPACE,          KC_SPACE,         KC_RALT, KC_RGUI,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
      ),
  [_NAV] = KEYMAP(
      ______,   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,       KC_F6,   KC_F7,      KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  LCTL(KC_GRV),  LCTL(KC_GRV), ______,
      ______,  LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E), LCTL(KC_R), ______,      ______,  KC_HOME,    KC_UP,   KC_END,  ______,   KC_GRV,  KC_TILD, KC_DEL,                      ______,
      ______,  LCTL(KC_A), LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), ______,      ______,  KC_LEFT,    KC_DOWN, KC_RGHT, ______,   ______,  KC_CAPS,                              ______,
      ______,  ______,     LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),  ______,  LCTL(KC_N), ______,  ______,  ______,   ______,  ______,  ______,                      ______,
      ______,  ______,     ______,     ______,                 ______,               ______,              ______,  ______,   ______,  ______,  ______,        ______
      ),
  [_FN] = KEYMAP(
      ______,  MO(_GAMING), ______, ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,  ______,  ______,  ______, RESET,
      ______,  BL_TOGG,     BL_STEP, BL_DEC,  BL_INC,  ______,  ______,  ______,  ______,  ______,  ______,   ______,  ______,  ______,          ______,
      ______,  RGB_TOG,     RGB_MOD, ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,  ______,                   ______,
      ______,  ______,      RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______,  ______,  ______,   ______,  ______,  ______,          ______,
      ______,  ______,      ______,  ______,           ______,           ______,           ______,  ______,   ______,  ______,  ______,  ______
      ),
  [_GAMING] = KEYMAP(
      ______,  ______, ______, ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______,  ______, ______,
      ______,  ______, ______, ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______,          ______,
      KC_LCTL, ______, ______, ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,                   ______,
      ______,  ______, ______, ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______,          ______,
      ______,  ______, ______, ______,         ______,         ______,          ______,  ______,  ______,  ______,  ______,  ______
      ),
};
