#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define clock_frequency 16000000
#define UBR_register ((clock_frequency / 16 / BAUD) - 1)

int main(void)
{
    UBRR0L = UBR_r egister;
    UBRR0H = UBR_register >> 8;
    UCSR0B = 1 << TXEN0;
    UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
    while (1)
    {
        UDR0 = 0b00111000;
        _delay_ms(2000);
    }
}