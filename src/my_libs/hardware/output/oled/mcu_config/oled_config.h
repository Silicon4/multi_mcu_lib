#include "all_config.h"
#include "mcu_interface.h"

#define oled_i2c
//#define oled_spi

#ifdef oled

#ifdef oled_i2c
#include "drv_i2c.h"
#endif

// #ifdef oled_spi
// #include "drv_spi.h"
// #endif

#endif
