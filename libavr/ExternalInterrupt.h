/** �O�����荞�݂����񂽂�ɍs�����߂̃��C�u�����ł��BAVR atmega88P,atmega168P�݊�
 * �̃}�C�R�������ɍ쐬����Ă��܂��B
 *
 * @file ExternalInterrupt.h
 * �O�����荞�݂̂��߂̃��C�u����
 *
 * mega88p/mega168p����
 *
 * @namespace External
 * @date 2012/01/06 22:41:56
 * @author hirokazu yokoyama
 */


#ifndef EXTERNALINTERRUPT_H_
#define EXTERNALINTERRUPT_H_

/**
 * INT0,INT1�O�����荞�݂̔�������
 */
typedef enum External_Condition {
	/** Low���x���Ŕ��� */
	External_LOW = 0b00,
	/** �ω����ɔ��� */
	External_CHANGE = 0b01,
	/** ���~�[�Ŕ��� */
	External_FALLING_EDGE = 0b10,
	/** �㏸�[�Ŕ��� */
    External_RISING_EDGE = 0b11
} External_Condition;

/**
 * INT0(PD2)�O�����荞�݂̂��߂ɏ��������܂��B
 * ����INT0�s����INT1�s���̊O�����荞�݂͊��荞�݂̔���������ݒ�ł��܂�
 * ����������External_Condtion�񋓑̂Œ�`���ꂽ�l�������ŗ^���Ă��������B
 * ���̊֐������s����INT0���O�����荞�݂̂��߂ɏ���������Ƌ��ɁA
 * External_setINT0Event(*func)��INT0�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�Ă��������B
 * �����āA���荞�݂����s����ɂ͕ʓrsei()�Ŋ��荞�݂�������K�v������܂��B 
 * @param c ���荞�݂̔�������
 *
 * *-- �g�p�� --*
 *
 * // INT0�O�����荞�݂𗧂��オ��Ɏ��s�ŏ���������
 * External_init0(External_RISING_EDGE);
 *
 * // INT0�O�����荞�ݔ������Ɏ��s����֐�func��ݒ肷��
 * External_setINT0Event(*func);
 *
 * //���荞�݂�����
 * sei();
 */
void External_initINT0(External_Condition c);


/**
 * INT1(PD3)�O�����荞�݂̂��߂ɏ��������܂��B
 * ����INT0�s����INT1�s���̊O�����荞�݂͊��荞�݂̔���������ݒ�ł��܂�
 * ����������External_Condtion�񋓑̂Œ�`���ꂽ�l�������ŗ^���Ă��������B
 * ���̊֐������s����INT1���O�����荞�݂̂��߂ɏ���������Ƌ��ɁA
 * External_setINT1Event(*func)��INT0�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�Ă��������B
 * �����āA���荞�݂����s����ɂ͕ʓrsei()�Ŋ��荞�݂�������K�v������܂��B 
 * @param c ���荞�݂̔�������
 *
 * *-- �g�p�� --*
 *
 * // INT1�O�����荞�݂𗧂��オ��Ɏ��s�ŏ���������
 * External_init1(External_RISING_EDGE);
 *
 * // INT0�O�����荞�ݔ������Ɏ��s����֐�func��ݒ肷��
 * External_setINT1Event(*func);
 *
 * //���荞�݂�����
 * sei();
 */
void External_initINT1(External_Condition c);


/**
 * PCINT0(PCINT0~PCINT7)�̊O���荞��(�ω����Ɋ��荞��)�̂��߂ɏ��������܂��B
 * PCINT0����PCINT7�̓��A���荞�݂�������s���������Ɏw�肵�܂��B
 * PCINTx�̊O�����荞�݂͊��荞�݂̔���������ݒ肷�邱�Ƃ͂ł��܂���B
 * PCINTx�̊O�����荞�݂͗����オ��A������̗����Ŕ������܂��B
 * ���̊֐������s����PCINT0�O�����荞�݂�����������Ƌ��ɁA
 * External_setPCINT0Handler(*func)�Ŋ��荞�ݎ��Ɏ��s����֐����w�肵�Ă��������B
 * (PCINT0~PCINT7�̊��荞�ݎ��̓���͋��ʂɂȂ�܂��B�ʂɎw�肷�邱�Ƃ͂ł��܂���)
 * �܂��A���荞�݂����s����ɂ͕ʓrsei()�Ŋ��荞�݂�������K�v������܂��B
 * @param mask ���荞�݋�����s����1�ɂ���
 *              [PCINT7|PCINT6|PCINT5|PCINT4|PCINT3|PCINT2|PCINT1|PCINT0|]
 */
void External_initPCINT0(unsigned char mask);


/**
 * PCINT1(PCINT8~PCINT14)�̊O�����荞��(�ω����Ɋ��荞��)�̂��߂ɏ��������܂��B
 * PCINT8����PCINT14�̓��A���荞�݂�������s�����p�����[�^�Ɏw�肵�܂��B
 * PCINTx�̊O�����荞�݂͊��荞�݂̔���������ݒ肷�邱�Ƃ͂ł��܂���B
 * PCINTx�̊O�����荞�݂͗����オ��A������̗����Ŕ������܂��B
 * ���̊֐������s����PCINT1�O�����荞�݂�����������Ƌ��ɁA
 * External_setPCINT1Handler(*func)�Ŋ��荞�ݎ��Ɏ��s����֐����w�肵�Ă��������B
 * (PCINT8~PCINT14�̊��荞�ݎ��̓���͋��ʂɂȂ�܂��B�ʂɎw�肷�邱�Ƃ͂ł��܂���)
 * �܂��A���荞�݂����s����ɂ͕ʓrsei()�Ŋ��荞�݂�������K�v������܂��B

 * @param mask ���荞�݋�����s����1�ɂ���
 *              [-|PCINT14|PCINT13|PCINT12|PCINT11|PCINT10|PCINT9|PCINT8|]
 */
void External_initPCINT1(unsigned char mask);


/**
 * PCINT2(PCINT16~PCINT23)�̊O�����荞��(�ω����Ɋ��荞��)�̂��߂ɏ��������܂��B
 * PCINT16����PCINT23�̓��A���荞�݂�������s�����p�����[�^�Ɏw�肵�܂��B
 * PCINTx�̊O�����荞�݂͊��荞�݂̔���������ݒ肷�邱�Ƃ͂ł��܂���B
 * PCINTx�̊O�����荞�݂͗����オ��A������̗����Ŕ������܂��B
 * ���̊֐������s����PCINT2�O�����荞�݂�����������Ƌ��ɁA
 * External_setPCINT2Handler(*func)�Ŋ��荞�ݎ��Ɏ��s����֐����w�肵�Ă��������B
 * (PCINT16~PCINT23�̊��荞�ݎ��̓���͋��ʂɂȂ�܂��B�ʂɎw�肷�邱�Ƃ͂ł��܂���)
 * �܂��A���荞�݂����s����ɂ͕ʓrsei()�Ŋ��荞�݂�������K�v������܂��B
 * @param mask ���荞�݋�����s����1�ɂ���
 *              [PCINT23|PCINT22|PCINT21|PCINT20|PCINT19|PCINT18|PCINT17|PCINT16|]
 */
void External_initPCINT2(unsigned char mask);


/**
 * INT0�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setINT0Handler(void (*func)(void));


/**
 * INT1�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setINT1Handler(void (*func)(void));


/**
 * PCINT0�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setPCINT0Handler(void (*func)(void));


/**
 * PCINT1�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setPCINT1Handler(void (*func)(void));


/**
 * PCINT2�O�����荞�ݎ��Ɏ��s����֐���ݒ肵�܂��B
 * @param *func ���s����֐��̃|�C���^
 */
void External_setPCINT2Handler(void (*func)(void));


#endif /* EXTERNALINTERRUPT_H_ */