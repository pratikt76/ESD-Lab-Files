#ifndef LCD_H
	#define LCD_H

	void LCD_init(void);
	void LCD_display(int, int, unsigned char*);
	void LCD_data(unsigned char);
	void LCD_cmd(unsigned char);

#endif
