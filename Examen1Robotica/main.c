#include <main.h>
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(e)  
int interrupcion = input_b;
#int_rb
void interrupcionBoton(){
   if (interrupcion == 0x10){
      output_high(PIN_A0);
   } else if (interrupcion == 0x20){
      output_low(PIN_A0);
   } else {
      output_toggle(PIN_A1);
   }
}

void main()
{
   set_tris_a(0x00);
   set_tris_b(0x70); //0111 0000
   set_tris_c(0x00);
   output_a(0x00);
   output_b(0x00);
   output_c(0x00);
   ENABLE_INTERRUPTS(INT_RB);
   ENABLE_INTERRUPTS(GLOBAL);

   while(TRUE)
   {
      
   }

}
