
#include "eco.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _NAV 2
#define _RAISE 3
#define _LOWER 4
#define _NUM 5

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-------------------------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | NAV  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  | Enter|  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|  Up  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | NUM  | LOWER| Space| Space| RAISE| Alt  | Gui  | Ctrl | Left | Down | Right|
 * `-------------------------------------------------------------------------------------------------'
 */
[_BASE] = KEYMAP(
  KC_ESC,   KC_Q,    KC_W,    KC_E,     KC_R,       KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
  MO(_NAV), KC_A,    KC_S,    KC_D,     KC_F,       KC_G,   KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_BSLS,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,       KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL,
  KC_LCTL,  KC_LGUI, KC_LALT, MO(_NUM), MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
),

/* NAV
 * ,-------------------------------------------------------------------------------------------------.
 * |      | Ctl+Q| Ctl+W| Ctl+E| Ctl+R|      |      | Home |  Up  |  End |      |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctl+A| Ctl+S| Ctl+D| Ctl+F|      |      | Left | Down | Right|      |      | Caps |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctl+Z| Ctl+X| Ctl+C| Ctl+V|      | Ctl+N|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[_NAV] = KEYMAP(
  _______, LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E), LCTL(KC_R), _______, _______,    KC_HOME, KC_UP,   KC_END,  _______, _______, _______, KC_DEL,
  _______, LCTL(KC_A), LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), _______, _______,    KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_CAPS, _______,
  _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, LCTL(KC_N), _______, _______, _______, _______, _______, _______, _______,
  _______, _______,    _______,    _______,    _______,    _______, _______,    _______, _______, _______, _______, _______, _______, _______
),

/* NUM
 * ,-------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   /  |   7  |   8  |   9  |   -  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   *  |   4  |   5  |   6  |   +  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  | Enter|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   .  |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[_NUM] = KEYMAP(
  _______, _______, _______, _______, _______, _______, KC_PSLS, KC_P7, KC_P8,   KC_P9,   KC_PMNS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_PAST, KC_P4, KC_P5,   KC_P6,   KC_PPLS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2,   KC_P3,   KC_PENT, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_PDOT, _______, _______, _______, _______, _______
),

/* RAISE
 * ,-------------------------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |caltde|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      | RESET|
 * `-------------------------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______,
  CALTDEL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
),

/* LOWER
 * ,-------------------------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |Taskmg|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,
  TSKMGR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

