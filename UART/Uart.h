
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
