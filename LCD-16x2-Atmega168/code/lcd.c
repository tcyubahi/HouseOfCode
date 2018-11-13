/*
* AUTHOR: TRESOR CYUBAHIRO
* 11 12 2018 
* Code to run a 16x2 LCD Display interfaced with ATmega168
*/

#include <avr/io.h>
#include <util/delay.h>

// LCD Definitions
#define		LCD_DATA_PORT		PORTB 
#define 	LCD_CONT_PORT		PORTD
#define 	LCD_RS 		PD2
#define 	LCD_RW 		PD3
#define 	LCD_EN 		PD4

// FUNCTION Definitions
void LCDDataWrite(char data);
void LCDCommandWrite( char command);
void LCDInit();
void LCDStringWrite( char *string);
void LCD_Clear();

int main(void)
{	

	LCDInit();

	while(1){

		LCDStringWrite("HOUSE of CODE");
		LCDCommandWrite(0xc0);
		LCDStringWrite("TUTORIAL");
		_delay_ms(5000);
		LCD_Clear();

	}

	return (0);
}


// LCD Data Write
void LCDDataWrite(char data)
{
	LCD_CONT_PORT=_BV(LCD_EN)|_BV(LCD_RS);// 1 on E, 1 on RS
	LCD_DATA_PORT=data;
	_delay_ms(1);
	LCD_CONT_PORT=_BV(LCD_RS);
	_delay_ms(1);
}

// LCD Command Write
void LCDCommandWrite(char command)
{
	LCD_CONT_PORT=_BV(LCD_EN); // 1 on E
	LCD_DATA_PORT=command;
	_delay_ms(1);
	LCD_CONT_PORT=0x00;
	_delay_ms(1);
}

// Configure LCD
	/* 
		0x38 - 2 lines 5X7 Mode command
		0x01 - Clear screen command
		0x06 - Shift cursor to right on incerement command
		0xe0 - Cursor blink command
		0x80 - focus cursor at beggining command
	*/

void LCDInit()
{
	DDRB = 0xff;
	DDRD = 0xff;

	LCDCommandWrite(0x38);
	LCDCommandWrite(0x01);
	LCDCommandWrite(0x06);
	LCDCommandWrite(0x0e);	
}

// Write String to LCD
void LCDStringWrite(char *string)
{
	while (*string)
	LCDDataWrite(*string++);
}

// Clear LCD's contents
void LCD_Clear()
{
	LCDCommandWrite(0x01);		
	_delay_ms(2);
	LCDCommandWrite(0x80);		
}

