#pragma once

#include "quantum.h"

#define ___ KC_NO


#define LAYOUT_4x10( \
    K00, K01, K02, K03, K04, K44, K43, K42, K41, K40, \
    K10, K11, K12, K13, K14, K54, K53, K52, K51, K50, \
    K20, K21, K22, K23, K24, K64, K63, K62, K61, K60, \
    K30, K31, K32, K33, K34, K74, K73, K72, K71, K70 \
) { \
    { K00, K01, K02, K03, K04 }, \
    { K40, K41, K42, K43, K44 }, \
    { K10, K11, K12, K13, K14 }, \
    { K50, K51, K52, K53, K54 }, \
    { K20, K21, K22, K23, K24 }, \
    { K60, K61, K62, K63, K64 }, \
    { K30, K31, K32, K33, K34 }, \
    { K70, K71, K72, K73, K74 } \
}

#define LAYOUT LAYOUT_4x10