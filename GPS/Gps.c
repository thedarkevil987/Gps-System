#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "UART.h"
#include "GPS.h"
#include "stdint.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"


#define PI 3.14159265359



extern char a[9];
extern char f[9][17];




void get_Degree_From_Latitude(char e,char w)
{

 a[0]=e;
 a[1]=w;
 a[2]='\0';

}
void get_Degree_From_Longitude(char e,char w,char r)
{

 a[0]=e;
 a[1]=w;
 a[2]=r;
 a[3]='\0';

}

void get_mintues(char i, char j)
{

 char end = j+8;
 char k;

 for(k =0; k< end; k++)
 {
   a[k] = f[i][j++];
 }

}

float latitude_To_Decimal_Degree()
{
 float degree,latitude;

 get_Degree_From_Latitude(f[2][0],f[2][1]);
 degree = atof(a);

 get_mintues(2,2);
 latitude = degree + (atof(a)/60);

 return latitude;

}

float longitude_To_Decimal_Degree()
{
 float degree,longitude;

 get_Degree_From_Longitude(f[4][0],f[4][1],f[4][2]);
 degree = atof(a);

 get_mintues(4,3);
 longitude = degree + (atof(a)/60);

 return longitude;
}
