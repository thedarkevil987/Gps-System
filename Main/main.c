#include "GPS.h"
#include "stdint.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


float total_Distance =0;
float displacement=0;
float distance_final = 0;

float start_lat_tot=0;
float start_long_tot=0;

float start2_lat_tot=0;
float start2_long_tot=0;

float end_lat_tot=0;
float end_long_tot=0;


float dist1=0;
float dist2=0;

char a[9];
char f[9][17];
char *token;




int main()
{

 unsigned char x;
 float check =0;
 int i=0;
 int cnt=0;
 const  char d[2]=",";

 char speed = 0;
 char command[50]={0};

 UART1_Init();
 Led_Init();

 while(1)
 {
      if(start_lat_tot !=0 )
      {
        start2_lat_tot = start_lat_tot;
        start2_long_tot = start_long_tot;
      }

      x = UART1_ReadChar();

      if(x=='$' & cnt==0)
      {
        cnt++;
      }
      else if(x=='G' & cnt==1)
      {
        cnt++;
      }
      else if(x=='P' & cnt==2)
      {
        cnt++;
      }
      else if(x=='R' & cnt==3)
      {
        cnt++;
      }
      else if(x=='M' & cnt==4)
      {
        cnt++;
      }
      else if(x=='C' & cnt==5)
      {
        cnt++;
      }
      else if(x==',' & cnt==6)
      {

