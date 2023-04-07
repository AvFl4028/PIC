#include <teclado matricial.h>

void initPins() {
   bit_clear(TRISA, 0);
   bit_clear(TRISA, 1);
   bit_clear(TRISA, 2);
   bit_clear(TRISA, 3);

   bit_clear(PORTA, 0);
   bit_clear(PORTA, 1);
   bit_clear(PORTA, 2);
   bit_clear(PORTA, 3);

   bit_clear(TRISB, 0);
   bit_clear(TRISB, 1);
   bit_clear(TRISB, 2);
   bit_clear(TRISB, 3);

   bit_clear(PORTB, 0);
   bit_clear(PORTB, 1);
   bit_clear(PORTB, 2);
   bit_clear(PORTB, 3);

   bit_set(TRISB, 4);
   bit_set(TRISB, 5);
   bit_set(TRISB, 6);
   bit_set(TRISB, 7);
}

void contador(int i) {
    switch (i) {
    case 0:
        bit_clear(PORTA, 0);
        bit_clear(PORTA, 1);
        bit_clear(PORTA, 2);
        bit_clear(PORTA, 3);
        break;

    case 1:
        bit_set(PORTA, 0);
        bit_clear(PORTA, 1);
        bit_clear(PORTA, 2);
        bit_clear(PORTA, 3);
        break;

    case 2:
        bit_clear(PORTA, 0);
        bit_set(PORTA, 1);
        bit_clear(PORTA, 2);
        bit_clear(PORTA, 3);
        break;

    case 3:
        bit_set(PORTA, 0);
        bit_set(PORTA, 1);
        bit_clear(PORTA, 2);
        bit_clear(PORTA, 3);
        break;

    case 4:
        bit_clear(PORTA, 0);
        bit_clear(PORTA, 1);
        bit_set(PORTA, 2);
        bit_clear(PORTA, 3);
        break;

    case 5:
        bit_set(PORTA, 0);
        bit_clear(PORTA, 1);
        bit_set(PORTA, 2);
        bit_clear(PORTA, 3);
        break;

    case 6:
        bit_clear(PORTA, 0);
        bit_set(PORTA, 1);
        bit_set(PORTA, 2);
        bit_clear(PORTA, 3);
        break;

    case 7:
        bit_set(PORTA, 0);
        bit_set(PORTA, 1);
        bit_set(PORTA, 2);
        bit_clear(PORTA, 3);
        break;

    case 8:
        bit_clear(PORTA, 0);
        bit_clear(PORTA, 1);
        bit_clear(PORTA, 2);
        bit_set(PORTA, 3);
        break;

    case 9:
        bit_set(PORTA, 0);
        bit_clear(PORTA, 1);
        bit_clear(PORTA, 2);
        bit_set(PORTA, 3);
        break;

    case 10:
        bit_clear(PORTA, 0);
        bit_set(PORTA, 1);
        bit_clear(PORTA, 2);
        bit_set(PORTA, 3);
        break;

    case 11:
        bit_set(PORTA, 0);
        bit_set(PORTA, 1);
        bit_clear(PORTA, 2);
        bit_set(PORTA, 3);
        break;

    case 12:
        bit_clear(PORTA, 0);
        bit_clear(PORTA, 1);
        bit_set(PORTA, 2);
        bit_set(PORTA, 3);
        break;

    case 13:
        bit_set(PORTA, 0);
        bit_clear(PORTA, 1);
        bit_set(PORTA, 2);
        bit_set(PORTA, 3);
        break;

    case 14:
        bit_clear(PORTA, 0);
        bit_set(PORTA, 1);
        bit_set(PORTA, 2);
        bit_set(PORTA, 3);
        break;

    case 15:
        bit_set(PORTA, 0);
        bit_set(PORTA, 1);
        bit_set(PORTA, 2);
        bit_set(PORTA, 3);
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
      for (int i = 0; i < 4; i++)
      {
         bit_set(PORTB, i);

         if(bit_test(PORTB, 4) == 1 && bit_test(PORTB, 2)){
                contador(1);
         }
         else if (bit_test(PORTB, 5) == 1 && bit_test(PORTB, 2)) {
             contador(2);
         }
         else if (bit_test(PORTB, 6) == 1 && bit_test(PORTB, 2)) {
             contador(3);
         }
         else if (bit_test(PORTB, 4) == 1 && bit_test(PORTB, 1)) {
             contador(4);
         }
         else if (bit_test(PORTB, 5) == 1 && bit_test(PORTB, 1)) {
             contador(5);
         }
         else if (bit_test(PORTB, 6) == 1 && bit_test(PORTB, 1)) {
             contador(6);
         }
         else if (bit_test(PORTB, 4) == 1 && bit_test(PORTB, 0)) {
             contador(7);
         }
         else if (bit_test(PORTB, 5) == 1 && bit_test(PORTB, 0)) {
             contador(8);
         }
         else if (bit_test(PORTB, 6) == 1 && bit_test(PORTB, 0)) {
             contador(9);
         }
         else {
             contador(0);
         }

         while(bit_test(PORTB, 4) == 1 && bit_test(PORTB, i)){}

         while (bit_test(PORTB, 5) == 1 && bit_test(PORTB, i)) {}

         while (bit_test(PORTB, 6) == 1 && bit_test(PORTB, i)) {}

         while (bit_test(PORTB, 7) == 1 && bit_test(PORTB, i)) {}
         delay_ms(10);
         bit_clear(PORTB, i);
         delay_ms(10);
      }
   }
}
