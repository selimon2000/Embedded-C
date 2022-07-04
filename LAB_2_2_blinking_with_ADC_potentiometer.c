#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int max_milliseconds;
int milliseconds = 0;
int main(void)
{
    DDRD = 1 << 4 | 1 << 3;
    sei();
    TCCR0A = 1 << WGM01;
    OCR0A = 249;
    TIMSK0 = 1 << OCIE0A;
    TCCR0B = 0b00000011;
    ADMUX = 1 << 7;
    ADCSRA = 0b11101110;
    while (1)
    {
        PORTD |= (1 << PORTD4);
        _delay_ms(500);
        PORTD &= ~(1 << PORTD4);
        _delay_ms(500);
    }
}

ISR(TIMER0_COMPA_vect)
{
    max_milliseconds = (0.390625 * ADC)+100;
    milliseconds++;
    if (milliseconds > max_milliseconds)
    {
        milliseconds = 0;
        PORTD ^= 1 << 3;
    }
}

ISR(ADC_vect)
{
}