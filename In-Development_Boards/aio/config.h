#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    TheRoyalSweatshirt
#define PRODUCT         The AIO_40
#define DESCRIPTION     An all in one 40 Percent Keyboard
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

/* key matrix pins */
#define MATRIX_ROW_PINS { E6, D6, D5, D3, D2 }
#define MATRIX_COL_PINS { B5, B6, C6, C7, F7, F6, F5, F4, F1, F0, B4, D7, D4, B7 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { B3 }
#define ENCODERS_PAD_B { B2 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define OLED_DISABLE_TIMEOUT

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define TAPPING_TERM 200

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define OLED_FONT_H "keyboards/kingly_keys/aio/gmkbad.c"