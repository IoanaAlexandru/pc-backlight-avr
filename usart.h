#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include <stdio.h>

/*
 * Functie de initializare a controllerului USART
 */
void USART0_init();

/*
 * Functie ce transmite un caracter prin USART
 *
 * @param data - caracterul de transmis
 */
void USART0_transmit(unsigned char data);

/*
 * Functie ce primeste un caracter prin USART
 *
 * @return - caracterul primit
 */
unsigned char USART0_receive();

#endif // USART_H_
