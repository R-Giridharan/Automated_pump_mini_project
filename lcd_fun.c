#include"defiine.h"
void lcd_init(void)
{
    IODIR0 = lcd | rs | e | motor;
    lcd_cmd(0x02);
    lcd_cmd(0x28);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
}


void lcd_data(unsigned char data)
{ IOCLR0= lcd;
IOSET0=(data&0xf0);
IOSET0=rs;
IOSET0=e;
delay_ms(2);
IOCLR0=e;
	
	IOCLR0= lcd;
IOSET0=((data<<4)&0xf0);
IOSET0=rs;
IOSET0=e;
delay_ms(2);
IOCLR0=e;
}

void lcd_cmd(unsigned char cmd)
{IOCLR0=lcd;
IOSET0=(cmd&0xf0);
IOCLR0=rs;
IOSET0=e;
delay_ms(2);
IOCLR0=e;
	
	IOCLR0=lcd;
IOSET0=((cmd<<4)&0xf0);
IOCLR0=rs;
IOSET0=e;
delay_ms(2);
IOCLR0=e;
}
void lcd_str(unsigned char*s)
{while(*s)
	lcd_data(*s++);
}
