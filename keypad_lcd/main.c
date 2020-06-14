#include<reg51.h>


sbit RS=P2^0;
sbit RW=P2^1;
sbit EN=P2^2; 


sbit R1=P3^0;
sbit R2=P3^1;
sbit R3=P3^2;
sbit R4=P3^3;
sbit C1=P3^4;
sbit C2=P3^5;
sbit C3=P3^6;
sbit C4=P3^7;


void lcd_init(void);
void lcd_command(unsigned char a);
void lcd_data(unsigned char b);
void delay(unsigned int c);
void send_string(unsigned char *ch);

unsigned char Keypad(void);

int main()
{
	//setting ports as output
	P1=0x00;
	P2=0x00;
	P3=0xF0;
	lcd_init();
	delay(1);
	send_string("HI evryone");
	lcd_command(0xC0);//next line
	send_string("sushant");
	lcd_command(0x01);
	while(!(Keypad()));
	
}
void lcd_init()
{
	lcd_command(0x01);//clear display
	lcd_command(0x06);//shift display to right
	lcd_command(0x0C);//disp on cursor off
	lcd_command(0x38);//5*7matrix
	lcd_command(0x80);//take control to beginning
}
void lcd_command(unsigned char a)
{
	P1=a;
	RS=0;
	RW=0;
	EN=1;
	delay(1);
	EN=0;
}
void lcd_data(unsigned char b)
{
	P1=b;
	RS=1;
	RW=0;
	EN=1;
	delay(1);
	EN=0;
}
void send_string(unsigned char *ch)
{
	while(*ch != '\0')
	{
		lcd_data(*ch);
		ch++;
	}
}
void delay(unsigned int c)
{
	unsigned int b;
	for(b=0;b<1000*c;b++);
}

unsigned char Keypad(void)
{
	C1=C2=C3=C4=1;
	
	//for r1
	
	R1=0;
	R2=R3=R4=1;
	if(C1==0)
	{
		delay(1);
		lcd_data('7');
		while(C1==0);
	}
	if(C2==0)
	{
		delay(1);
		lcd_data('8');
		while(C2==0);
	}
	if(C3==0)
	{
		delay(1);
		lcd_data('9');
		while(C3==0);
	}
	if(C4==0)
	{
		delay(1);
		lcd_data('/');
		while(C4==0);
	}
	
	//for r2
	
		
	R2=0;
	R1=R3=R4=1;
	if(C1==0)
	{
		delay(1);
		lcd_data('4');
		while(C1==0);
	}
	if(C2==0)
	{
		delay(1);
		lcd_data('5');
		while(C2==0);
	}
	if(C3==0)
	{
		delay(1);
		lcd_data('6');
		while(C3==0);
	}
	if(C4==0)
	{
		delay(1);
		lcd_data('*');
		while(C4==0);
	}
	//for R3
	R3=0;
	R1=R2=R4=1;
	if(C1==0)
	{
		delay(1);
		lcd_data('1');
		while(C1==0);
	}
	if(C2==0)
	{
		delay(1);
		lcd_data('2');
		while(C2==0);
	}
	if(C3==0)
	{
		delay(1);
		lcd_data('3');
		while(C3==0);
	}
	if(C4==0)
	{
		delay(1);
		lcd_data('-');
		while(C4==0);
	}
	
	//for R4
	R4=0;
	R1=R2=R3=1;
	if(C1==0)
	{
		delay(1);
		lcd_command(0xC0);
		while(C1==0);
	}
	if(C2==0)
	{
		delay(1);
		lcd_data('0');
		while(C2==0);
	}
	if(C3==0)
	{
		delay(1);
		lcd_data('=');
		while(C3==0);
	}
	if(C4==0)
	{
		delay(1);
		lcd_data('+');
		while(C4==0);
	}
	
	return 0;
}