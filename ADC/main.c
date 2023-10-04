#include "adc.h"
#include "LCD.h"
#include <stdio.h>

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
		for(j=0;j<5000;j++);
}

int main()
{
	unsigned int temp;
	char buf[16];

	LCD_init();
	ADCInit();
	while(1)
	{
		temp = ADC_Read(1);							//read AN0.1
		sprintf(buf,"ADC result:0x%03X",temp);		//convert to string and store in a buffer
		LCD_display(1,1,buf);					   	//display buffer
		delay(20);
	}
}
