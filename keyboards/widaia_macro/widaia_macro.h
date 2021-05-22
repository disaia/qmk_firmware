#pragma once

#include "quantum.h"

#define KEYMAP( \
	K00, K01, K02, \
	K10, K11, K12, \
	K20, K21, K22  \
) { \
	{ K00,   K01,   K02 }, \
	{ K10,   K11,   K12 }, \
	{ K20,   K21,   K22 }  \
}

#define LAYOUT_widaia_macro( \
    k00, k01, k02, \
    k10, k11, k12, \
    k20, k21, k22 \
) { \
    { k00, k01, k02 }, \
    { k10, k11, k12 }, \
    { k20, k21, k22 } \
}
