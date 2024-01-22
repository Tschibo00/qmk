#include "hp_display.h"

void hpInitDisplay(void){
/*	Wire.begin();
	TWBR=0;
	Wire.beginTransmission(OLED_I2C_ADDRESS);
*/
}

void hpDrawBitmap(char index){}

void hpDrawDigit(char pos,char d){}

/*
static const uint8_t PROGMEM
game_bmp[] ={  
0b10111111,
0b11011111,
0b10101111,
0b11100111,
},
hack_bmp[] = {  
0b11000110,
0b11011111,
0b11011100,
0b11011100,
};
  x y bitmap width height lum
  matrix.drawBitmap(0, 1, game_bmp, 8, 5, 64);
  matrix.drawBitmap(0, 1, hack_bmp, 8, 5, 64);
*/

/*
void render_random_display(void){
	for(int i=0;i<10;i++){
		led_matrix_set_value(i,((rand()%10)==0)*100);
	}
}
*/
/*void render_game_display(void){
	led_matrix_set_value(9,100);
	led_matrix_set_value(11,100);
	led_matrix_set_value(12,100);
	led_matrix_set_value(13,100);
	led_matrix_set_value(14,100);
	led_matrix_set_value(15,100);
	led_matrix_set_value(16,100);
//	led_matrix_set_value_all(100);
//	led_matrix_set_value(0, 70);
//	led_matrix_set_value(0, 0);
}

void render_hack_display(void){
//	led_matrix_set_value_all(0);
//	led_matrix_set_value(1, 70);
//	led_matrix_set_value(1, 0);
}*/