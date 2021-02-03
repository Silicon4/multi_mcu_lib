//根据单片机宏选择要使用的库
#include "all_config.h"
#include "stdint.h"

#ifdef mcu_stm32f1_hal
#include "stm32f1xx_hal.h"
#endif

// #ifdef mcu_stm32f4_hal
// #include "stm32f4xx_hal.h"
// #endif

