#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    TheRoyalSweatshirt
#define PRODUCT         Moiie
#define DESCRIPTION     A retro-themed macro pad inspired by the vintage apple iie keypad.
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { D6, D7, B4, B5 }
#define MATRIX_COL_PINS { D4, B7, B3, B2, B1, B0 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D5 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
#define BACKLIGHT_LEVELS 0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN F0
#define RGBLED_NUM 3    // Number of LEDs

#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 6
#define RGBLIGHT_SAT_STEP 4
#define RGBLIGHT_VAL_STEP 8
