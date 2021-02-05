#include "oled_config.h"
#include "spi_config.h"
#include "i2c_config.h"
#ifdef use_oled
#ifdef mcu_stm32f1_hal

#ifdef oled_spi
#include "main.h"
#define cs_pin CS_GPIO_Port, CS_Pin
#define dc_pin DC_GPIO_Port, DC_Pin
#define res_pin RES_GPIO_Port, RES_Pin

void set_cs(uint8_t pin_stat)
{
    HAL_GPIO_WritePin(cs_pin, pin_stat);
}
void set_dc(uint8_t pin_stat)
{
    HAL_GPIO_WritePin(dc_pin, pin_stat);
}
void set_res(uint8_t pin_stat)
{
    HAL_GPIO_WritePin(res_pin, pin_stat);
}

#endif




#endif
#endif
