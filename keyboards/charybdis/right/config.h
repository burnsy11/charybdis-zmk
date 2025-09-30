#pragma once

#include "../config.h"

// Right half specific configuration
#define MASTER_RIGHT
#define SPLIT_HAND_PIN GP16

// Matrix pins for right half  
#define MATRIX_ROW_PINS { GP18, GP5, GP4, GP9 }
#define MATRIX_COL_PINS { GP19, GP20, GP10, GP6, GP7, GP8 }

// Trackball configuration for right side
#define POINTING_DEVICE_RIGHT
#define PMW3610_CS_PIN GP20
#define PMW3610_CK_PIN GP8
#define PMW3610_DI_PIN GP17
#define PMW3610_DO_PIN GP17