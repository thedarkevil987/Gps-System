#include "tm4c123gh6pm.h"
#include "UART.h"





void UART1_Init(void)
{

 SYSCTL_RCGCUART_R|=0x02;
 SYSCTL_RCGCGPIO_R|=0x02;
 while((SYSCTL_PRGPIO_R&0x02)==0){}
 UART1_CTL_R=0;
 UART1_IBRD_R=0x68;
 UART1_FBRD_R=0x0B;
 UART1_LCRH_R=0x070;
 UART1_CTL_R=0x0301;
 GPIO_PORTB_AFSEL_R|=0x03;
 GPIO_PORTB_PCTL_R=(GPIO_PORTB_PCTL_R&0xFFFFFF00)|0x00000011;
 GPIO_PORTB_DEN_R|=0x03;
 GPIO_PORTB_AMSEL_R&=~0x03;

}


char UART1_ReadChar()
{

 while((UART1_FR_R&0x10)!=0){}

 return (char)UART1_DR_R &0xFF;

}


void UART1_WriteChar(char data)
{

 while((UART1_FR_R&0x20)!=0){}

 UART1_DR_R=data;

}

void UART1_WriteString(char *str)
{

  while(*str)
  {
    UART1_WriteChar(*str);
    str++;
  }

}

void UART1_ReadString(char *str, char stopCh)
{
	char c = UART1_ReadChar();

	while(c && c != stopCh)
    {
		*str = c;
		str++;
		c = UART1_ReadChar();
	}
	*str = 0x00;

}
