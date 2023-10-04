/*
 ============================================================================
 Name        	: LCD.c
 
 Interface		:
 		D0		-	P1.16
		D1		-	P1.17
		D2		-	P1.18
		D3		-	P1.19
		D4		-	P1.20
		D5		-	P1.21
		D6		-	P1.22
		D7		-	P1.23
		RS		-	P1.24
		EN		-	P1.25
		RW		-	GND
 ============================================================================
 */

#include<lpc214x.h>
#define LCD_PORT 0x00FF0000
#define EN 1<<24					//define RS pin
#define RS 1<<25					//define EN pin
#define LCD_SHIFT 16				//shift data by LCD_SHIFT bits


void delay(unsigned int time)
{
	int i,j;
	for(i=0;i<time;i++)
		for(j=0;j<200;j++);
}

void LCD_strobe()				   //Enable pulse
{
	delay(100);
	IOSET1 = EN;
	delay(100);
	IOCLR1 = EN;
	delay(100);
}

void LCD_data(unsigned char ch)			   //function to send data
{
	IOCLR1 = LCD_PORT;					   //clear LCD pins
	IOSET1 = ch<<LCD_SHIFT;				   //shift data and set only the data bits
	IOSET1 = RS;						   //RS =1
	LCD_strobe();						   //EN pulse
}

void LCD_cmd(unsigned char ch)			   //function to send command
{
	IOCLR1 = LCD_PORT;
	IOSET1 = ch<<LCD_SHIFT;
	IOCLR1 = RS;						  //RS = 0
	LCD_strobe();						  //EN pulse
}

void LCD_init()
{
	PINSEL2 &= 0xFFFFFFF7;

	IODIR1 = LCD_PORT | RS | EN;		  //set the pins as output

	LCD_cmd(0x38);						 //8bit use both lines
	LCD_cmd(0x06);						 //Entry mode
	LCD_cmd(0x0C);						 //display ON cursor OFF
	LCD_cmd(0x01);						 //Clear display
	LCD_cmd(0x80);						 //cursor at 1st line 1st position
}

void LCD_display(int row, int pos, unsigned char *ch)
{
	unsigned char temp;

	if(row==1)
	{
		temp = 0x80 | (pos-1);			 //set cursor at 1st line pos position
	}
	else
	{
		temp = 0xC0 | (pos-1);			//set cursor at 2nd line pos position
	}
	LCD_cmd(temp);
	while(*ch)							//while data is valid, display the string
		LCD_data(*ch++);
}


int main()
{
IODIR0=0xffffffff;
	LCD_init();									//initialize LCD
	LCD_display(1,2,"RTOS LAB");			//display on 1st line 2nd position
	LCD_display(2,5,"2022");			//display on 2nd line 3rd position									//stop here
	int a;
	a=0x00001000;
	
	
	while(1)
	{
	IOSET0=a;
	delay(150);
	IOCLR0=a;
	
		if(a==0x00080000)
			a=0x00001000;
		else
			a=a<<1;
	}
	return 0;
}
