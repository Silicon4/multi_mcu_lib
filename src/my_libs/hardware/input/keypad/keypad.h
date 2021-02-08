#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "keypad_config.h"
#ifdef use_input_keypad


typedef enum keypad_read_mode
{
    PULL_UP,
    PULL_DOWN,
}keypad_read_mode;


void keypad_init(keypad_read_mode mode, void (*call_back)(uint8_t x, uint8_t y));
uint8_t keypad_scan(keypad_read_mode mode);

#endif

#endif // __KEYPAD_H__