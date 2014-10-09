#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(e)  
#use rs232(baud=9600, xmit=pin_c6,rcv=pin_c7, parity=N, bits=8)
#use pwm(CCP1,TIMER=2,FREQUENCY=38000,DUTY=10)
