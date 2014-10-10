#include <main.h>

//int estadoSensor = 0;
float potenciometro = 0;
float voltaje = 0;
float valorPwm = 0;
int16 timer=0;
int16 segundo=0;
//short frec = false;
#INT_RTCC                           //Interrupcion de Timer0
void interrupcionTimer0(){
set_timer0(131);                    //Se carga timer0 com valor de 131
//frec = !frec;
timer++;                

if (timer==8000){                    //Si timer = 8000 cada segundo
output_toggle(PIN_B3);
segundo++;
timer=0;
}
}


#INT_RB                                //Interrupcion por cambio de estado del prueto B de RB4-RB7
void interrupcionSensor(){
if (input(PIN_B4)==1){
   output_low(PIN_B1);
   //output_high(PIN_A1);
   //output_low(PIN_A2);
   if (segundo != 0){
      printf("Bloqueado %Ld Segundos \n\r ", segundo);
      segundo=0;
   } 
}
else if(input(PIN_B4)==0){
   output_high(PIN_B1);
   //output_low(PIN_A1);
   //output_low(PIN_A2);
   if (segundo != 0){
      printf("Desbloqueado %Ld Segundos \n\r ", segundo);
      segundo=0;
   }
}
}
void main()
{
   set_tris_a(0x01); 
   set_tris_b(0x10);
   set_tris_c(0x00);
   output_a(0x00);
   output_b(0x00);
   output_c(0x00);
   ENABLE_INTERRUPTS(INT_RB);    // Habilita interrupcion por cambio de estado.
   ENABLE_INTERRUPTS(int_rtcc);  // Habilita interrupcion timer0.
   ENABLE_INTERRUPTS(GLOBAL);    //Habilita las interrupciones globales.
   SETUP_ADC_PORTS(RA0_ANALOG);  //Configura adc en en PIN A0
   setup_adc(ADC_CLOCK_DIV_32);  
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_1);  //
   set_timer0(131);
   while(TRUE)
   {
      
      set_adc_channel(0);       //      lee adc de canal 0 en RA0
      delay_us(10);              
      potenciometro=read_adc();  //se agrega el valor de lectura a la variable potenciometro.
      voltaje=potenciometro*5.0/1023.0;   //
      valorPwm=voltaje*20.0;
      pwm_set_duty_percent(valorPwm);
     
     
     /*
      if (frec){
          output_high(PIN_C0);
      }
      else {
         output_low(PIN_C0);
      }
      
      output_high(PIN_A1);
      output_low(PIN_A2);
     */ 
   }

}





