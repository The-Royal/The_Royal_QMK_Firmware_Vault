/* Copyright 2018 Jack Humbert
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

#define BASE 0
#define FN 1
#define XXX KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT_ALL(
		KC_ESC,     KC_7, KC_8, KC_9,     KC_BSPC,   KC_DEL,
		KC_PGUP,    KC_4, KC_5, KC_6,     KC_MINUS, KC_EQUAL,
		KC_PGDN,    KC_1, KC_2, KC_3,     MO(1),  KC_ENTER,
		KC_SPACE,   KC_0, KC_0, KC_DOT,   MO(1),  KC_ENTER
	),
  
	[FN] = LAYOUT_ALL(
		RGB_MOD,    RGB_SAI, RGB_SAI, RGB_HUI,      XXX, XXX,
		XXX,        RGB_SAD, KC_UP, RGB_HUD,      XXX, XXX,
		RGB_VAI,    KC_LEFT,  KC_DOWN, KC_RIGHT,            XXX, XXX,
		RGB_VAD,              XXX, XXX, XXX,            XXX, XXX
	)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    default: //  for any other layers, or the default layer
        rgblight_sethsv_at (28, 255, 255, 1);
        rgblight_sethsv_at(85, 255, 255, 0);
        break;
    case FN:
        rgblight_sethsv_at (128, 255, 128, 1);
        break;
    }
  return state;
}

