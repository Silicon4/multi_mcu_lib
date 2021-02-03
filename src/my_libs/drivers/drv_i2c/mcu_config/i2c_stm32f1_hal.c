#include "i2c_config.h"

#ifdef use_i2c
#ifdef mcu_stm32f1_hal

#define i2c hi2c1

#ifdef i2c_soft
#include "main.h" //包含引脚的命名

#define scl  SCL_GPIO_Port, SCL_Pin
#define sda SDA_GPIO_Port, SDA_Pin

void scl_H(void)
{
    HAL_GPIO_WritePin(scl, GPIO_PIN_SET);
}
void scl_L(void)
{
    HAL_GPIO_WritePin(scl, GPIO_PIN_RESET);
}
void sda_H(void)
{
    HAL_GPIO_WritePin(sda, GPIO_PIN_SET);
}
void sda_L(void)
{
    HAL_GPIO_WritePin(sda, GPIO_PIN_RESET);
}
#endif

#ifdef i2c_hard
#include "main.h"
extern I2C_HandleTypeDef i2c;
void i2c_write_byte(uint16_t dev_add, uint16_t mem_add, uint8_t data)
{
    HAL_I2C_Mem_Write(&i2c ,dev_add<<1, mem_add, 1, (uint8_t *)&data, 1, 0xfff);
}
void i2c_write_len(uint16_t dev_add, uint16_t mem_add, uint16_t mem_size, uint8_t *data, uint16_t buff_size)
{
    HAL_I2C_Mem_Write(&i2c ,dev_add<<1, mem_add, mem_size, data, buff_size, 0xfff);
}
#endif

#endif
#endif
