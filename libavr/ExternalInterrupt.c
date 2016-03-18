/*
 * ExternalInterrupt.c
 *
 * Created: 2012/02/07 20:46:14
 *  Author: hirokazu
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "ExternalInterrupt.h"


// �O�����荞�ݔ������Ɏ��s�����֐�
static void (*External_INT0handler)(void);
static void (*External_INT1handler)(void);
static void (*External_PCINT0handler)(void);
static void (*External_PCINT1handler)(void);
static void (*External_PCINT2handler)(void);

/**
 * INT0(PD2)�O�����荞�݂̂��߂ɏ��������܂��B
 * �������A�ʓrsei()�Ŋ��荞�݂�������K�v������܂��B
 * �܂��AExternal_setINT0Event(*func)�ŊO�����荞�ݎ��Ɏ��s����֐���ݒ肵�Ă��������B
 * @param c ���荞�݂̔�������
 */
void External_initINT0(External_Condition c) {
	EICRA |= c & 0b0011;
	EIMSK |= _BV(INT0);
}

/**
 * INT1(PD3)�O�����荞�݂̂��߂ɏ��������܂��B
 * �������A�ʓrsei()�Ŋ��荞�݂�������K�v������܂��B
 * �܂��AExternal_setINT1Event(*func)�ŊO�����荞�ݎ��Ɏ��s����֐���ݒ肵�Ă��������B
 * @param c ���荞�݂̔�������
 */
void External_initINT1(External_Condition c) {
	EICRA |= c << 2;
	EIMSK |= _BV(INT1);
}

/**
 * PCINT0(PCINT0~PCINT7)�̊O���荞��(�ω����Ɋ��荞��)�̂��߂ɏ��������܂��B
 * PCINT0����PCINT7�̓��A���荞�݂�������s�����p�����[�^�Ɏw�肵�܂��B
 * �܂��AExternal_setPCINT0Handler(*func)�Ŋ��荞�ݎ��Ɏ��s����֐����w�肵�Ă��������B
 * @param mask ���荞�݋�����s����1�ɂ���
 *              [PCINT7|PCINT6|PCINT5|PCINT4|PCINT3|PCINT2|PCINT1|PCINT0|]
 */
void External_initPCINT0(unsigned char mask) {
	PCICR |= _BV(PCIE0);
	PCMSK0 = mask;
}

/**
 * PCINT1(PCINT8~PCINT14)�̊O�����荞��(�ω����Ɋ��荞��)�̂��߂ɏ��������܂��B
 * PCINT8����PCINT14�̓��A���荞�݂�������s�����p�����[�^�Ɏw�肵�܂��B
 * �܂��AExternal_setPCINT1Handler(*func)�Ŋ��荞�ݎ��Ɏ��s����֐����w�肵�Ă��������B
 * @param mask ���荞�݋�����s����1�ɂ���
 *              [-|PCINT14|PCINT13|PCINT12|PCINT11|PCINT10|PCINT9|PCINT8|]
 */
void External_initPCINT1(unsigned char mask) {
	PCICR |= _BV(PCIE1);
	PCMSK1 = mask;
}

/**
 * PCINT2(PCINT16~PCINT23)�̊O�����荞��(�ω����Ɋ��荞��)�̂��߂ɏ��������܂��B
 * PCINT16����PCINT23�̓��A���荞�݂�������s�����p�����[�^�Ɏw�肵�܂��B
 * �܂��AExternal_setPCINT2Handler(*func)�Ŋ��荞�ݎ��Ɏ��s����֐����w�肵�Ă��������B
 * @param mask ���荞�݋�����s����1�ɂ���
 *              [PCINT23|PCINT22|PCINT21|PCINT20|PCINT19|PCINT18|PCINT17|PCINT16|]
 */
void External_initPCINT2(unsigned char mask) {
	PCICR |= _BV(PCIE2);
	PCMSK2 = mask;
}

/**
 * INT0�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setINT0Handler(void (*func)(void)) {
	External_INT0handler = func;
}

/**
 * INT1�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setINT1Handler(void (*func)(void)) {
	External_INT1handler = func;
}

/**
 * PCINT0�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setPCINT0Handler(void (*func)(void)) {
	External_PCINT0handler = func;
}

/**
 * PCINT1�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setPCINT1Handler(void (*func)(void)) {
	External_PCINT1handler = func;
}

/**
 * PCINT2�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setPCINT2Handler(void (*func)(void)) {
	External_PCINT2handler = func;
}

/**
 * INT0���؂�ւ�������̊��荞�ݓ���
 */
ISR(INT0_vect){
    External_INT0handler();
}

/**
 * INT1���؂�ւ�������̊��荞�ݓ���
 */
ISR(INT1_vect) {
	External_INT1handler();
}

/**
 * PCINT0~PCINT7�̂����ꂩ���؂�ւ�������̊��荞�ݓ���
 */
ISR(PCINT0_vect) {
	External_PCINT0handler();
}

/**
 * PCINT8~PCINT14�̂����ꂩ���؂�ւ�������̊��荞�ݓ���
 */
ISR(PCINT1_vect) {
	External_PCINT1handler();
}

/**
 * PCINT16~PCINT23�̂����ꂩ���؂�ւ�������̊��荞�ݓ���
 */
ISR(PCINT2_vect) {
	External_PCINT2handler();
}
