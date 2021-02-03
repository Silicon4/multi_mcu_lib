#include "all_config.h"
#include "mcu_interface.h"
/*如果使用的单片机的硬件i2c无法使用，通过宏选择软件模拟i2c*/
#ifdef use_i2c
#define i2c_hard
//#define i2c_soft


#ifdef i2c_soft
void scl_H(void);
void scl_L(void);
void sda_H(void);
void sda_L(void);
#endif

void i2c_write_byte(uint16_t dev_add, uint16_t mem_add, uint8_t data);
void i2c_write_len(uint16_t dev_add, uint16_t mem_add, uint16_t mem_size, uint8_t *data, uint16_t buff_size);
#endif
