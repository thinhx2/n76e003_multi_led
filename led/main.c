#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"

void delay(unsigned int time){
	unsigned int i,j;
	for(i = 0; i<time; i++){
		for(j=0; j<123; j++);
	}
}

void hieuung1(){
	int i;
	for(i=0; i<8; i++){
		P0=P1=0x01<<i;
    delay(1000);
	}
}

void hieuung2(){
	int i;
	for(i=0; i<8; i++){
		P0=P1=0x80>>i;
		delay(1000);
	}
}

void hieuung3(){
	int i;
	P0=P1=0x00;
	for(i=0; i<8; i++){
		P0=P1=P0|(0x01<<i);
		delay(1000);
	}
}

void hieuung4(){
	int i;
	P0=P1=0x00;
	for(i=0; i<8; i++){
		P0=P1=P0|(0x80>>i);
		delay(1000);
	}
}

// lap trinh hieu ung sang tung led 1;
void sangtungled(){
	int i;
	P0=P1 = 0x00; // tat tat ca cac led o cong P0;
	for(i=0; i<8; i++){
	   P0=P1 = 0x01<<i;
	   /*
	   	P0=0x00;
		i=0: P0 = 0x01<<0 = 0x01;
		i=1: P0 = 0x01<<1 = 0000 0001 << 1 = 0000 0010;
		...
		i=7: P0 = 0x01<<7 = 0000 0001 << 7 = 1000 0000= 0x80;
	   */
	   delay(1000);
	}			 
	// ket thuc vong for ben tren thi P0= 0x80;
		for(i=0; i<8; i++){
			P0=P1 = 0x80 >> i;	
			delay(1000);
		}
		
}

void sangdan(){
	int i;
	P0=P1= 0x00;
	for(i=0; i<8; i++){
		P0=P1= P0|(0x01<<i);
		delay(1000);
	}
	for(i=0; i<8; i++){
		P0=P1 = P0&(0x7f>>i);
		delay(1000);
	}
}

		// Hieu ung chop tat 1: Ca 8 LED sang, ca 8 LED tat
void hieuung5(){
	int i;
	P0=P1= 0x00;
		for(i=0;i<5;i++)
		{
		 	P0=P1 = 0x00;
			delay(1000);
			P0=P1 = 0xFF;
			delay(1000);
		}
}

		// Hieu ung chop tat 2: 4 bong dau sang, 4 bong sau tat. 4 bong dau tat, 4 bong sau sang
void hieuung6(){
	int i;
	P0=P1= 0x00;
		for(i=0;i<5;i++)
		{
		 	P0=P1 = 0x0F;
			delay(1000);
			P0=P1 = 0xF0;
			delay(1000);
		}
}

		// Hieu ung chop tat 3
void hieuung7(){
	int i;
	P0= 0x00;
		for(i=0;i<5;i++)
		{
		 	P0=P1 = 0x55;
			delay(1000);
			P0=P1 = 0xAA;
			delay(1000);
		}
}

int main(){
	int i;
	P0=P1 = 0x00;
	Set_All_GPIO_Quasi_Mode;
	while(1){
				hieuung1();
				hieuung2();
				hieuung3();
				hieuung4();
		    sangtungled();
			  sangdan();
				hieuung5();
				hieuung6();
				hieuung7();
    }
}

// Software based delay. Time is not accurate.