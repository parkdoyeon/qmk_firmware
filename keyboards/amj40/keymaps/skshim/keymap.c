

// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "amj40.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _VIMKEY 4
#define _ENTKEY 5
#define _OVERWATCH 6 


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  VIMKEY,
  ENTKEY,
  OVERWATCH
};

enum layer_names {
  LAYER_LOWER = 0,
  LAYER_RAISE,
  LAYER_ADJUST,
  LAYER_VIMKEY,
  LAYER_ENTKEY,
};


const uint16_t PROGMEM fn_actions[] = {
	[LAYER_LOWER]  = ACTION_LAYER_TAP_KEY(_LOWER, KC_SPC),
	[LAYER_RAISE]  = ACTION_LAYER_TAP_KEY(_RAISE, KC_SPC),
	[LAYER_ADJUST]  = ACTION_LAYER_TAP_KEY(_ADJUST, KC_SPC),
	[LAYER_VIMKEY]  = ACTION_LAYER_TAP_KEY(_VIMKEY, KC_TAB),
	[LAYER_ENTKEY]  = ACTION_LAYER_TAP_KEY(_ENTKEY, KC_ENT)
}; 

/*
enum tap_dances {
  TD_COMM = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_COMM]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SLSH)
};
*/

// increase readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        /* Default Layer
     * ,-----------------------------------------------------------.
     * | Esc|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS |
     * |-----------------------------------------------------------|
     * | Tab |  A |  S |  D |  F |  G |  H |  J |  K |  L | Ent    |
     * |-----------------------------------------------------------|
     * | LSft   |  Z |  X |  C |  V |  B |  N |  M |  , | . | RSft |
     * |-----------------------------------------------------------|
     * | LCtl | LGui| LAlt|  spc fn0  |  spc fn1    |fn2|RCtl|Toggle |
     * `-----------------------------------------------------------'
     */
    [_QWERTY] = KEYMAP( \
        KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,   KC_BSPC,\
		F(LAYER_VIMKEY),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    F(LAYER_ENTKEY),\
        KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_RSFT,\
        KC_LCTL, KC_LGUI, KC_LALT,          F(LAYER_LOWER),           F(LAYER_RAISE),        F(LAYER_ADJUST), KC_RCTL, TG(6) \
		),

    /* Function Layer 1 HHKB style
     * ,-----------------------------------------------------------.
     * |  F1 | F2 | F3 |F4 |F5|F6 | F7 | F8 | F9 | F10 | F11 | F12 |
     * |-----------------------------------------------------------|
     * |   1    |  2 |  3 | 4  | 5  |  6 |  7 |  8 |  9 |  0 |  -  |
     * |-----------------------------------------------------------|
     * |   LSft  |    |   |   |   |  | LT | LD | LI |     |RSft    |
     * |-----------------------------------------------------------|
     * |LCtl | LGui |LAlt |           |  Space    |     |    |     |
     * `-----------------------------------------------------------'
     */
    [_LOWER] = KEYMAP( \
        KC_F1, KC_F2, KC_F3,   KC_F4, KC_F5,  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
		KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7, KC_8, KC_9, KC_0, KC_MINS, \
		KC_LSFT,   _______,   _______,   _______,  _______,  _______,BL_TOGG,BL_DEC,BL_INC, KC_TRNS, KC_RSFT, \
		KC_LCTL, KC_LGUI, KC_LALT, _______, KC_SPC, _______, RESET, _______ \
		),

	/* Function Layer 2 HHKB style
     * ,-----------------------------------------------------------.
     * | ~  |   |    |   |    |    |   | -  | =   |  [  |  ]  |  \ |
     * |-----------------------------------------------------------|
     * |      | | | " | _  | +  |    |    |    |  { |   } |  Enter |
     * |-----------------------------------------------------------|
     * |  LSft  |    |    |    |     |   |   | ,  | .  | /   | Rsft|
     * |-----------------------------------------------------------|
     * | LCtl| LGui| LAlt | Space     |             |   |   |      |
     * `-----------------------------------------------------------'
     */
    [_RAISE] = KEYMAP( \
        LSFT(KC_GRV),  _______,    _______,    _______,    _______,    _______,    _______,    KC_MINS,    KC_EQL,    KC_LBRC,    KC_RBRC,    KC_BSLS, \
		_______,  LSFT(KC_BSLS), LSFT(KC_QUOT), LSFT(KC_MINS) , LSFT(KC_EQL) , _______,   _______, _______,  LSFT(KC_LBRC), LSFT(KC_RBRC), KC_ENT, \
		KC_LSFT,   _______,   _______,   _______,  _______,  _______,  _______, KC_COMM, KC_DOT, KC_SLSH, LSFT(KC_SLSH), \
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_TRNS, _______, _______, _______ \
		),

	/* Function Layer 3 HHKB style
     * ,-----------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |  U |     |   |    |
     * |-----------------------------------------------------------|
     * |      |    |    |    |    |    |    |  L |  D | R  |       |
     * |-----------------------------------------------------------|
     * |        |    |   |    |    |    |    |    |     |     |    |
     * |-----------------------------------------------------------|
     * |     |    |     |           |             |     |    |     |
     * `-----------------------------------------------------------'
     */
    [_ADJUST] = KEYMAP( \
        XXXXXXX, KC_WH_U,   KC_MS_U, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_UP, KC_ACL1, KC_ACL2, KC_DEL, \
		XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R,   XXXXXXX,  XXXXXXX, KC_BTN2, KC_LEFT, KC_DOWN, KC_RGHT,  XXXXXXX,  \
		XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R,  XXXXXXX,  XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,  XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, XXXXXXX, _______, XXXXXXX, KC_TRNS \
		),

	/* Function Layer 4 VIM key style
     * ,-----------------------------------------------------------.
     * |  ~ | !  | @  | #  | $  | %  | ^  | &  |  * |  (  | ) | DEL|
     * |-----------------------------------------------------------|
     * |      | \  | '  | -  | =  |    |  L |  D |  U | R  |       |
     * |-----------------------------------------------------------|
     * |        |    |   |    |    |    |    |    |     |     |    |
     * |-----------------------------------------------------------|
     * |     |    |     |           |             |     |    |     |
     * `-----------------------------------------------------------'
     */
    [_VIMKEY] = KEYMAP( \
        LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),LSFT(KC_6),LSFT(KC_7), LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),  KC_DEL, \
		_______, LCTL(KC_B),  KC_QUOT, KC_MINS , KC_EQL,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  _______,  \
		XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R,  XXXXXXX,  XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,  XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, XXXXXXX, _______, XXXXXXX, KC_TRNS \
		),


	/* Function Layer 5 ENT key style
     * ,-----------------------------------------------------------.
     * |  ` | !  | @  | #  | $  | %  | ^  | &  |  * |  :  | " | DEL|
     * |-----------------------------------------------------------|
     * |      | |  | "  | _  | +  |    |  L |  D |  ; | '  |       |
     * |-----------------------------------------------------------|
     * |        |    |   |    |    |    |    |    |     |     |    |
     * |-----------------------------------------------------------|
     * |     |    |     |           |             |     |    |     |
     * `-----------------------------------------------------------'
     */
    [_ENTKEY] = KEYMAP( \
        KC_GRV, LSFT(KC_1), LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),LSFT(KC_6),LSFT(KC_7), LSFT(KC_8),LSFT(KC_SCLN),LSFT(KC_QUOT),  KC_DEL, \
		_______, KC_BSLS, KC_QUOT, KC_MINS , KC_EQL,  XXXXXXX, KC_LEFT, KC_DOWN, KC_SCLN, KC_QUOT,  _______,  \
		XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R,  XXXXXXX,  XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,  XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, XXXXXXX, _______, XXXXXXX, KC_TRNS \
		),


        /* overwatch Layer
     * ,-----------------------------------------------------------.
     * | Esc|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS |
     * |-----------------------------------------------------------|
     * | Tab |  A |  S |  D |  F |  G |  H |  J |  K |  L | Ent    |
     * |-----------------------------------------------------------|
     * | LSft   |  Z |  X |  C |  V |  B |  N |  M |  , | . | RSft |
     * |-----------------------------------------------------------|
     * | LCtl | LGui| LAlt|  spc      |  spc     |RAlt|RCtl|Toggle |
     * `-----------------------------------------------------------'
     */
    [_OVERWATCH] = KEYMAP( \
        KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,   KC_BSPC,\
		KC_TAB,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_ENT,\
        KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_RSFT,\
        KC_LCTL, KC_LGUI, KC_LALT,         KC_SPC,          KC_SPC,      KC_RALT, KC_RCTL, KC_TRNS \
		),
};




enum function_id {
    LAUNCH,
    RGBLED_TOGGLE,
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
	/*
	if (record->event.pressed) {
		switch(id) {
			case 0 :
				return MACRO(D(ESC),END);
		}
	}
	*/

    return MACRO_NONE;
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
   /*case QWERTY:
      if (record->event.pressed) {
        layer_off(_OVERWATCH);
        breathing_disable();
      }
      return false;
      break;
	*/
	case VIMKEY:
	  if (record->event.pressed) {
        layer_on(_VIMKEY);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_VIMKEY);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }

      return false;
	  break;
	case ENTKEY:
		if (record->event.pressed) {
		  layer_on(_ENTKEY);
		  update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
		  layer_off(_ENTKEY);
		  update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}

		return false;
    	break;

  }
  return true;
}
