#INCLUDE <16f628a.h>   // Define el PIC16f628
#FUSES NOWDT      // Es un fuse que resetea el pic si este se cuelga.
#FUSES NOPROTECT  // Permite o bloque lectura del pic con un  programador
#FUSES NOLVP      // Anula pin de programacion RB4 y lo deja como I/O
#FUSES NOMCLR     // NOMCLR = PIN RA5 Input. MCLR=PIN RA5 como reset   
// ************************FUSES DEL RELOJ ************************************
//************************ PARA USAR EL OSCILADOR INTERNO DEL PIC *************
#FUSES INTRC_IO            // HABILITA el OSCILADOR INTERNO 
#USE DELAY(clock = 4000000, INTERNAL) // COMPLEMENTA EL FUSE INTRC_IO

#byte TRISB = 0x86
#byte PORTB = 0x06

void initPins(){
   bit_set(TRISB, 2);
   bit_clear(TRISB,0);
   bit_clear(PORTB, 0);
   bit_clear(TRISB,1);
   bit_clear(PORTB, 1);
}

void main(){
   initPins();
   while(true){
      if(bit_test(PORTB, 2) == 1){
      bit_set(PORTB, 1);
      bit_clear(PORTB, 0);
      delay_ms(500);
      bit_clear(PORTB, 1);
      bit_set(PORTB, 0);
      delay_ms(500);
      }
   }
}
