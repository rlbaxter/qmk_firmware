// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER Reggie
#define PRODUCT ut11

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 3

#define DIODE_DIRECTION COL2ROW

// #define PRODUCT UT11 Raspberry Pi RP2040
#define MATRIX_COL_PINS { GP19, GP1, GP2 }
#define MATRIX_ROW_PINS { GP18, GP5, GP4, GP3 }
#define ENCODERS_PAD_A { GP27, GP29 }
#define ENCODERS_PAD_B { GP26, GP28 }   
#define DEBUG_MATRIX_SCAN_RATE

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// #define RGB_DI_PIN A1
