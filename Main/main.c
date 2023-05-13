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
for(i=0;i<50;i++)
           {
             x = UART1_ReadChar();
             command[i]=x;
           }

           token = strtok(command,d);

           i = 0;
           while(token != NULL)
           {

             if(i==8)
             {
               break;
             }

             strcpy(f[i],token);
             i++;
             token = strtok(NULL,d);

           }

           speed = atof(f[6]);

           if( (strcmp(f[1],"A")==0 )  & ( speed > 0.6 ) )
           {



                 start_lat_tot = latitude_To_Decimal_Degree();
                 start_long_tot = longitude_To_Decimal_Degree();

                 end_lat_tot=30.123338;
                 end_long_tot=31.367355;

                 dist1 = fabs(getDistance(start_lat_tot,start_long_tot,end_lat_tot,end_long_tot) - 2.5);

                 if(start2_lat_tot!=0)
                 {
                   dist2 = getDistance(start2_lat_tot,start2_long_tot,start_lat_tot,start_long_tot);
                   total_Distance += dist2;
                 }
                 else
                 {
                   displacement=dist1;
                 }

                 if(dist1<0.5)
                 {
									 if(check==0)
									 {
										 distance_final = total_Distance;	
										 check = 1;
									 }
				
                   Output(GREEN);
                 }
                 else if(dist1<5)
                 {
                   Output(YELLOW);
                 }
                 else
                 {
                  Output(RED);
                 }

           }

      }
      else
      {
        cnt=0;
      }

 }


}

