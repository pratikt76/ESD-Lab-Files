#include "keypad.h"
#include "LCD.h"

int main()
{
	unsigned char temp;

	kbdInit();
	LCD_init();		
	LCD_display(1,1,"Keypad");
	while(1)
	{
		temp = GetKey();
		if(temp != 0)
		{
			LCD_cmd(0xC0);
			LCD_data(temp);
		}
	}
}
