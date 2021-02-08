#ifndef __OLED_CONFIG_H__
#define __OLED_CONFIG_H__

#include "all_config.h"
#include "mcu_interface.h"

#define oled_i2c
// #define oled_spi

#ifdef oled

#ifdef oled_i2c
#ifndef use_i2c
#define use_i2c
#endif
#include "drv_i2c.h"
#endif

#ifdef oled_spi
#ifndef use_spi
#define use_spi
#endif
#include "drv_spi.h"

void set_cs(uint8_t pin_stat);
void set_dc(uint8_t pin_stat);
void set_res(uint8_t pin_stat);

#endif

#endif

#endif // __OLED_CONFIG_H__