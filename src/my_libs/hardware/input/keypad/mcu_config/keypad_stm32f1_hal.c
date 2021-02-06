//stm32的中间层
#include "keypad_config.h"
#include "mcu_interface.h"

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

void pin_config(pin_type type, pin_mode mode)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    switch (mode)
    {
        case MODE_INPUT_NONE :
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        break;
        case MODE_INPUT_PULL_UP :
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        break;
        case MODE_INPUT_PULL_DOWN :
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        break;
        case MODE_OUTPUT_PP_NONE :
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        break;
        case MODE_OUTPUT_PP_PULL_UP :
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        break;
        case MODE_OUTPUT_PP_PULL_DOWN :
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        break;
        case MODE_OUTPUT_OD_NODE :
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
        break;
        case MODE_OUTPUT_OD_PULL_UP :
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
        break;

        switch (type)
        {
            case ROW0 : GPIO_InitStruct.Pin = ROW0_Pin; HAL_GPIO_Init(ROW0_GPIO_Port, &GPIO_InitStruct); break;
            case ROW1 : GPIO_InitStruct.Pin = ROW1_Pin; HAL_GPIO_Init(ROW1_GPIO_Port, &GPIO_InitStruct); break;
            case ROW2 : GPIO_InitStruct.Pin = ROW2_Pin; HAL_GPIO_Init(ROW2_GPIO_Port, &GPIO_InitStruct); break;
            case ROW3 : GPIO_InitStruct.Pin = ROW3_Pin; HAL_GPIO_Init(ROW3_GPIO_Port, &GPIO_InitStruct); break;
            case LINE0 : GPIO_InitStruct.Pin = LINE0_Pin; HAL_GPIO_Init(LINE0_GPIO_Port, &GPIO_InitStruct); break;
            case LINE1 : GPIO_InitStruct.Pin = LINE1_Pin; HAL_GPIO_Init(LINE1_GPIO_Port, &GPIO_InitStruct); break;
            case LINE2 : GPIO_InitStruct.Pin = LINE2_Pin; HAL_GPIO_Init(LINE2_GPIO_Port, &GPIO_InitStruct); break;
            case LINE3 : GPIO_InitStruct.Pin = LINE3_Pin; HAL_GPIO_Init(LINE3_GPIO_Port, &GPIO_InitStruct); break;
        }     
    }
}

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
