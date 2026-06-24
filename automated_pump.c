#include<lpc21xx.h>
#include"fun_declar.h"
#include"lcd_fun.c"
#include"uart.c"
#include"delay.c"
#include"define.h"
typedef unsigned char u8 ;
int main()
{ 
	//u8 rtxbyte;
	u8 i;
	u8 flag=0;
	u8 c=0;
	PINSEL0=0x05;
	lcd_init();
	uart_config();
	lcd_cmd(0x80);
	lcd_str("Automated Water Pump");
	for(i=0;i<20;i++)
	{ lcd_cmd(0x18);
		delay_ms(100);
	}
	lcd_cmd(0x01);
	
	while(1)
{ 
	if((((IOPIN0>>sensor)&1)==1)&&(c==0)){
		flag=1;
		c++;
		
	}
	if((((IOPIN0>>sensor)&1)==0)&&(flag==0))
	{lcd_cmd(0x80);
		lcd_str("Field Dry state");
		IOSET0=motor;
		gsm_send_sms("dry state\r\n");
		flag=1;
		c=0;
	}
	if((((IOPIN0>>sensor)&1)==1)&&(flag==1))
	{lcd_cmd(0x80);
		lcd_str("Field Wet state");
		IOCLR0=motor;
		gsm_send_sms("Wet state\r\n");
		flag=0;
	}
	delay_ms(1000);
 }

	
 }


