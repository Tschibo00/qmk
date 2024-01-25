#ifndef _PLANKLET_HP_DISPLAY_H_
#define _PLANKLET_HP_DISPLAY_H_

extern void hpInitDisplay(void);
extern void hpDrawBitmap(uint8_t index);
extern void hpDrawHackScreen(void);
extern void hpDrawGameScreen(void);
extern void hpDrawNumber(uint8_t i);

extern void showBitmap(uint8_t *pattern);
extern uint8_t* mapDisplay(uint8_t *input,uint8_t *output);
extern void selectBank(uint8_t bank);
extern void writeRegister8(uint8_t bank, uint8_t reg, uint8_t data);
extern void writeBulkRegister(uint8_t bank, uint8_t reg, uint8_t *data);

#endif
