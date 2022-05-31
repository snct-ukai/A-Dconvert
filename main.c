#define F_CPU 20000000UL
#include <asf.h>
#include <util/delay.h>

int main (void)
{
	board_init();

	DDRB |= 0b00101111;
	DDRD = 0b00000000;

	PRR |= 0b00000001;

	ACSR &= 0b00111111;

	ADCSRB &= 0b10111111;

	ADCSRA |= 0b10000000;

	DIDR0 |= 0b00111111;

	DIDR1 |= 0b00000011;

	while(1){
		//_delay_us(0.32);
		//PORTB = (ACSR & 0b00100000) ? 0b00100000: 0b00000000;
		
		uint8_t output = 0b00000000;
		uint8_t num = 0b00001000;
		while(num){
			output |= num;
			PORTB = output;
			_delay_us(0.5);
			output ^= (ACSR & 0b00100000) ? 0 : num;
			num = num >> 1;
		}
	}
}
