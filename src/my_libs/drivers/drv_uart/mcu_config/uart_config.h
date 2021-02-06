#include "all_config.h"
#include "mcu_interface.h"
/*如果使用的单片机的硬件i2c无法使用，通过宏选择软件模拟i2c*/
#ifdef use_uart

void uart_receive(uint8_t *rx_data);
void uart_transmit(uint8_t *tx_data);


#endif
