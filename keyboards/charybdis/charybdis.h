#pragma once

#include "quantum.h"

// Layout definition for 5x3 split with thumb cluster
#define LAYOUT_5x3( \
    L00, L01, L02, L03, L04,           R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,           R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,           R20, R21, R22, R23, R24, \
                   L32, L33, L34,     R30, R31                 \
) \
{ \
    { KC_NO, L00,   L01,   L02,   L03,   L04   }, \
    { KC_NO, L10,   L11,   L12,   L13,   L14   }, \
    { KC_NO, L20,   L21,   L22,   L23,   L24   }, \
    { KC_NO, KC_NO, KC_NO, L32,   L33,   L34   }, \
    { KC_NO, R04,   R03,   R02,   R01,   R00   }, \
    { KC_NO, R14,   R13,   R12,   R11,   R10   }, \
    { KC_NO, R24,   R23,   R22,   R21,   R20   }, \
    { KC_NO, R31,   R30,   KC_NO, KC_NO, KC_NO }  \
}