#include QMK_KEYBOARD_H
#include "quantum.h"

enum schwann_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _OTHER
};



 /* TAP DANCING DECLARATIONS:
 *
 * TD_RST - TAP x3 for DFU Mode
 * 
 * TD_DBQT - TAP x1 for ' - TAP x2 for "
 * 
 */
enum {
  TD_RST = 0,
  TD_DBQT = 1
};

void dance_rst_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    reset_keyboard();
    reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_RST] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, NULL, dance_rst_reset),
 [TD_DBQT] = ACTION_TAP_DANCE_DOUBLE (KC_QUOTE, KC_DQT)
};

enum custom_keycodes {
  M_PAR = SAFE_RANGE,
  M_BKT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_PAR:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("()" SS_TAP(X_LEFT));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case M_BKT:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("[]" SS_TAP(X_LEFT));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
return true;

};


#define XXXXX KC_TRNS
#define OTHER MO(_OTHER)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_MINUS,  KC_BSPC, 
        KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,     KC_ENT,  
        KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,  OTHER,   
               KC_DEL, KC_LGUI, KC_LALT,                  LOWER,          KC_SPACE,                    RAISE, KC_RCTL
  ),
  [_LOWER] = LAYOUT_split_space(
        KC_ESC, KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_UNDS,  XXXXX, 
        XXXXX,  KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,  KC_ASTR,  M_PAR,  M_BKT, TD(TD_DBQT),  
        XXXXX,     XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,   XXXXX,    XXXXX,  XXXXX,   
                  XXXXX, XXXXX, XXXXX,                     XXXXX,       XXXXX,                        XXXXX, XXXXX
  ),
  [_RAISE] = LAYOUT_split_space(
        XXXXX,  XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,  KC_EQUAL,  XXXXX, 
        KC_CAPS,  XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    KC_LBRC,    KC_RBRC,     XXXXX,  
        XXXXX,     XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,   XXXXX,    XXXXX,  XXXXX,   
                 XXXXX,  XXXXX, XXXXX,                        XXXXX,    XXXXX,                    XXXXX, XXXXX
    ),

  [_OTHER] = LAYOUT_split_space(
        RGB_MOD,  RGB_VAI,    RGB_HUI,    RGB_SAI,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    KC_UP,  KC_BSLS,  XXXXX, 
        XXXXX,  RGB_VAD,    RGB_HUD,    RGB_SAD,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    KC_LEFT,    KC_RIGHT,     KC_PIPE,  
        XXXXX,     XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,    XXXXX,   KC_DOWN,    XXXXX,  XXXXX,   
             TD(TD_RST),  XXXXX,  XXXXX,                         XXXXX,   XXXXX,                    XXXXX,  XXXXX
    )
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set NumLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
  // set ScrollLock LED to output and low
  setPinOutput(B7);
  writePinLow(B7);
}

void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
/*
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }*/

}

//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state)
{
    if (get_highest_layer(state) == 1) {
    writePinHigh(B7);
	} else {
		writePinLow(B7);
    }
    return state;
}


