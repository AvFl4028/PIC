#include <display-7.h>

#define RESET PORTB, 0
#define LED1 PORTB, 1
#define LED2 PORTB, 2
#define LED3 PORTB, 3
#define LED4 PORTB, 4
#define LED5 PORTB, 5
#define LED6 PORTB, 6
#define LED7 PORTB, 7

int i;

void initPins() {
    bit_set(TRISB, 0);
    bit_clear(TRISB, 1);
    bit_clear(TRISB, 2);
    bit_clear(TRISB, 3);
    bit_clear(TRISB, 4);
    bit_clear(TRISB, 5);
    bit_clear(TRISB, 6);
    bit_clear(TRISB, 7);

    bit_clear(LED1);
    bit_clear(LED2);
    bit_clear(LED3);
    bit_clear(LED4);
    bit_clear(LED5);
    bit_clear(LED6);
    bit_clear(LED7);
}

void cero() {
   bit_set(LED1);      //a
   bit_set(LED2);      //b
   bit_set(LED3);      //c
   bit_set(LED4);      //d
   bit_set(LED5);      //e
   bit_set(LED6);      //f
   bit_clear(LED7);   //g
}

void uno() {
   bit_clear(LED1);   //a
   bit_set(LED2);      //b
   bit_set(LED3);      //c
   bit_clear(LED4);   //d
   bit_clear(LED5);   //e
   bit_clear(LED6);   //f
   bit_clear(LED7);   //g
}

void dos() {
   bit_set(LED1);      //a
   bit_set(LED2);      //b
   bit_clear(LED3);   //c
   bit_set(LED4);      //d
   bit_set(LED5);      //e
   bit_clear(LED6);   //f
   bit_set(LED7);      //g
}

void tres() {
   bit_set(LED1);      //a
   bit_set(LED2);      //b
   bit_set(LED3);      //c
   bit_set(LED4);      //d
   bit_clear(LED5);   //e
   bit_clear(LED6);   //f
   bit_set(LED7);      //g
}

void cuatro() {
   bit_clear(LED1);   //a
   bit_set(LED2);      //b
   bit_set(LED3);      //c
   bit_clear(LED4);   //d
   bit_clear(LED5);   //e
   bit_set(LED6);      //f
   bit_set(LED7);      //g
}

void cinco() {
   bit_set(LED1);      //a
   bit_clear(LED2);   //b
   bit_set(LED3);      //c
   bit_set(LED4);      //d
   bit_clear(LED5);   //e
   bit_set(LED6);      //f
   bit_set(LED7);      //g
}

void seis() {
   bit_set(LED1);      //a
   bit_clear(LED2);   //b
   bit_set(LED3);      //c
   bit_set(LED4);      //d
   bit_set(LED5);      //e
   bit_set(LED6);      //f
   bit_set(LED7);      //g
}

void siete() {
   bit_set(LED1);      //a
   bit_set(LED2);      //b
   bit_set(LED3);      //c
   bit_clear(LED4);   //d
   bit_clear(LED5);   //e
   bit_clear(LED6);   //f
   bit_clear(LED7);   //g
}

void ocho() {
   bit_set(LED1);      //a
   bit_set(LED2);      //b
   bit_set(LED3);      //c
   bit_set(LED4);      //d
   bit_set(LED5);      //e
   bit_set(LED6);      //f
   bit_set(LED7);      //g
}

void nueve() {
   bit_set(LED1);      //a
   bit_set(LED2);      //b
   bit_set(LED3);      //c
   bit_clear(LED4);   //d
   bit_clear(LED5);   //e
   bit_set(LED6);      //f
   bit_set(LED7);      //g
}

void contador(int t) {
    switch (t)
    {
    case 0:
        cero();
        break;
    case 1:
        uno();
        break;
    case 2:
        dos();
        break;
    case 3:
        tres();
        break;
    case 4:
        cuatro();
        break;
    case 5:
        cinco();
        break;
    case 6:
        seis();
        break;
    case 7:
        siete();
        break;
    case 8:
        ocho();
        break;
    case 9:
        nueve();
        break;
    default:
        break;
    }
}

void main()
{
   initPins();
   while(TRUE)
   {
       if (bit_test(RESET) == 1) {
           if (i == 9)
           {
               i = 0;
           }
           else {
               i++;
           }
           contador(i);
       }
       delay_ms(100);
   }
}
