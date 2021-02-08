#include "keypad.h"

#ifdef use_input_keypad

void (*keypad_call_back)(uint8_t x, uint8_t y); //回调函数

void keypad_init(keypad_read_mode mode, void (*call_back)(uint8_t x, uint8_t y))
{
    if (mode == PULL_DOWN)
    {
        pin_config(LINE0, MODE_INPUT_PULL_UP);
        pin_config(LINE1, MODE_INPUT_PULL_UP);
        pin_config(LINE2, MODE_INPUT_PULL_UP);
        pin_config(LINE3, MODE_INPUT_PULL_UP);
        pin_config(ROW0, MODE_OUTPUT_PP_NONE);
        pin_config(ROW1, MODE_OUTPUT_PP_NONE);
        pin_config(ROW2, MODE_OUTPUT_PP_NONE);
        pin_config(ROW3, MODE_OUTPUT_PP_NONE);
    }
    if (mode == PULL_UP)
    {
        pin_config(LINE0, MODE_INPUT_NONE);
        pin_config(LINE1, MODE_INPUT_NONE);
        pin_config(LINE2, MODE_INPUT_NONE);
        pin_config(LINE3, MODE_INPUT_NONE);
        pin_config(ROW0, MODE_OUTPUT_PP_PULL_DOWN);
        pin_config(ROW1, MODE_OUTPUT_PP_PULL_DOWN);
        pin_config(ROW2, MODE_OUTPUT_PP_PULL_DOWN);
        pin_config(ROW3, MODE_OUTPUT_PP_PULL_DOWN);
    }
    keypad_call_back = call_back;
}

uint8_t keypad_scan(keypad_read_mode mode)
{
   static unsigned int cnt[36] = {0}; //最多支持6*6矩阵键盘
   while (1)
   {
       for (uint8_t i = 0; i < keypad_row; i++)  //循环，每次拉低一列
       {
           if (mode == PULL_DOWN) set_row(i, 0);  //拉低一列
           if (mode == PULL_UP) set_row(i, 1);

           for (uint8_t j = 0; j < keypad_line; j++)  //循环，每次检测一行
           {
               if (get_line() == j)  //检测到行被拉低
               {
                   if(cnt[keypad_row*i+j] <= 200) cnt[keypad_row*i+j]++;  //对应的按键计数加一
               }
               else cnt[keypad_row*i+j] = 0;  //低电平，按键松开或抖动过程，对应的按键计数清零

               if (cnt[keypad_row*i+j] == 200)
               {
                    keypad_call_back(i, j);
                    return 4*i+j;
               }
           }

           if (mode == PULL_DOWN) set_row(i, 1);  //重新拉高这一列
           if (mode == PULL_UP) set_row(i, 0);
       }
   }
}

#endif