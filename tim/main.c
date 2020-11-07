#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"

unsigned char sangXuoi[8]= {0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00};
unsigned char sangNguoc[8] = {0xff,0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01};
unsigned char tatXuoi[8] = {0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};
unsigned char tatNguoc[9] = {0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe,0xff};

unsigned char sang1BongXuoi[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char sang1BongNguoc[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
unsigned char tat1BongXuoi[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char tat1BongNguoc[8] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

void delay(unsigned int time){
	unsigned int i,j;
	for(i = 0; i<time; i++){
		for(j=0; j<123; j++);
	}
}

void Blink(int lan)	//nhay toan bo trong va ngoai
{
	int i;
	for(i=0;i<lan;i++)
	{
		P0 = P1 = 0;
		delay(750);
		P0 = P1 = 0xff;
		delay(750);
	}
}
void nhayVeTraiTim() //Vua nhay vua ve trai tim
{ 
	int i;
	P1=P0=0xff;
	for(i=0;i<8;i++)
	{
		P1 = sangXuoi[i];
		delay(750);
		P1=0xff;
		delay(750);
	}
	P1=0;
	for(i=0;i<8;i++)
	{
		P0 = sangXuoi[i];
		delay(750);
		P0=0xff;
		delay(750);
	}
	P0=0;
}
void nhayVeTraiTim2()
{
	P1=P0=0;
	P1=P0=0xfe; delay(750);
	P1=P0=0xfd; delay(750);
	P1=P0=0xfa; delay(750);
	P1=P0=0xf5; delay(750);
	P1=P0=0xea; delay(750);
	P1=P0=0xd5; delay(750);
	P1=P0=0xaa; delay(750);
	P1=P0=0x55; delay(750);
}
void nhayVeChu()  //Vua nhay vua ve chu Q <3 N
{ 
	int i;
	//----------- Xu <3 Hiep --------- 
	for(i=0;i<3;i++)
	{
		P0 = sangXuoi[i];
		delay(750);
		P0=0xff;
		delay(750);
	}
}
void nhayXenKeTraiTim(int lan)	//trai tim ben ngoai nhay xen ke nhau  
{ 
	int i;
	for(i=0;i<lan;i++)
	{
		P1=0xaa; P0=0x55; delay(750);
		P1=0x55; P0=0xaa; delay(750);				
	}
}
void nhayXenKeTrongNgoai() //ben trong va ben ngoai nhay xen ke nhau
{ 
	P1=0; P0=0xff; delay(750);
	P1=0xff; P0=0; delay(750);
}
/*void nhayDienTen() //1 bong chay den cuoi roi chay lai, het lan i thi bong thu i sang   
{
	 P1=P3=0;
	P0=0; delay(750); P0=0xff;
	P2=0; delay(750);	P2=0xff;
	P0=0; delay(750); P0=0xff;
	P2=0; delay(750);	P2=0xff;
	//----------------- Xu <3 Hiep --------------------------
	P0=0xfe; delay(750); P0=0xfd; delay(750); P0=0xfb; delay(750); P0=0xf7; delay(750);	P0=0xef; delay(750); P0=0xdf; delay(750); P0=0xbf; delay(750);
	P0=0xff; delay(750); P0=0xe7; delay(750); P0=0xf7; delay(750); P0=0xfb; delay(750);	P0=0xfd; delay(750); P0=0xfe; delay(750);
	//-----------------------------------------------------
	P0=0xfc; delay(750); P0=0xfa; delay(750); P0=0xf6; delay(750); P0=0xee; delay(750);	P0=0xde; delay(750); P0=0xbe; delay(750);
	P0=0xde; delay(750); P0=0xee; delay(750); P0=0xf6; delay(750); P0=0xfa; delay(750);	P0=0xfc; delay(750);
	//-----------------------------------------------------
	P0=0xf8; delay(750); P0=0xf4; delay(750); P0=0xec; delay(750); P0=0xdc; delay(750);	P0=0xbc; delay(750);
	P0=0xdc; delay(750); P0=0xec; delay(750); P0=0xf4; delay(750); P0=0xf8; delay(750);
	//-----------------------------------------------------
	P0=0xf0; delay(750); P0=0xe8; delay(750); P0=0xd8; delay(750); P0=0xb8; delay(750);
	P0=0xd8; delay(750); P0=0xe8; delay(750); P0=0xf0; delay(750);
	//-----------------------------------------------------
	P0=0xe0; delay(750); P0=0xd0; delay(750);  P0=0xb0; delay(750);
	P0=0xd0; delay(750); P0=0xe0; delay(750);
	//-----------------------------------------------------
	P0=0xc0; delay(750); P0=0xa0; delay(750);
	P0=0xc0; delay(750);
	//----------------------------------------------------
	P0=0x80; delay(750);
	P0=0; 
}*/
void chay1Bong1() //1 bong tat chay tu vi tri 0 den 7 roi quay lai
{
	int i;
	for(i=0;i<8;i++)
	{
		P1=P0=tat1BongXuoi[i];
		delay(750);
	}
	P1=P0=0;
	for(i=0;i<8;i++)
	{
		P1=P0=tat1BongNguoc[i];
		delay(750);
	}
	P0=P1=0xff;
} 
void chayVongTronXuoi1() //1 bong tat chay vong tron
{
	int i;
	P0=P1=0;
	for(i=0;i<8;i++)
	{
		P1=tat1BongXuoi[i];
		delay(750);	
	}
	P1=0;
	for(i=0;i<8;i++)
	{
		P0=tat1BongNguoc[i];
		delay(750);
	}
	P0=0;
}
void chayVongTronNguoc1() //1 bong tat chay vong tron nguoc
{
	int i;
	P0=P1=0;
	for(i=0;i<8;i++)
	{
		P0=tat1BongXuoi[i];
		delay(750);	
	}
	P0=0;
	for(i=0;i<8;i++)
	{
		P1=tat1BongNguoc[i];
		delay(750);
	}
	P1=0;
}
void nhayDienTen2()	 //ten duoc dien tu 2 chieu
{
	P0=0xfe; delay(750);
	P0=0xfa; delay(750);
	P0=0xf8; delay(750);
//	P0=0x9c; delay(750);
//	P0=0x98; delay(750);
//	P0=0x88; delay(750);
//	P0=0x80; delay(750);		 
}
void veTraiTim() //2 nua trai tim duoc ve xen ke
{
	int i;
	P0=0; P1=0xff;
	for(i=0;i<8;i++)
	{
		P1 = sangXuoi[i];
		delay(750);
		P0 = sangXuoi[i];
		delay(750);
	}  
}
void veTraiTim2() //2 nua trai tim duoc ve dong thoi
{
	int i;
	P0=0; P1=0xff;
	for(i=0;i<8;i++)
	{
		P1=P0=sangXuoi[i];
		delay(750);
	}
	for(i=0;i<8;i++)
	{
		P1=P0=tatXuoi[i];
		delay(750);
	}
}
void veTraiTim3() //2 nua trAI tim duoc ve nguoc chieu nhau
{
	int i;
	P0=0; P1=0xff;
	for(i=0;i<8;i++)
	{
		P1=sangXuoi[i];
		delay(750);
		P0=sangNguoc[i];
		delay(750);
	}
	for(i=0;i<8;i++)
	{
		P1=tatXuoi[i];
		delay(750);
		P0=tatNguoc[i];
		delay(750);
	}
}
void veTraiTim4() //Nguoc lai hieu ung ve trai tim 3
{
	int i;
	P0=0; P1=0xff;
	for(i=0;i<8;i++)
	{
		P1=sangNguoc[i];
		delay(750);
		P0=sangXuoi[i];
		delay(750);
	}
	for(i=0;i<8;i++)
	{
		P1=tatNguoc[i];
		delay(750);
		P0=tatXuoi[i];
		delay(750);
	}	
}
void chayTen() //tung chu cai nhay lan luot
{
	int i;
	P1=P0=0; 
	for(i=0;i<3;i++)
	{
		P0=tat1BongXuoi[i];
		delay(750);
	}
	for(i=0;i<3;i++)
	{
		P0=tat1BongNguoc[i];
		delay(750);
	}
	  
}
void nhayCham() //ket thuc
{
	int i;
	P0=P1=0;
	delay(750);
	P0=P1=0xff;
	delay(750);
	//--------------
	P0=P1=0;
	delay(750);
	P0=P1=0xff;
	delay(750);
	for(i=0;i<3;i++)
	{
		P0=sangXuoi[i];
		delay(750);
	}
	 
}
void saoBang()   //hieu ung sao bang
{
	int i;
	P0=P1=0;
	for(i=0;i<8;i++)
	{
		P1 = P0 = sangXuoi[i];
		delay(750);	
	}
	for(i=0;i<8;i++)
	{
		P1 = P0 = tatXuoi[i];
		delay(750);	
	}
	//--------Nguoc-----
	for(i=0;i<8;i++)
	{
		P1 = P0 = sangNguoc[i];
		delay(750);	
	}
	for(i=0;i<8;i++)
	{
		P1 = P0 = tatNguoc[i];
		delay(750);	
	}
	//-----------------
	for(i=0;i<8;i++)
	{
		P1 = sangXuoi[i];
		delay(750);	
	}
	for(i=0;i<8;i++)
	{
		P0 = sangNguoc[i];
		delay(750);	
	}
	for(i=0;i<8;i++)
	{
		P0 = tatXuoi[i];
		delay(750);	
	}
	
	for(i=0;i<8;i++)
	{
		P0 = tatNguoc[i];
		delay(750);	
	}
	//---------------
	for(i=0;i<8;i++)
	{
		P0 = sangXuoi[i];
		delay(750);	
	}
	for(i=0;i<8;i++)
	{
		P1 = sangNguoc[i];
		delay(750);	
	}
	for(i=0;i<8;i++)
	{
		P1 = tatXuoi[i];
		delay(750);	
	}
	
	for(i=0;i<8;i++)
	{
		P1 = tatNguoc[i];
		delay(750);	
	}
}
void halfBlink()
{
	P0=P1=0xff;
	P1=0; delay(750); P1=0xff; delay(750); P1=0; delay(750); P1=0xff; delay(750); P1=0;
	P0=0; delay(750); P0=0xff; delay(750); P0=0; delay(750); P0=0xff; delay(750); P0=0;
}
void main()
{
		Set_All_GPIO_Quasi_Mode;
	while(1)
	{
		Blink(5);
		nhayXenKeTraiTim(6);
		nhayVeTraiTim();
		nhayVeChu();
		nhayXenKeTrongNgoai();
		nhayXenKeTrongNgoai();
		nhayXenKeTrongNgoai();
		nhayXenKeTrongNgoai();
		//nhayDienTen();
		Blink(4);
		chay1Bong1();
		chay1Bong1();
		chayVongTronXuoi1();
		Blink(1);
		chayVongTronNguoc1();
		nhayXenKeTraiTim(10);
		chayTen();
		veTraiTim2();
		veTraiTim();
		nhayDienTen2();
		nhayVeTraiTim2();
		
		veTraiTim2();
		veTraiTim3();
		veTraiTim4();
		veTraiTim3();
		veTraiTim4();
		saoBang();
		halfBlink();
		nhayCham();
	}
}
