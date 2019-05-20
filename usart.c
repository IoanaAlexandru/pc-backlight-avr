#include "usart.h"

/*
 * Functie de initializare a controllerului USART
 */
void USART0_init()
{
    /* seteaza baud rate la 9600 */
    UBRR0H = 0;
    UBRR0L = 103;

    /* porneste transmitatorul si receptorul */
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    /* seteaza formatul frame-ului: 8 biti de date, 1 bit de stop, paritate para */
    UCSR0C = (1 << UPM01) | (3 << UCSZ00);
}

/*
 * Functie ce transmite un caracter prin USART
 *
 * @param data - caracterul de transmis
 */
void USART0_transmit(unsigned char data)
{
    /* asteapta pana bufferul e gol */
    while(!(UCSR0A & (1 << UDRE0)));

    /* pune datele in buffer; transmisia va porni automat in urma scrierii */
    UDR0 = data;
}

/*
 * Functie ce primeste un caracter prin USART
 *
 * @return - caracterul primit
 */
unsigned char USART0_receive()
{
    /* asteapta cat timp bufferul e gol */
    while(!(UCSR0A & (1 << RXC0)));

    /* returneaza datele din buffer */
    return UDR0;
}
