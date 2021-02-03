//矩阵键盘基本函数的编译控制
#include "all_config.h"
#include "commen_config.h"
#include "mcu_interface.h"
#ifdef use_input_keypad
//用宏定义行数和列数
#define keypad_row 4
#define keypad_line 4

void set_row(uint8_t row, uint8_t stat);
void set_line(uint8_t line, uint8_t stat);
uint8_t get_line(void);
#endif
