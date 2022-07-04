#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int max_milliseconds = 500;
int milliseconds = 0;
int main(void)
{
    DDRD = (1 << 4) | 1 << 3;
    sei();
    TCCR0A = (1 << WGM01);
    OCR0A = 249;
    TIMSK0 = (1 << OCIE0A);
    TCCR0B = 0b00000011;
}

ISR(TIMER0_COMPA_vect)
{
    milliseconds++;
    if (milliseconds > max_milliseconds)
    {
        milliseconds = 0;
        PORTD ^= 1 << 4;
    }
}