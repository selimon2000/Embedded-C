#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define clock_frequency 16000000
#define UBR_register ((clock_frequency / 16 / BAUD) - 1)

int main(void)
{
    UBRR0L = UBR_register;
    UBRR0H = UBR_register >> 8;
    UCSR0B = 1 << TXEN0;
    UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
    char message[] = "Hello World ";
    int message_length = sizeof(message) - 1;
    while (1)
    {
        for (int i = 0; i < message_length; i++)
        {
            UDR0 = message[i];
            _delay_ms(20);
        }
        _delay_ms(500);
    }
}