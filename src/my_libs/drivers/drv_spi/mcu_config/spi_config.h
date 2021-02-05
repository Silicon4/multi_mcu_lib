#include "all_config.h"
#include "mcu_interface.h"
/*如果使用的单片机的硬件i2c无法使用，通过宏选择软件模拟i2c*/
#ifdef use_spi

uint8_t spi_read_write_byte(uint8_t tx_data);

#endif
