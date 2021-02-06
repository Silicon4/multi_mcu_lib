#include "uart_config.h"

#ifdef use_uart
#ifdef mcu_stm32f1_hal
#include "main.h"
extern UART_HandleTypeDef huart1;

void uart_receive(uint8_t *rx_data)
{
    HAL_UART_Receive(&huart1, rx_data, sizeof(rx_data), 0xfff);
}

void uart_transmit(uint8_t *tx_data)
{
    HAL_UART_Transmit(&huart1, tx_data, sizeof(tx_data), 0xfff);
}

#endif
#endif
