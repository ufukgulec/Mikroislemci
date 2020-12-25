#include <main.h>
#use delay(clock=20M)

#fuses BROWNOUT, HS, NOWDT, NOLVP

#define col1 pin_c4
#define col2 pin_c5
#define col3 pin_c6
#define col4 pin_c7

#define row1 pin_c0
#define row2 pin_c1
#define row3 pin_c2
#define row4 pin_c3

void kp_scan (void);

void main ()
 {
   output_b(0b00000000);
    
   while (true)
      {
      kp_scan();
    delay_ms(50);
      }
 }
void kp_scan(void)
{
   output_high(row1);
   output_high(row2);
   output_high(row3);
   output_high(row4);
   
   output_low(row1);
   if(input(col1)==0) output_b(0b00000110);//1
      
   output_high(row1); output_low(row2);
   if(input(col1)==0) output_b(0b01100110);//4
      
   output_high(row2); output_low(row3);
   if(input(col1)==0) output_b(0b00000111);//7
      
   output_high(row3); output_low(row4);
   if(input(col1)==0) output_b(0b00111001);//c
      
   output_high(row4); output_low(row1);
   if(input(col2)==0) output_b(0b01011011);//2
      
   output_high(row1); output_low(row2);
   if(input(col2)==0) output_b(0b01101101);//5
      
   output_high(row2); output_low(row3);
   if(input(col2)==0) output_b(0b01111111);//8
      
   output_high(row3); output_low(row4);
   if(input(col2)==0) output_b(0b00111111);//0
      
   output_high(row4); output_low(row1);
   if(input(col3)==0) output_b(0b01001111);//3
      
   output_high(row1); output_low(row2);
   if(input(col3)==0) output_b(0b01111101);//6
      
   output_high(row2); output_low(row3);
   if(input(col3)==0) output_b(0b01101111);//9
}
