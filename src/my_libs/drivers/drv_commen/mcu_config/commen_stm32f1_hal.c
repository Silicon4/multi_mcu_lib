//基本函数的stm32f1hal相关实现
#include "commen_config.h"
#include "stdio.h"

#define us_tim htim6 //用于us延时的定时器

#ifdef mcu_stm32f1_hal

void my_delayms(uint64_t ms)
{
    HAL_Delay(ms);
}

extern TIM_HandleTypeDef htim6;
void my_delayus(uint64_t us) //如果不用systic,需要开一个定时器用于us级别延时
{
    uint16_t differ = 0xffff - us - 5;
    __HAL_TIM_SET_COUNTER(&us_tim, differ);
    HAL_TIM_Base_Start(&us_tim);
    while (differ < 0xffff - 6)
    {
        differ = __HAL_TIM_GET_COUNTER(&us_tim);
    }
    HAL_TIM_Base_Stop(&us_tim);
}

uint64_t my_getms(void)
{
    uint32_t getms = HAL_GetTick(); //获取系统当前时间
    return getms;
}

void my_commonInit(void)
{
    
}

void my_print(const char *chr)
{
    printf(chr);
}


#endif
