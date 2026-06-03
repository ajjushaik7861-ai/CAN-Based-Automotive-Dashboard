/* 
 * File:   uart.h
 * Author: ajjus
 *
 * Created on 6 May, 2026, 1:06 PM
 */

#ifndef UART_H
#define	UART_H

void init_uart(void);
void putch(unsigned char byte);
int puts(const char *s);
unsigned char getch(void);
unsigned char getch_with_timeout(unsigned short max_time);
unsigned char getche(void);


#endif	/* UART_H */

