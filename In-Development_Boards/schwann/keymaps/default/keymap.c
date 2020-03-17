#include QMK_KEYBOARD_H
#include "quantum.h"

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _OTHER
};

//Tap Dance Declarations
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

//All tap dance functions would go here. Only showing this one.
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
#define OTHER MO(_OTHER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │Del│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │  Enter  │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───────┤
     * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RShift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬──────┘
     * │LCtl│LGui│LAlt│         Space          │RAlt│ Fn │ 
     * └────┴────┴────┴────────────────────────┴────┴────┘ 
     */

[_BASE] = LAYOUT_TWOU_ortho(
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSPC,
    KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_ENT,
              KC_DEL,  KC_LGUI, KC_LALT, LOWER,     KC_SPACE,       RAISE,   OTHER,    KC_RALT,  KC_RCTL
),

/* _LOWER
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_TWOU_ortho(
    KC_ESC,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,     KC_8,     KC_9,     KC_0,     _______,
    KC_TILD,    KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DQT,
    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,  KC_GRAVE, KC_LBRC,  KC_RBRC,  _______,
                _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______
),

/* _RAISE
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_TWOU_ortho(
    RGB_MOD,    _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  _______,  KC_MINS,  _______,
    KC_CAPS,    _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  KC_BSLS,
    KC_PSCR,    _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  KC_EQUAL,
                _______,   _______,    _______,   _______,   _______,   _______,  _______,  _______,  _______ 
),

/* _OTHER
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_OTHER] = LAYOUT_TWOU_ortho(
    TD(TD_RST),    _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  RGB_SAI,  RGB_HUI,  RGB_VAI,
    _______,    _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  RGB_SAD,  RGB_HUD,  RGB_VAD,
    _______,    _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,
                RGB_MOD,   _______,    _______,   _______,   _______,   _______,  _______,  _______,  _______ 
)

};

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case TD(TD_DBQT):
      return 230;
    default:
      return TAPPING_TERM;
  }
}


