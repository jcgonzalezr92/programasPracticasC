#include <16F877a.h>  
#device adc=10
#FUSES NOWDT, XT, NOPUT, NOPROTECT, NOBROWNOUT, NOLVP, NOCPD, NOWRT, NODEBUG 
#use delay(clock=4000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(e)  
#use rs232(baud=9600, xmit=pin_c6,rcv=pin_c7, parity=N, bits=8)

int estadoSensor = 0;
float potenciometro;
float voltaje;
float valorPwm;
int16 timer=0;
int16 segundo=0;

#INT_RTCC
void interrupcionTimer0(){
set_timer0(6);
timer++;

if (timer==250){
output_toggle(PIN_B3);
segundo++;
timer=0;
}
}


#INT_RB
void interrupcionSensor(){
//tadoSensor=input(PIN_B1);
if (input(PIN_B4)==1){
output_low(PIN_B1);
printf("Desbloqueado %Ld \n", segundo);
segundo=0;
}
else if(input(PIN_B4)==0){
output_high(PIN_B1);
printf("Bloqueado %Ld \n", segundo);
segundo=0;
}
}
void main(){
	set_tris_b(0x10);
	set_tris_a(0x01);
	set_tris_c(0x00);
	output_b(0x00);
	output_a(0x00);
	output_c(0x00);
	ENABLE_INTERRUPTS(INT_RB);
	ENABLE_INTERRUPTS(int_rtcc);
	ENABLE_INTERRUPTS(GLOBAL);
	SETUP_ADC_PORTS(RA0_ANALOG);
	setup_adc(ADC_CLOCK_DIV_32);
	setup_ccp2(CCP_PWM);
	setup_timer_2(T2_DIV_BY_1,25,1);			//prescales de 1, valor timer2 =25                       	
	set_pwm2_duty(0.000000526);
	setup_timer_0(RTCC_INTERNAL | RTCC_DIV_16);
	set_timer0(6);
while (1){
	set_adc_channel(0);                      
   delay_us(10);   
	potenciometro=read_adc();
	voltaje=potenciometro*5.0/1023.0;
	valorPwm=voltaje*200.0;
	//set_pwm2_duty(valorPwm);
	output_toggle(PIN_B2);
	delay_ms(500);
	
	//output_low(PIN_B2);
	//delay_ms(500);
	/*
	printf("Voltaje = %f \n" , voltaje);
	printf(" valorPwm = %f \n" , valorPwm);
	printf("Valor potenciometro = %f \n ", potenciometro);
	delay_ms(500);
*/

	
	}
}

