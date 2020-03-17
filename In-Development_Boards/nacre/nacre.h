#pragma once

#include "quantum.h"
#include "nacre.h"

#define LAYOUT_split_space( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K010, K011, K012,   \
    K10,  K11, K12, K13, K14, K15, K16, K17, K18, K19, K110,  K112,     \
     K20,  K21, K22, K23, K24, K25, K26, K27, K28, K29, K210,   K211,   \
               K30, K31, K32,       K34, K37,       K39, K311           \
){ \
  { K00, K01, K02, K03,   K04, K05, K06,   K07, K08,   K09, K010, K011,  K012},    \
  { K10, K11, K12, K13,   K14, K15, K16,   K17, K18,   K19, K110, KC_NO, K112},    \
  { K20, K21, K22, K23,   K24, K25, K26,   K27, K28,   K29, K210, K211,  KC_NO},   \
  { K30, K31, K32, KC_NO, K34, KC_NO, KC_NO, K37, KC_NO, K39, K311, KC_NO, KC_NO}, \
}

#define LAYOUT_big_space( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K010, K011, K012,   \
    K10,  K11, K12, K13, K14, K15, K16, K17, K18, K19, K110,  K112,     \
     K20,  K21, K22, K23, K24, K25, K26, K27, K28, K29, K210,   K211,   \
                 K30, K31,        K34,       K39, K311                  \
){ \
  { K00, K01, K02, K03,   K04, K05, K06,   K07, K08,   K09, K010, K011,  K012},      \
  { K10, K11, K12, K13,   K14, K15, K16,   K17, K18,   K19, K110, KC_NO, K112},      \
  { K20, K21, K22, K23,   K24, K25, K26,   K27, K28,   K29, K210, K211,  KC_NO},     \
  { K30, K31, K32, KC_NO, K34, KC_NO, KC_NO, KC_NO, KC_NO, K39, K311, KC_NO, KC_NO}, \
}
