/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 3/28/2021
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#include <delay.h>
// Declare your global variables here
float buttons(float);
void main(void)
{
float f = 0.01;
DDRA = 0x00;
PORTA = 0xFF;
DDRC = 0xFF;
PORTC = 0x00;

while (1)
      {
      if(PINA.0==0){
          while(1){ 
          //100HZ
              PORTC = 0b00000000;   
              delay_ms(f);    
              PORTC = 0b00000001; 
              delay_ms(f);  
              f = buttons(f);
          } 
      }

      }
}
float buttons(float f0){
    //250HZ
     if(PINA.2==0){
     return 0.004;
     }              
     //500Hz
     if(PINA.3==0){
     return 0.002;
     }     
     //1000Hz
     if(PINA.4==0){
     return 0.001;
     }   
     //100HZ
     if(PINA.1==0){
     return 0.01;
     }
     else{
     return f0;
     }
}
