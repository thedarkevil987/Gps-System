#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
#define YELLOW 0x0A
#define CR 0x0D


void Led_Init(void);

void Output(unsigned char color);

void RGB_setOutput(char data);

void LEDS_OFF(void);

