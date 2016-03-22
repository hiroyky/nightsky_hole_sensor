/**
 * usart.h  AVR AtMega88P / AtMega168P向け
 *
 * USART通信及びFT232RLを使ったPCとのUSBインターフェイスのライブラリ
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
	// 通常USART通信
	NOMAL = 0x00,
	// 受信完了割り込みを許可
	RX_COMPLETION_INTERRUPT = 0x01,
    // 送信完了割り込みを許可
    TX_COMPLETION_INTERRUPT = 0x02,
	// 送信データレジスタが空になった割り込みを許可
	DATA_REGISTER_EMPTY_INTERRUPT = 0x04
} USART_InitMode;


/**
* USARTを初期化します。非同期動作
* ボーレート参考値:
* - 8MHz, 9600: 51
* - 1MHz, 9600: 6 
* @param baud ボーレート指定値(値はデータシート参照のこと。)
* @param mode 割り込みを行うかどうかを指定します。
*/
void USART_init(USART_InitMode mode, uint16_t baud);

/**
* USART受信完了の割り込み時に実行する関数を設定します。
* @param func 実行する関数
*/
void USART_setRxCompletionInterruptListener(void (*func)(uint8_t data));

/**
* USART送信完了の割り込みに実行する関数を設定します。
* @param func 実行する関数
*/
void USART_setTxCompletionInterruptListener(void (*func)(void));

/**
* USARTで送信データレジスタが空き状態になり、
* 送信準備が整った時の割り込みに実行する関数を設定します。
* @param func 実行する関数
*/
void USART_setDataRegisterEmptyInterruptListener(void (*func)(void));

/**
* 1バイトのデータを送信します。
* @param data 送信データ
*/
void USART_sendData(uint8_t data);

/**
* データを受信します。
* @return 受信データ
*/
uint8_t USART_recieveData();

void USART_binaryPrintf(unsigned char dat);

#endif /* USART_H_ */