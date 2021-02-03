//基本函数的编译控制
#include "all_config.h"
#include "mcu_interface.h"

#ifdef mcu_stm32f1_hal

#endif

void my_delayms(uint64_t ms);
void my_delayus(uint64_t us);
uint64_t my_getms(void);
void my_commonInit(void);
void my_print(const char *);

