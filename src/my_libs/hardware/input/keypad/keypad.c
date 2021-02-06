#include "keypad.h"

#ifdef use_input_keypad

void keypad_int(void)
{
    pin_config(LINE0, MODE_INPUT_PULL_UP);
    pin_config(LINE1, MODE_INPUT_PULL_UP);
    pin_config(LINE2, MODE_INPUT_PULL_UP);
    pin_config(LINE3, MODE_INPUT_PULL_UP);
    pin_config(ROW0, MODE_OUTPUT_PP_NONE);
    pin_config(ROW1, MODE_OUTPUT_PP_NONE);
    pin_config(ROW2, MODE_OUTPUT_PP_NONE);
    pin_config(ROW3, MODE_OUTPUT_PP_NONE);
    int i;
    for (i = 0; i < keypad_row; i++) //拉高所有IO口
    {
        set_row(i, 1);
    }
    for (i = 0; i < keypad_line; i++)
    {
        set_line(i, 1);
    }
}

uint8_t keypad_scan(void)
{
   uint8_t i, j;
   unsigned int cnt[36] = {0}; //最多支持6*6矩阵键盘
   while (1)
   {
       for (i = 0; i < keypad_row; i++)  //循环，每次拉低一列
       {
           set_row(i, 0);  //拉低一列
           for (j = 0; j < keypad_line; j++)  //循环，每次检测一行
           {
               if (get_line() == j)  //检测到行被拉低
               {
                   if(cnt[keypad_row*i+j] <= 200) cnt[keypad_row*i+j]++;  //对应的按键计数加一
               }
               else cnt[keypad_row*i+j] = 0;  //低电平，按键松开或抖动过程，对应的按键计数清零
           }
           set_row(i, 1);  //重新拉高这一列
       }

       for (i = 0; i < keypad_row; i++)  //检测计数值经过100的按键，并用LED显示
       {
           for (j = 0; j < keypad_line; j++)
           {
               if (cnt[keypad_row*i+j] == 200) return 4*i+j;
           }
       }
   }
}

#endif