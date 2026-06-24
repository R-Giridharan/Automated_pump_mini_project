#include"fun_declar.h"

void uart_config(void)
{  PINSEL0|=0X05;
	U0LCR=0X83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0X03;
}
void uart_tx(unsigned char txbyte)
{U0THR=txbyte;
	while(((U0LSR>>5)&1)==0);
}
unsigned char uart_rx(void)
{
	while(((U0LSR>>5)&1)==0);
	return U0RBR;
}
void uart_tx_str(char *s)
{
    while(*s)        
        uart_tx(*s++); 
}
void gsm_send_sms(char *msg)
{
    uart_tx_str("AT\r");
    delay_ms(500);

    uart_tx_str("AT+CMGF=1\r");   
    delay_ms(500);

    uart_tx_str("AT+CMGS=\"+919514118859\"\r");  
    delay_ms(500);

    uart_tx_str(msg);

    uart_tx(26);   
    delay_ms(1000);
}
