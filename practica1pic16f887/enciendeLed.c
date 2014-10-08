#define<16f887.h>
#use delay(clock=4000000)
#fuses NOWDT, XT, NOPUT, NOPROTECT, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use fast_io(a)
void main(){
set_tris_a(0x00);
output_b(0x00);

while (true){
output_high(pin_a0);
delay_ms(500);
output_low(pin_a0);
delay_ms(500);
}
}
