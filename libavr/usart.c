/*
 * usart.c
 *
 * Created: 2012/03/18 19:00:05
 *  Author: hirokazu
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "usart.h"

static void (*rxCompletionInterruptListener)(uint8_t data);
static void (*txCompletionInterruptListener)(void);
static void (*dataRegisterEmptyInterruptListener)(void);

void USART_init(USART_InitMode mode, uint16_t baud) {
    // �{�[���[�g�ݒ�
    UBRR0H = (uint8_t)(baud >> 8);
    UBRR0L = (uint8_t)(baud);    

    // �t���[���`���̐ݒ�
    // 8bit�f�[�^��, �Q��~�r�b�g
    UCSR0C = (1<< USBS0 | 3 << UCSZ00);

    // ����M����
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);

    // ���荞�݋���
    if (mode & RX_COMPLETION_INTERRUPT == 1) {
        UCSR0B |= (1<<RXCIE0);
    }
    if (mode & TX_COMPLETION_INTERRUPT == 1) {
        UCSR0B |= (1<<TXCIE0);
    }
    if (mode & DATA_REGISTER_EMPTY_INTERRUPT == 1) {
        UCSR0B |= (1<<UDRIE0);
    }
}

void USART_setRxCompletionInterruptListener(void (*func)(uint8_t data)) {
    rxCompletionInterruptListener = func;
}

void USART_setTxCompletionInterruptListener(void (*func)(void)) {
    txCompletionInterruptListener = func;
}

void USART_setDataRegisterEmptyInterruptListener(void (*func)(void)) {
    dataRegisterEmptyInterruptListener = func;
}

void USART_sendData(uint8_t data) {
    loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = data;
}

uint8_t USART_recieveData() {
    loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}


void USART_binaryPrintf(unsigned char dat) {
    for(uint8_t i = 0;i < sizeof(dat);++i) {
        if(dat & 0x01 == 1) {
			printf("1");
		}
		dat >>= 1;
	}
	printf("\n");
}

/**
 * ��M�������荞�ݓ���
 */
ISR(USART_RX_vect) {
    uint8_t data = USART_recieveData();
    rxCompletionInterruptListener(data);    
}

/**
 * ���M�������荞�ݓ���
 */
ISR(USART_TX_vect) {
    txCompletionInterruptListener();
}

/**
* ���M�f�[�^���W�X�^��t���O�̊��荞�ݓ���
*/
ISR(USART_UDRE_vect) {
    dataRegisterEmptyInterruptListener();
}