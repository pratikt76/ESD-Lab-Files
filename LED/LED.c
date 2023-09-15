/********************************************************/
/* This Program is to demonstrate the LED Functionality */
/*******************************************************
Author 		: Ashish
Board 		: SBC_ARM7
Processor 	: LPC2148

LED Mapping 	: LED0 thru LED7 : P0.4 thru P0.11

Jumper Settings :

********************************************************/

#include<lpc214x.h>

//LED Mapping for the board
#define LED_SET IOSET0
#define LED_CLR IOCLR0
#define LED_DIR IODIR0
#define LED_IO  IOPIN0

#define LED_MASK 0x000FF000
#define LED0  12

void delay(unsigned int time)
{
unsigned int i,j;
	for(i = 0; i < time ;i++ )
	{
		for(j = 0; j < 5000 ; j++);
	}
}

int main(void)
{
int i,j;

 i = PINSEL0;				  // set the pin function for the pins as GPIO : 00
 PINSEL0 = (i & ~LED_MASK);	  //read , modify and write
 PINSEL0 = 0;

 LED_DIR = LED_MASK;			// set the direction of the pins as  output : 1

while(1)
{
 // LED Blinking
 for(i = 0; i < 4 ; i++)
 {
	LED_SET = LED_MASK;					// set the port pins to 1
	delay(150);
	LED_CLR = LED_MASK;					//clear the port pins to 0
	delay(150);
 }
 // LED Rolling
 for(i = 0 ; i < 4 ; i++)
 {
 	for(j = 0 ; j < 8; j++)
	{
		LED_SET = 1 << (LED0 + j);		 // set the port pins to 1
		delay(50);
	}
	for(j = 7 ; j >= 0; j--)
	{
		LED_CLR = 1 << (LED0 + j);		 //clear the port pins to 0
		delay(50);
	}
 }
 // LED SINGLE Rolling

 for(i = 0 ; i < 5 ; i++)
 {
 	for(j = 0 ; j < 8; j++)
	{
		LED_CLR = 1 << (LED0 + j);		  //clear the port pins to 0
		delay(50);
		LED_SET = 0xFF << (LED0 + j);		  // set the port pins to 1
		delay(50);
	}
	for(j = 7 ; j >= 0; j--)
	{
		LED_CLR = 1 << (LED0 + j);		  //clear the port pins to 0
		delay(50);
		LED_SET = 0xFF << (LED0 + j);		  // set the port pins to 1
		delay(50);
	}
 }

}

return 0;
}
