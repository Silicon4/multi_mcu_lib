
#include "spi_config.h"
#ifdef use_spi
#ifdef mcu_stm32f1_hal

#define spi hspi1

uint8_t spi_read_write_byte(uint8_t tx_data)
{
    uint8_t rx_data;
    HAL_SPI_TransmitReceive(&hspi, &tx_data, &rx_data, 1, 0xfff);
    return rx_data;
}

#endif
#endif