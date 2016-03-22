/*
 * nightsky_hall_sensor.c
 *
 * Created: 2016/02/07 23:10:45
 * Author : hirokazu
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <ExternalInterrupt.h>
#include <usart.h>

uint16_t hallCount = 0;

void initializeIO() {
    DDRB = 0xFF;
    DDRC = 0x00;
    DDRD = 0xFF;
    PORTB = 0x00;
    PORTC = 0xFF;
    PORTD = 0x00;
}

void onHallSense() {
    PORTB = PINB == 0x00 ? 0xFF : 0x00;
    hallCount++;
}

void onRxCompleted(uint8_t data) {
    printf("%d\n", hallCount);
    hallCount = 0;
}

int main(void) {
    initializeIO();

    External_initPCINT1(0xFF);
    External_setPCINT1Handler(*onHallSense);

    USART_init(RX_COMPLETION_INTERRUPT, 51);
    USART_setRxCompletionInterruptListener(*onRxCompleted);
    fdevopen(*USART_sendData, NULL);
    sei();
    while (1) {        
    }
}

