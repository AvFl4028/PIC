#include <pic16f628a.h>   // Incluye la biblioteca para el PIC16F628A

#define _XTAL_FREQ 4000000 // Frecuencia de reloj (4 MHz)

void main() {
   OSCCONbits.IRCF = 0b111; // Configura el oscilador interno a 8 MHz
   TRISBbits.TRISB0 = 0;    // Configura el pin RB0 como salida

   while(1) {               // Bucle infinito
      PORTBbits.RB0 = 1;    // Enciende el LED
      __delay_ms(500);      // Espera medio segundo
      PORTBbits.RB0 = 0;    // Apaga el LED
      __delay_ms(500);      // Espera medio segundo
   }
}

