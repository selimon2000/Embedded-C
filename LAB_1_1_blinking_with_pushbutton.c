#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = (1<<2|1<<3);
    PORTD = (1<<2);

    while (1)
    {
        if ((PIND & (0b00000100)) == 0b00000100) //if button is unpressed
        {
            PORTD^=1<<3;
            _delay_ms(500);
        }
    }
}