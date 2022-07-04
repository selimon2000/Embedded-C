#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = 1 << 2 | 1 << 3 | 1 << 4;
    PORTD = 1 << 2;
    while (1)
    {
        if ((PIND & (0b00000100)) == 0b00000100)
        {
            PORTD = 1 << 2 | 1 << 3;
            _delay_ms(500);
            PORTD ^= 1 << 3;
            _delay_ms(500);
        }

        else
        {
            PORTD = 1 << 2 | 1 << 4;
            _delay_ms(500);
            PORTD ^= 1 << 4;
            _delay_ms(500);
        }
    }
}