//stm32的中间层
#include "keypad_config.h"
#include "src/my_libs/drivers/mcu_interface.h"

#ifdef use_input_keypad

#ifdef mcu_stm32f1_hal

#include "main.h"

#define row0  ROW0_GPIO_Port, ROW0_Pin
#define line0 LINE0_GPIO_Port, LINE0_Pin
#define row1  ROW1_GPIO_Port, ROW1_Pin
#define line1 LINE1_GPIO_Port, LINE1_Pin
#define row2  ROW2_GPIO_Port, ROW2_Pin
#define line2 LINE2_GPIO_Port, LINE2_Pin
#define row3  ROW3_GPIO_Port, ROW3_Pin
#define line3 LINE3_GPIO_Port, LINE3_Pin


void set_row(uint8_t row, uint8_t stat)
{
    switch (row)
    {
        case 0: HAL_GPIO_WritePin(row0, stat); break;
        case 1: HAL_GPIO_WritePin(row1, stat); break;
        case 2: HAL_GPIO_WritePin(row2, stat); break;
        case 3: HAL_GPIO_WritePin(row3, stat); break;
    }
}

void set_line(uint8_t line, uint8_t stat)
{
    switch (line)
    {
        case 0: HAL_GPIO_WritePin(line0, stat); break;
        case 1: HAL_GPIO_WritePin(line1, stat); break;
        case 2: HAL_GPIO_WritePin(line2, stat); break;
        case 3: HAL_GPIO_WritePin(line3, stat); break;
    }
}



uint8_t get_line(void)
{
    uint8_t line = 4;
    if (HAL_GPIO_ReadPin(line0) == GPIO_PIN_RESET) line = 0;
    if (HAL_GPIO_ReadPin(line1) == GPIO_PIN_RESET) line = 1;
    if (HAL_GPIO_ReadPin(line2) == GPIO_PIN_RESET) line = 2;
    if (HAL_GPIO_ReadPin(line3) == GPIO_PIN_RESET) line = 3;
    return line;
}
#endif
#endif
