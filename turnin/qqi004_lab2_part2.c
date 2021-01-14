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
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	//unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char cntavail = 0x00; // Temproraty variable to hold the value of C
while(1) {
		// 1) Read input
		tmpA = PINA & 0x0F;
		if(tmpA==0x00){
			cntavail = 0x04;
		}
		if((tmpA==0x08)|(tmpA==0x04)|(tmpA==0x02)|(tmpA==0x01)){
			cntavail = 0x03;
		}
		if((tmpA==0x0C)|(tmpA==0x0A)|(tmpA==0x09)|(tmpA==0x06)|(tmpA==0x05)|(tmpA==0x03)){
			cntavail = 0x02;
		}
		if((tmpA==0x07)|(tmpA==0x0B)|(tmpA==0x0D)|(tmpA==0x0E)){
			cntavail = 0x01;
		}
		if(tmpA==0x0F){
			cntavail = 0x00;
		}
		
		
	// 3) Write output
PORTC = cntavail;	
	}
	return 0;
}

