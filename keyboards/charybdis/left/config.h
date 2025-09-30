#pragma once

#include "../config.h"

// Left half specific configuration
#define MASTER_LEFT
#define SPLIT_HAND_PIN GP16

// Matrix pins for left half
#define MATRIX_ROW_PINS { GP18, GP5, GP4, GP9 }
#define MATRIX_COL_PINS { GP19, GP20, GP10, GP6, GP7, GP8 }

// No trackball on left side
#undef POINTING_DEVICE_ENABLE