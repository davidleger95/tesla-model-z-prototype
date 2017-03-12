/*******************************************************************************
 * PROJECT		Tesla Model Z Prototype
 * AUTHOR(S)	David Leger
 * 				Dylan Wood
 * DATE			10 Mar, 2017
 *
 * FILE NAME	init.c
 * DESCRIPTION	Functions to initialize the hardware interfaces including UART0,
 * 				GPIO, and ADC/DAC.
 *
 *******************************************************************************/

#ifndef _INITC_
#define _INITC_

#include "fsl_device_registers.h"

void UART0_Interface_Init() {
	uint16_t ubd;
	uint8_t temp;

	//Enable clk to the module via SIM_SCFC
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;

	//enable port
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

	//Configure port bits to be UARTx instead of GPIO
	PORTB_PCR16 |= PORT_PCR_MUX(3);
	PORTB_PCR17 |= PORT_PCR_MUX(3);

	//disable transmit en and receive en
	UART0_C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

	//config UART for 8 bits
	UART0_C1 = 0;

	//set baud rate
	ubd = (uint16_t)((21000*1000)/(9600 * 16));

	temp = UART0_BDH & ~(UART_BDH_SBR(0x1F));
	UART0_BDH = temp | (((ubd & 0x1F00) >> 8));		 // Upper half of baud rate
	UART0_BDL = (uint8_t)(ubd & UART_BDL_SBR_MASK);  // Lower half of baud rate

	//enable tx & rx
	UART0_C2 |= UART_C2_TE_MASK;
	UART0_C2 |= UART_C2_RE_MASK;
}

void GPIO_Init() {
	// Activate PTB and PTC
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTE_MASK;

	// Use ALT1 configuration for PTB and PTC2
	PORTA_PCR4  |= PORT_PCR_MUX(1) | PORT_PCR_ISF(0x0) | PORT_PCR_IRQC(0xA);
	PORTB_PCR21 |= PORT_PCR_MUX(1);
	PORTB_PCR22 |= PORT_PCR_MUX(1);
	PORTC_PCR6  |= PORT_PCR_MUX(1) | PORT_PCR_ISF(0x0) | PORT_PCR_IRQC(0xA);
	PORTE_PCR26 |= PORT_PCR_MUX(1);

	// Set BLUE LED (PTB21) to output (high)
	GPIOB_PDDR |= 0x1 << 21;
	GPIOB_PDDR |= 0x1 << 22;
	GPIOE_PDDR |= 0x1 << 26;
	// Set SW2 (PTC6) to input (low)
	GPIOC_PDDR = 0x0 << 6;
	// Set SW3 (PTA4) to input (low)
	GPIOA_PDDR = 0x0 << 4;
	// LED initially off (high)
	GPIOB_PSOR |= 0x1 << 21;
	GPIOB_PSOR |= 0x1 << 22;
	GPIOE_PSOR |= 0x1 << 26;

	// Clear ISFR flags
	PORTA_ISFR = PORT_ISFR_ISF(0x10);
	PORTC_ISFR = PORT_ISFR_ISF(0x40);
	// Enable Interrupts
	NVIC_EnableIRQ(PORTA_IRQn);
	NVIC_EnableIRQ(PORTC_IRQn);
}

void init() {
	UART0_Interface_Init();
	GPIO_Init();
}

#endif
