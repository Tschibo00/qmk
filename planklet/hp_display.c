#include QMK_KEYBOARD_H
#include "hp_display.h"
#include "wait.h"
#include "i2c_master.h"

#define USE_I2CV1
#define ISSI_ADDR_DEFAULT 0xe8				// shifted left because of the auto-"correction" in i2c_master
#define ISSI_REG_CONFIG 0x00
#define ISSI_REG_CONFIG_PICTUREMODE 0x00
#define ISSI_REG_PICTUREFRAME 0x01
#define ISSI_REG_SHUTDOWN 0x0A
#define ISSI_REG_DISPLAY_OPTIONS 0x05
#define ISSI_REG_BREATHE_CONTROL 0x09
#define ISSI_COMMANDREGISTER 0xFD
#define ISSI_BANK_FUNCTIONREG 0x0B

uint8_t bitmaps[2][4] = {
	{
		0b01101110,
		0b11101110,
		0b10011100,
		0b00101111
	},
	{
		0b10111100,
		0b11101110,
		0b11101101,
		0b10011110
	}
};

uint8_t digits[2][10] = {
	{
		0b00000000,0b01100000,0b11011010,0b11110010,0b01100110,0b10110110,0b00111110,0b11100100,0b11111110,0b11100110
	},
	{
		0b11111100,0b01100000,0b11011001,0b11110001,0b01100101,0b10110101,0b00111101,0b11100100,0b11111101,0b11100101
	}
};

uint8_t animPointer=0;
uint8_t anim[14][4]={
	{0b10000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b10000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b10000000,0b00000000},
	{0b00000000,0b00000000,0b01000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000010},
	{0b00000000,0b00000000,0b00000000,0b00100000},
	{0b00000000,0b00000000,0b00000000,0b00010000},
	{0b00000000,0b00000000,0b00010000,0b00000000},
	{0b00000000,0b00000000,0b00001000,0b00000000},
	{0b00000000,0b00000010,0b00000000,0b00000000},
	{0b00100000,0b00000000,0b00000000,0b00000000},
	{0b00010000,0b00000000,0b00000000,0b00000000},
	{0b00001000,0b00000000,0b00000000,0b00000000},
	{0b00000100,0b00000000,0b00000000,0b00000000}
};
	
void hpInitDisplay(void){
	i2c_init();

	// startup procedure copied from Adafruits is31fl3731 library
	writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_SHUTDOWN, 0x00);	// shutdown first
	wait_ms(10);
	writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_SHUTDOWN, 0x01);	// wake up
	
	writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_CONFIG, ISSI_REG_CONFIG_PICTUREMODE);	// picture mode
	writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_PICTUREFRAME, 0);						// select frame 0

	writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_DISPLAY_OPTIONS, 0);						// disable blink
	writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_BREATHE_CONTROL, 0);						// disable breathe
	hpDrawHackScreen();
}


void hpDrawHackScreen(void){
	showBitmap(bitmaps[0]);
}


void hpDrawGameScreen(void){
	if(animPointer<28)
		showBitmap(bitmaps[1]);
	else
		showBitmap(anim[animPointer%14]);
	animPointer++;
	if(animPointer>=70)animPointer=0;
}
// displays a number 00-99 on digit 1+3 due to inaccessible segments (i.e. this looks at least acceptable in a way)
void hpDrawNumber(uint8_t i){
	if(i>99)i=99;
	uint8_t bitmap[4];
	bitmap[0]=digits[0][i/10];
	bitmap[2]=digits[1][i%10];
	bitmap[1]=0;
	bitmap[3]=0;
	showBitmap(bitmap);
}

// ----------- internal functions ------------
void showBitmap(uint8_t *pattern){
	uint8_t outPattern[18];
	mapDisplay(pattern, outPattern);
	writeBulkRegister(0, 0, outPattern);
}


// maps the weirdo connected display to human-readable display spec
// input format is 4 bit patterns setting the segments of 7-segment upside-down display as follows
//   a  b  c  d e f g P
// 128 64 32 16 8 4 2 1
// following is the physical bits to be set
/*
            1st byte   2nd byte
             631
             4268421
            NC         00000000
digit 3		_aecbPdf   00000000
digit 2		_aecbPgf   00000000
digit 1		_aecbdgf   00000000
digit 4		_aecPdgf   00000000
            NC         00000000
            NC         00000000
            NC         00000000
*/
uint8_t* mapDisplay(uint8_t *input,uint8_t *output){
	uint8_t i=input[0];
	output[6]=((i&128)>>1)|((i&64)>>3)|((i&32)>>1)|((i&16)>>2)|((i&8)<<2)|((i&4)>>2)|(i&2)            ;

	i=input[1];
	output[4]=((i&128)>>1)|((i&64)>>3)|((i&32)>>1)            |((i&8)<<2)|((i&4)>>2)|(i&2)|((i&1)<<2);

	i=input[2];
	output[2]=((i&128)>>1)|((i&64)>>3)|((i&32)>>1)|((i&16)>>3)|((i&8)<<2)|((i&4)>>2)      |((i&1)<<2);

	i=input[3];
	output[8]=((i&128)>>1)            |((i&32)>>1)|((i&16)>>2)|((i&8)<<2)|((i&4)>>2)|(i&2)|((i&1)<<3);
	return output;
}


void selectBank(uint8_t bank) {
	i2c_writeReg(ISSI_ADDR_DEFAULT, ISSI_COMMANDREGISTER, &bank, 1, 50);
}


void writeRegister8(uint8_t bank, uint8_t reg, uint8_t data) {
	selectBank(bank);
	i2c_writeReg(ISSI_ADDR_DEFAULT, reg, &data, 1, 50);
}


void writeBulkRegister(uint8_t bank, uint8_t reg, uint8_t *data) {
	selectBank(bank);
	i2c_writeReg(ISSI_ADDR_DEFAULT, reg, data, 18, 50);
}
