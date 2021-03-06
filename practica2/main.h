#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)
#use RS232(BAUD=9600, PARITY=N, BITS=8)
#use pwm(CCP1,TIMER=2,FREQUENCY=38000,DUTY=10)

