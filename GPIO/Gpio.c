#include "tm4c123gh6pm.h"
#include "GPIO.h"


void Led_Init(void)
{

 SYSCTL_RCGCGPIO_R |=0x00000020;
 while((SYSCTL_PRGPIO_R & 0x20)==0){}
 GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
 GPIO_PORTF_CR_R|= 0x0E;
 GPIO_PORTF_AFSEL_R &= ~ 0x0E;
 GPIO_PORTF_AMSEL_R &= ~ 0x0E;
 GPIO_PORTF_PCTL_R &= ~ 0x0000FFF0;
 GPIO_PORTF_DEN_R |= 0x0E;
 GPIO_PORTF_DIR_R |= 0x0E;
 GPIO_PORTF_DATA_R &=~0x0E;

}


//
void Output(unsigned char color)
{

 LEDS_OFF();
 GPIO_PORTF_DATA_R |= color;

}


void RGB_setOutput(char data)
{

 GPIO_PORTF_DATA_R |= data;

}
void LEDS_OFF()
{

 GPIO_PORTF_DATA_R &= ~0x0E;

}
