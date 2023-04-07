#include <16F628A.h>

#FUSES NOWDT      // Es un fuse que resetea el pic si este se cuelga.
#FUSES NOPROTECT  // Permite o bloque lectura del pic con un  programador
#FUSES NOLVP      // Anula pin de programacion RB4 y lo deja como I/O
#FUSES NOMCLR     // NOMCLR = PIN RA5 Input. MCLR=PIN RA5 como reset   

#FUSES INTRC_IO            // HABILITA el OSCILADOR INTERNO 
#USE DELAY(clock = 4000000, INTERNAL) // COMPLEMENTA EL FUSE INTRC_IO

#byte TRISA = 0x85
#byte PORTA = 0x05

#byte TRISB = 0x86
#byte PORTB = 0x06