/*******************************************************************************
 * PROJECT		Tesla Model Z Prototype
 * AUTHOR(S)	David Leger
 * 				Dylan Wood
 * DATE			10 Mar, 2017
 *
 * FILE NAME	hw_interface.c
 * DESCRIPTION	Provides an abstraction layer to interface with the FRDM-K64
 * 				board without knowing the board's specific registers or
 * 				register masks.
 *
 ******************************************************************************/

#ifndef _HW_INTERFACESH_
#define _HW_INTERFACESH_

#include "math.h"

#include "./init.c"
#include "./utils.c"
#include "./../config.c"

int drive_mode = 0;
int cli_mode = 0;


/*******************************************************************************
 * UART0 INTERFACE
 ******************************************************************************/

void UART0_Putchar(char c) {
	while (!(UART0_S1 & UART_S1_TDRE_MASK));	// poll TDRE
	UART0_D = (uint8_t) c;						// put char in data register
}

char UART0_Getchar() {
	char c = '\0';
	char val;
	while (c != '\r') {
		val = c;
		while (!(UART0_S1 & UART_S1_RDRF_MASK));  // poll RDRE
		c = UART0_D; 		// fetch char from data register
		if (c > 0x20 && c != 0x7F) {
			UART0_Putchar(0x7F);
			UART0_Putchar(c);
		}
	}

	return val;		
}

void UART0_Putstring(char * s) {
	// put string of chars into the data register
	while (*s) {
		UART0_Putchar(*s);
		s++;
	}
}

// Logs strings to the console.
void cLog(char * string) {
	UART0_Putstring(string);
}

// gets a single character from the console.
char cGetValid(char * validChars) {
  char c;
  do {
    c = UART0_Getchar();
    if (!isValid(c, validChars)) {
    	cLog("\n\r\n\rINVALID INPUT! Please try again: ");
    }
  } while (c < 0x20 || (validChars[0] != '\0' && !isValid(c, validChars))); 
  // Wait for char within visible range.

  return c;
}

char cGet() {
  char * c = "\0";
  return cGetValid(c);
}

/*******************************************************************************
 * ADC0 INTERFACE
 ******************************************************************************/
unsigned short ADC_Convert() {
	ADC0_SC1A = 18 & ADC_SC1_ADCH_MASK; 	 //Write to SC1A to start conversion
	while(ADC0_SC2 & ADC_SC2_ADACT_MASK);    //Conversion in progress
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); //Until conversion complete
	ADC0_SC1A &= ~ADC_SC1_COCO_MASK;
	return ADC0_RA;
}


int getLightVal() {
	unsigned short adc_val = ADC_Convert();	//Value read from ADC0
	int light_val = (10 - ceil((adc_val / 0x3ff) * 10));
	//Represent this value to the nearest integer on a 0-9 scale
	return light_val;
}

/*******************************************************************************
 * DAC0 INTERFACE
 ******************************************************************************/

// Write's an integer corresponding to voltage to the DAC
// voltage = Vd / Vref * 4096
// Vd : Desired voltage
// Vref : Reference voltage (e.g. 3.3V)
void DAC0_Write(uint16_t voltage){
	DAC0_DAT0L = (voltage & 0x00FF);
	DAC0_DAT0H = ((voltage & 0x0F00) >> 8);
}

void setMotorSpeed(int speed) {
	DAC0_Write(speed);
}

/*******************************************************************************
 * ONBOARD LEDs
 ******************************************************************************/

void blueLED (int turnOn) {
	if (turnOn) GPIOB_PDOR &= ~(0x1 << 21);		// Turn on BLUE LED (PTB21)
	else GPIOB_PDOR |= 0x01 << 21;
}

void redLED (int turnOn) {
	if (turnOn) GPIOB_PDOR &= ~(0x1 << 22);		// Turn on RED LED (PTB22)
	else GPIOB_PDOR |= 0x01 << 22;
}

void greenLED (int turnOn) {
	if (turnOn) GPIOE_PDOR &= ~(0x1 << 26);		// Turn on GREEN LED (PTE26)
	else GPIOE_PDOR |= 0x01 << 26;
}

/*******************************************************************************
 * INTERRUPT HANDLERS
 ******************************************************************************/

// SW3 Handler
void PORTA_IRQHandler(void){
	//drive
	drive_mode = 1;
	cli_mode = 0;

	PORTA_ISFR = PORT_ISFR_ISF(0x10);
}

// SW2 Handler
void PORTC_IRQHandler(void){
	//config
	drive_mode = 0;
	cli_mode = 1;

	PORTC_ISFR = PORT_ISFR_ISF(0x40);
}

#endif
