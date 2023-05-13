
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

