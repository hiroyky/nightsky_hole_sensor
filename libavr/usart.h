/**
 * usart.h  AVR AtMega88P / AtMega168P����
 *
 * USART�ʐM�y��FT232RL���g����PC�Ƃ�USB�C���^�[�t�F�C�X�̃��C�u����
 * @author Hirokazu Yokoyama
 * @namespace USART
 *
 * Created: 2011/12/23 15:51:38
 *  Author: hirokazu
 */
#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include <avr/interrupt.h>

typedef enum USART_InitMode {
	// �ʏ�USART�ʐM
	NOMAL = 0,
	// ���M���荞�݂�����USART�ʐM������
	ALLOW_SEND_INTERRUPT = 1,
	// ��M���荞�݂�����USART�ʐM������
	ALLOW_RECIEVE_INTERRUPT = 2,
	// ���M��M���Ɋ��荞�݂�����USART�ʐM������
	ALLOW_SEND_AND_RECIEVE_INTERRUPT = 3
} USART_InitMode;


/**
* USART�����������܂��B
* �K�v�ɉ�����USART_sendBaudrate()�Ń{�[���[�g��ݒ肷��K�v������܂�
* @param mode ���荞�݂��s�����ǂ������w�肵�܂��B
*/
void USART_init(USART_InitMode mode);

/**
* �ʐM�ɂ�����{�[���[�g���w�肵�܂��B
* ���W�X�^UBRR0H�y��UBRR0L�ɓ��͂��܂��B�l�̓f�[�^�V�[�g���Q�l�ɂ��Ă��������B
* @param highBit UBRR0H�̒l
* @param lobBit UBRR0L�̒l
* �Q�l�l
*  1MHz���쎞�FhighBit = 0, lowBit = 12
*  8MHz���쎞�FhighBit = 0, lowBit = 104
*/
void USART_setBaudrate(uint8_t highBit, uint8_t lowBit);

void USART_sendData(uint8_t data);

uint8_t USART_recieveData();



void USART_binaryPrintf(unsigned char dat);

void USART_setSendInterruptListener(void (*func)(void));

void USART_setRecieveInterruptListener(void (*func)(uint8_t data));





#endif /* USART_H_ */