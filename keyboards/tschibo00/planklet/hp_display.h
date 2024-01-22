#ifndef _PLANKLET_HP_DISPLAY_H_
#define _PLANKLET_HP_DISPLAY_H_

#include "i2c_master.h"

void hpInitDisplay(void);
void hpDrawBitmap(char index);
void hpDrawDigit(char pos,char d);

#endif