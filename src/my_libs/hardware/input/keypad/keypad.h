#include "keypad_config.h"
#ifdef use_input_keypad

void keypad_init(void (*callback)(unsigned char x, unsigned char y));
uint8_t keypad_scan(void);

#endif
