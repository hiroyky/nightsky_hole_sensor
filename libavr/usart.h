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
	NOMAL = 0x00,
	// ��M�������荞�݂�����
	RX_COMPLETION_INTERRUPT = 0x01,
    // ���M�������荞�݂�����
    TX_COMPLETION_INTERRUPT = 0x02,
	// ���M�f�[�^���W�X�^����ɂȂ������荞�݂�����
	DATA_REGISTER_EMPTY_INTERRUPT = 0x04
} USART_InitMode;


/**
* USART�����������܂��B�񓯊�����
* �{�[���[�g�Q�l�l:
* - 8MHz, 9600: 51
* - 1MHz, 9600: 6 
* @param baud �{�[���[�g�w��l(�l�̓f�[�^�V�[�g�Q�Ƃ̂��ƁB)
* @param mode ���荞�݂��s�����ǂ������w�肵�܂��B
*/
void USART_init(USART_InitMode mode, uint16_t baud);

/**
* USART��M�����̊��荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
* @param func ���s����֐�
*/
void USART_setRxCompletionInterruptListener(void (*func)(uint8_t data));

/**
* USART���M�����̊��荞�݂Ɏ��s����֐���ݒ肵�܂��B
* @param func ���s����֐�
*/
void USART_setTxCompletionInterruptListener(void (*func)(void));

/**
* USART�ő��M�f�[�^���W�X�^���󂫏�ԂɂȂ�A
* ���M���������������̊��荞�݂Ɏ��s����֐���ݒ肵�܂��B
* @param func ���s����֐�
*/
void USART_setDataRegisterEmptyInterruptListener(void (*func)(void));

/**
* 1�o�C�g�̃f�[�^�𑗐M���܂��B
* @param data ���M�f�[�^
*/
void USART_sendData(uint8_t data);

/**
* �f�[�^����M���܂��B
* @return ��M�f�[�^
*/
uint8_t USART_recieveData();

void USART_binaryPrintf(unsigned char dat);

#endif /* USART_H_ */