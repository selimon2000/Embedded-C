#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main()
{
    DDRB = 1 << 1;
    TCCR1A = 0b10100010;
    TCCR1B = 0b10011100;
    ICR1 = 1249;
    while (1)
    {
        OCR1A = 31.25; // 0.5ms
        _delay_ms(500);

        OCR1A = 31.25 * 3; // 1.5ms
        _delay_ms(500);

        OCR1A = 31.25 * 6; // 2.5ms
        _delay_ms(2500);
    }
}