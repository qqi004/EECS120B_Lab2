/*	Author: lab
 *  Partner(s) Name: Qi Qi
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; // Configure port A's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpD = 0x00; // Temporary variable to hold the value of D
	unsigned char total= 0x00; // Temporary variable to hold the balue of total weight
while(1) {
		// 1) Read input
		tmpA = PINA & 0xFF;
		tmpB = PINB & 0xFF;
		tmpC = PINC & 0xFF;
		tmpD = 0x00;
		total = tmpA + tmpB + tmpC;

// Compare if the total weight > 140 kg:	
		if(total > 0x8C){ // Set PD0 to 1 
			tmpD = 0x01;
		}
		else{
			tmpD = 0x00;
		}
// Compare the difference between A and C exceeds 80kg or not:
			if((tmpA - tmpC)>0x50){
				tmpD = tmpD | 0x02; // Set PD1 to 1
			}
			else if((tmpC - tmpA)>0x50){
				tmpD = tmpD | 0x02; // Set PD1 to 1
			}
//Set the remaining 6 bits on D to represent the approximation of the total weight:
		total = total>>2;
		total = total & 0xFC; // total & 1111 1100
		tmpD = tmpD | total; // D's final expression
		
	// 3) Write output
PORTD = tmpD;	
	}
	return 0;
}

