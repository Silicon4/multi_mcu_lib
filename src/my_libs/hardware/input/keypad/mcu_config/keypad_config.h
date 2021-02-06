//矩阵键盘基本函数的编译控制
#include "all_config.h"
#include "commen_config.h"
#include "mcu_interface.h"
#ifdef use_input_keypad
//用宏定义行数和列数
#define keypad_row 4
#define keypad_line 4

typedef enum key_stat
{
    KEY_UP,
    KEY_DOWN,
    KEY_LONE,
    KEY_DOUBLE,
}key_stat;


typedef enum pin_type
{
    LINE0,
    LINE1,
    LINE2,
    LINE3,
    ROW0,
    ROW1,
    ROW2,
    ROW3,
}pin_type;

typedef enum pin_mode
{
    MODE_INPUT_NONE,
    MODE_INPUT_PULL_UP,
    MODE_INPUT_PULL_DOWN,
    MODE_OUTPUT_PP_NONE,
    MODE_OUTPUT_PP_PULL_UP,
    MODE_OUTPUT_PP_PULL_DOWN,
    MODE_OUTPUT_OD_NODE,
    MODE_OUTPUT_OD_PULL_UP,
}pin_mode;


void pin_config(pin_type type, pin_mode mode);
void set_row(uint8_t row, uint8_t stat);
void set_line(uint8_t line, uint8_t stat);
uint8_t get_line(void);
#endif
