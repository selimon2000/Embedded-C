#include <avr/io.h>
#include <avr/interrupt.h>
volatile int adc_value;

ISR(ADC_vect)
{
    adc_value = ADC;
}

int main(void)
{
    DDRB = 1 << 1;
    DDRB = 0xFF;
    TCCR1A = 0b10100010;
    TCCR1B = 0b10011100;
    ICR1 = 1249;
	ADMUX = (1 << REFS0); //OR: ADMUX = (1 << 6);
    ADCSRA = 0b11101110;
    sei();
    while (1)
    {
        OCR1A = (0.122 * (adc_value)) + 31.25;
    }
}