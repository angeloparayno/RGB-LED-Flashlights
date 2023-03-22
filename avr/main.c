#include <avr/io.h>

int main(void)
{
    // output pin (RGB LED)
    DDRD |= (1 << PD3);     // RED_LED
	DDRD |= (1 << PD4);     // GREEN_LED
	DDRD |= (1 << PD5);     // BLUE_LED
	
    // input pin (PUSH BUTTONS)
    DDRD &= ~(1 << PD0);    // SWITCH_1
    PORTD |= (1 << PD0);    // enable pull-up resistor
	DDRD &= ~(1 << PD1);    // SWITCH_2
    PORTD |= (1 << PD1);    // enable pull-up resistor
	DDRD &= ~(1 << PD2);    // SWITCH_3
    PORTD |= (1 << PD2);    // enable pull-up resistor
    
	for(;;)
    {
		//RED AND MAGENTA
        if (PIND & (1 << PD0)) {   // is SWITCH_1 open?
            PORTD |= (1 << PD3);   // switch is closed, switch RED LED on
			//PORTD |= (1 << PD5);   // switch is closed, switch BLUE LED on
        }
        else 
		{
			PORTD &= ~(1 << PD3);  // switch is open, switch RED LED off
			//PORTD &= ~(1 << PD5);  // switch is open, switch BLUE LED off
        }
		
		//GREEN AND YELLOW
        if (PIND & (1 << PD1)) {   // is SWITCH_2 open?
            PORTD |= (1 << PD4);   // switch is closed, switch GREEN LED on
			//PORTD |= (1 << PD3);   // switch is closed, switch RED LED on
        }
        else 
		{
			PORTD &= ~(1 << PD4);  // switch is open, switch GREEN LED off
			//PORTD &= ~(1 << PD3);  // switch is open, switch RED LED off
        }         

		//BLUE AND CYAN
        if (PIND & (1 << PD2)) {   // is SWITCH_2 open?
            PORTD |= (1 << PD5);   // switch is closed, switch BLUE LED on
			//PORTD |= (1 << PD4);   // switch is closed, switch GREEN LED on
        }
        else 
		{
			PORTD &= ~(1 << PD5);  // switch is open, switch BLUE LED off
			//PORTD &= ~(1 << PD4);  // switch is open, switch GREEN LED off
        }             		
    }
	return 0;
}