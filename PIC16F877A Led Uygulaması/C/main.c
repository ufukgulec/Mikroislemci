#include <main.h>

const int digit[8]={0x70,0x60,0x50,0x40,0x30,0x20,0x10,0x00};
void main()
{
int32 sayi=2447080;
int sayac=0;
int delay=50;
   while(TRUE)
   {
      int32 gecici=sayi;
      while(sayac<9&&gecici>0)
      {
         output_b(gecici%10 | digit[sayac]);    
         //delay_ms(delay);
         //delay-=10;
         sayac++;
         gecici=gecici/10;
      }
      sayac=0;
   }
}
