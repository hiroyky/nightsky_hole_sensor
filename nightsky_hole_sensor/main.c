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
#include <timer.h>

#define TIRE_DIAMETER_INCH 26.0
static const unsigned int TIRE_CIRCUMFERENCE_CM = (TIRE_DIAMETER_INCH * 2.54) * 2.0 * 3.14;

unsigned int hallCount = 0;

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

/**
* タイマ割り込みでの動作。 8msec毎に実行される
*/
void onTimer() {
    unsigned int diffDistance = (hallCount >> 1) * TIRE_CIRCUMFERENCE_CM;
    printf("%u\n", diffDistance);
    hallCount = 0;
}

int main(void) {
    initializeIO();

    External_initPCINT1(0xFF);
    External_setPCINT1Handler(*onHallSense);
        TCCR1A = 0;
        TCCR1B = (1<<WGM12)|(1<<CS12);    //クロックの分周指定(256分周),CTC動作指定
        TCCR1C = 0;
        TIMSK1 = (1<<OCIE1A);    //A比較一致割り込み許可
        OCR1A  = 31250;        //カウントクロック数(比較一致)
    //Timer1_init(Timer_A_NONE, Timer_B_NONE, Timer1_CTC_OCR, Timer_PRESCALER_256);
    //Timer1_setTimerACriteria(31250);
    //Timer1_setTimerCaptureCriteria(31250);
    
    
    Timer1_setMatchAHandler(*onTimer);
    //Timer1_setTimerInterruptEnable(Timer1_INTERRUPT_MATCH_A);
    USART_init(NOMAL);
    USART_setBaudrate(0, 104);
    fdevopen(*USART_sendData, NULL);
    sei();
    while (1) {
        //printf("val: %d\n", bit_is_set(PINC, PINC0));
    }
}

