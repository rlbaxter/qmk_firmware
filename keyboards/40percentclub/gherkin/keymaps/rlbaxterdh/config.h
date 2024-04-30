#pragma once

/* Make layout the right way:
 *  - USB port on left side
 *  - Switches facing the correct way
 */
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { B6, B2, B3, B1, F7 }
#define MATRIX_COL_PINS { D0, D4, C6, D7, E6, B4 }

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#define COMBO_COUNT 2
