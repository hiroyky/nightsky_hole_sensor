/*
 * timer.h �^�C�}����p�̃��C�u����
 * mega88p/mega168p����
 *
 * namespace: Timern
 * Created: 2012/01/04 1:32:48
 *  Author: hirokazu yokoyama
 */


#ifndef TIMER_H_
#define TIMER_H_

/**
 * �^�C�}�̃v�����X�P�[��(������)
 */
typedef enum Timer_Prescaler {
	/** �����Ȃ� */
	Timer_PRESCALER_NONE = 0b001,
	/** 8���� */
    Timer_PRESCALER_8 = 0b010,
	/** 64���� */
    Timer_PRESCALER_64 = 0b011,
    /** 256���� */
	Timer_PRESCALER_256 = 0b100,
	/** 1024���� */
    Timer_PRESCALER_1024 = 0b101,
	/** �O���N���b�N(���~) */
    Timer_PRESCALER_OUTSIDE_UNDER = 0b110,
	/** �O���N���b�N(�㏸) */
    Timer_PRESCALER_OUTSIDE_OVER = 0b111
} Timer_Prescaler;

/**
 * ��r�o�̓��[�h�I��A
 */
typedef enum Timer_MatchModeA {
	/** �W���|�[�g����(�^�C�}�g��Ȃ���) */
	Timer_A_NONE = 0b00,
	/** �g�O���o��(Low,High�����݂ɏo��) */
	Timer_A_TOGGLE = 0b01,
	/** ��r��v��Low, BOTTOM��High���o��(�񔽓]����)[10] */
	Timer_A_LOW_AT_COMPARE_MATCH = 0b10,
	/** ��r��v��High, BOTTOM��Low���o��(���]����)[11] */
	Timer_A_HIGH_AT_COMPARE_MATCH = 0b11
} Timer_MatchModeA;

/**
 * ��r�o�̓��[�h�I��B
 */
typedef enum Timer_MatchModeB {
	/** �W���|�[�g����(�^�C�}�g��Ȃ���) */
	Timer_B_NONE = 0b00,
	/** ��r��v��Low, BOTTOM��High���o��(�񔽓]����)[10] */
	Timer_B_LOW_AT_COMPARE_MATCH = 0b10,
	/** ��r��v��High, BOTTOM��Low���o��(���]����)[11] */
	Timer_B_HIGH_AT_COMPARE_MATCH = 0b11
} Timer_MatchModeB;

/**
 * �^�C�}0�̔g�`�I��
 */
typedef enum Timer0_PulseMode {
	// �W������(�^�C�}�g��Ȃ���)
	Timer0_PULSE_NONE = 0b000,
	// 8bit�ʑ��PWM,TOP�l$FF, OCR�X�V��:TOP, TOV0�ݒ莞:BOTTOM
	Timer0_8BIT_PHASE_BASED_PWM = 0b001,
	// ��r��vCTC����,TOP�l:OCR0A, OCR0�X�V��:����, TOV0�X�V��:MAX
	Timer0_CTC = 0b010,
	// 8bit����PWM����,TOP�l$FF, OCR�X�V��:BOTTOM, TOV0�ݒ莞:TOP
	Timer0_8BIT_FIRST_PWM = 0b011,
	// �ʑ��PWM,TOP�l$OCR0A, OCR�X�V��:TOP, TOV0�ݒ莞:BOTTOM
	Timer0_PHASE_BASED_PWM = 0b101,
	// ����PWM, TOP�l$FF, OCR�X�V��:BOTTOM, TOV0�ݒ莞:TOP
	Timer0_FIRST_PWM = 0b111
} Timer0_PulseMode;

/**
 * �^�C�}1�̔g�`�I��
 */
typedef enum Timer1_PulseMode {
	// �W������(�^�C�}�g��Ȃ���)
	Timer1_PULSE_NONE = 0b0000,
	// 8bit�ʑ��PWM,TOP�l:$FF, OCR�X�V��:TOP, TOV0�ݒ莞:BOTTOM
	Timer1_8BIT_PHASE_BASED_PWM = 0b0001,
	// 9bit�ʑ��PWM,TOP�l:$1FF, OCR�X�V��:TOP, TOV0�ݒ莞:BOTTOM
	Timer1_9BIT_PHASE_BASED_PWM = 0b0010,
	// 10bit�ʑ��PWM,TOP�l:3$FF, OCR�X�V��:TOP, TOV0�ݒ莞:BOTTOM
	Timer1_10BIT_PHASE_BASED_PWM = 0b0011,
	// ��r��vCTC����,TOP�l:OCR1A, OCR0�X�V��:����, TOV0�X�V��:MAX
	Timer1_CTC_OCR = 0b010,
	// 8bit����PWM����,TOP�l:$FF, OCR�X�V��:BOTTOM, TOV0�ݒ莞:TOP
	Timer1_8BIT_FIRST_PWM = 0b0101,
	// 9bit����PWM����,TOP�l:$1FF, OCR�X�V��:BOTTOM, TOV0�ݒ莞:TOP
	Timer1_9BIT_FIRST_PWM = 0b0110,
	// 10bit����PWM����,TOP�l:$3FF, OCR�X�V��:BOTTOM, TOV0�ݒ莞:TOP
	Timer1_10BIT_FIRST_PWM = 0b0111,
	// �ʑ��E���g���PWM����,TOP�lICR1, OCR�X�V��:BOTTOM, TOV1�ݒ莞:BOTTOM
	Timer1_PHASE_PULSE_BASED_PWM_ICR = 0b1000,
	// �ʑ��E���g���PWM����,TOP�lOCR1A, OCR�X�V��:BOTTOM, TOV1�ݒ莞:BOTTOM
	Timer1_PHASE_PULSE_BASED_PWM_OCR = 0b1001,
	// �ʑ��PWM,TOP�l$ICR1, OCR�X�V��:TOP, TOV0�ݒ莞:BOTTOM
	Timer1_PHASE_BASED_PWM_ICR = 0b1010,
	// �ʑ��PWM,TOP�l$OCR1A, OCR�X�V��:TOP, TOV0�ݒ莞:BOTTOM
	Timer1_PHASE_BASED_PWM_OCR = 0b1011,
	// CTC����,TOP�l:ICR1, OCR�X�V��:����, TOV0�ݒ莞:MAX
	Timer1_CTC_ICR = 0b1100,
	// ����PWM, TOP�l:ICR1, OCR�X�V��:BOTTOM, TOV0�ݒ莞:TOP
	Timer1_FIRST_PWM_ICR = 0b1110,
	// ����PWM, TOP�l:OCR, OCR�X�V��:BOTTOM, TOV0�ݒ莞:TOP
	Timer1_FIRST_PWM_OCR = 0b1111
} Timer1_PulseMode;

/**
 * �^�C�}2�̔g�`�I��
 */
typedef enum Timer2_PulseMode {
	// �W������(�^�C�}�g��Ȃ���)
	Timer2_PULSE_NONE = 0b000,
	// 8bit�ʑ��PWM,TOP�l$FF, OCR�X�V��:TOP, TOV0�ݒ莞:BOTTOM
	Timer2_8BIT_PHASE_BASED_PWM = 0b001,
	// ��r��vCTC����,TOP�l:OCR2A, OCR0�X�V��:����, TOV0�X�V��:MAX
	Timer2_CTC = 0b010,
	// 8bit����PWM����,TOP�l$FF, OCR�X�V��:BOTTOM, TOV0�ݒ莞:TOP
	Timer2_8BIT_FIRST_PWM = 0b011,
	// �ʑ��PWM,TOP�l$OCR2A, OCR�X�V��:TOP, TOV0�ݒ莞:BOTTOM
	Timer2_PHASE_BASED_PWM = 0b101,
	// ����PWM, TOP�l$FF, OCR�X�V��:BOTTOM, TOV0�ݒ莞:TOP
	Timer2_FIRST_PWM = 0b111
} Timer2_PulseMode;

/**
 * �^�C�}0�̊��荞�݃��[�h�̑I��
 */
typedef enum Timer0_InterruptMask {
	// �^�C�}�E�J�E���^��rA�Ŕ�r��v�̎��Ɋ��荞�݂����s����
	Timer0_INTERRUPT_MATCH_A = _BV(OCIE0A),
	// �^�C�}�E�J�E���^��rB�Ŕ�r��v�̎��Ɋ��荞�݂����s����
	Timer0_INTERRUPT_MATCH_B = _BV(OCIE0B),
	// ��ꂪ������Ɗ��荞�݂����s����
	Timer0_INTERRUPT_OVERFLOW = _BV(TOIE0)
} Timer0_InterruptMask;

/**
 * �^�C�}1�̊��荞�݃��[�h�̑I��
 */
typedef enum Timer1_InterruptMask {
	// �^�C�}�E�J�E���^��rA�Ŕ�r��v�̎��Ɋ��荞�݂����s����
	Timer1_INTERRUPT_MATCH_A = _BV(OCIE1A),
	// �^�C�}�E�J�E���^��rB�Ŕ�r��v�̎��Ɋ��荞�݂����s����
	Timer1_INTERRUPT_MATCH_B = _BV(OCIE1B),
	// ICR�̕ߊl���荞�݂����s����
	Timer1_INTERRUPT_ICR = _BV(ICIE1),
	// ��ꂪ������Ɗ��荞�݂����s����
	Timer1_INTERRUPT_OVERFLOW = _BV(TOIE1)
} Timer1_InterruptMask;


/**
 * �^�C�}2�̊��荞�݃��[�h�̑I��
 */
typedef enum Timer2_InterruptMask {
	// �^�C�}�E�J�E���^��rA�Ŕ�r��v�̎��Ɋ��荞�݂����s����
	Timer2_INTERRUPT_MATCH_A = _BV(OCIE2A),
	// �^�C�}�E�J�E���^��rB�Ŕ�r��v�̎��Ɋ��荞�݂����s����
	Timer2_INTERRUPT_MATCH_B = _BV(OCIE2B),
	// ��ꂪ������Ɗ��荞�݂����s����
	Timer2_INTERRUPT_OVERFLOW = _BV(TOIE2)
} Timer2_InterruptMask;

/**
 * �^�C�}�E�J�E���^0�����������܂��B
 * matchA, matchB�̒l��Timer_A_NONE�y��Timer_B_NONE�ȊO���w�肵���ꍇ�APD5�y��PD6
 * ��DDR��High�ɂȂ�o�͂ɐݒ肳��܂��B
 * @param matchA �^�C�}A�̔�r��v���̓����I��
 * @param matchB �^�C�}B�̔�r��v���̓����I��
 * @param wgm �o�͔g�`,���[�h��I��
 * @param p �v�����X�P�[��(������)
 */
void Timer0_init(Timer_MatchModeA matchA, Timer_MatchModeB matchB,
                        Timer0_PulseMode wgm, Timer_Prescaler p);

/**
 * �^�C�}�E�J�E���^1�����������܂��B
 * matchA, matchB�̒l��Timer_A_NONE�y��Timer_B_NONE�ȊO���w�肵���ꍇ�APB0�y��PB1
 * ��DDR��High�ɂȂ�o�͂ɐݒ肳��܂��B
 * @param matchA �^�C�}A�̔�r��v���̓����I��
 * @param matchB �^�C�}B�̔�r��v���̓����I��
 * @param wgm �o�͔g�`,���[�h��I��
 * @param p �v�����X�P�[��(������)
 */
void Timer1_init(Timer_MatchModeA matchA, Timer_MatchModeB matchB,
                        Timer1_PulseMode wgm, Timer_Prescaler p);

/**
 * �^�C�}�E�J�E���^2�����������܂��B
 * matchA, matchB�̒l��Timer_A_NONE�y��Timer_B_NONE�ȊO���w�肵���ꍇ�APB3�y��PB4
 * ��DDR��High�ɂȂ�o�͂ɐݒ肳��܂��B
 * @param matchA �^�C�}A�̔�r��v���̓����I��
 * @param matchB �^�C�}B�̔�r��v���̓����I��
 * @param wgm �o�͔g�`,���[�h��I��
 * @param p �v�����X�P�[��(������)
 */
void Timer2_init(Timer_MatchModeA matchA, Timer_MatchModeB matchB,
                        Timer2_PulseMode wgm, Timer_Prescaler p);

/**
 * �^�C�}0�̊��荞�݂������܂�
 * @param mask ���荞�݂̃^�C�~���O��I��
 */
void Timer0_setTimerInterruptEnable(Timer0_InterruptMask mask);

/**
 * �^�C�}1�̊��荞�݂������܂�
 * @param mask ���荞�݂̃^�C�~���O��I��
 */
void Timer1_setTimerInterruptEnable(Timer1_InterruptMask mask);

/**
 * �^�C�}2�̊��荞�݂������܂�
 * @param mask ���荞�݂̃^�C�~���O��I��
 */
void Timer2_setTimerInterruptEnable(Timer2_InterruptMask mask);

/**
 * TCNT0 �ɐݒ肷��J�E���g�l���w�肵�܂��B
 * @param count �J�E���^�l
 */
void Timer0_setTimerCounter(uint8_t count);

/**
 * TCNT1 �ɐݒ肷��J�E���g�l���w�肵�܂��B
 * @param count �J�E���^�l
 */
void Timer1_setTimerCounter(uint16_t count);

/**
 * TCNT2 �ɐݒ肷��J�E���g�l���w�肵�܂��B
 * @param count �J�E���^�l
 */
void Timer2_setTimerCounter(uint8_t count);

/**
 * �^�C�}0A�̔�r��v�̊�l���w�肵�܂��BOCR0A�̒l��ݒ肵�܂�
 * @param criteriaValue OCR0A�ɑ������l
 */
void Timer0_setTimerACriteria(uint8_t criteriaValue);

/**
 * �^�C�}0B�̔�r��v�̊�l���w�肵�܂��BOCR0B�̒l��ݒ肵�܂�
 * @param criteriaValue OCR0B�ɑ������l
 */
void Timer0_setTimerBCriteria(uint8_t criteriaValue);

/**
 * �^�C�}1A�̔�r��v�̊�l���w�肵�܂��BOCR1A�̒l��ݒ肵�܂�
 * @param criteriaValue OCR1A�ɑ������l
 */
void Timer1_setTimerACriteria(uint16_t criteriaValue);

/**
 * �^�C�}1B�̔�r��v�̊�l���w�肵�܂��BOCR1B�̒l��ݒ肵�܂�
 * @param criteriaValue OCR1B�ɑ������l
 */
void Timer1_setTimerBCriteria(uint16_t criteriaValue);

/**
 * �^�C�}1�̕ߊl���荞�݂̊�l���w�肵�܂��BICR1�̒l���w�肵�܂�
 */
void Timer1_setTimerCaptureCriteria(uint16_t criteriaValue);

/**
 * �^�C�}2A�̔�r��v�̊�l���w�肵�܂��BOCR2A�̒l��ݒ肵�܂�
 * @param criteriaValue OCR2A�ɑ������l
 */
void Timer2_setTimerACriteria(uint8_t criteriaValue);

/**
 * �^�C�}2B�̔�r��v�̊�l���w�肵�܂��BOCR2B�̒l��ݒ肵�܂�
 * @param criteriaValue OCR2B�ɑ������l
 */
void Timer2_setTimerBCriteria(uint8_t criteriaValue);

/**
 * �I�[�o�[�t���[���̊��荞�݃n���h����ݒ肵�܂�
 * @param func �n���h���֐��̃|�C���^
 */
void Timer0_setOverflowHandler(void (*func)(void));

/**
 * �^�C�}A���̊��荞�݃n���h����ݒ肵�܂�
 * @param func �n���h���֐��̃|�C���^
 */
void Timer0_setMatchAHandler(void (*func)(void));

/**
 * �I�[�o�[�t���[���̊��荞�݃n���h����ݒ肵�܂�
 * @param func �n���h���֐��̃|�C���^
 */
void Timer0_setMatchBHandler(void (*func)(void));

/**
 * �I�[�o�[�t���[���̊��荞�݃n���h����ݒ肵�܂�
 * @param func �n���h���֐��̃|�C���^
 */
void Timer1_setOverflowHandler(void (*func)(void));

/**
 * �^�C�}A���̊��荞�݃n���h����ݒ肵�܂�
 * @param func �n���h���֐��̃|�C���^
 */
void Timer1_setMatchAHandler(void (*func)(void));

/**
 * �I�[�o�[�t���[���̊��荞�݃n���h����ݒ肵�܂�
 * @param func �n���h���֐��̃|�C���^
 */
void Timer1_setMatchBHandler(void (*func)(void));

/**
 *  �ߊl���荞�݂̃n���h����ݒ肵�܂��B
 * @aram func �n���h���֐��̃|�C���^
 */
void Timer1_setCaptureHandler(void (*func)(void));

/**
 * �I�[�o�[�t���[���̊��荞�݃n���h����ݒ肵�܂�
 * @param func �n���h���֐��̃|�C���^
 */
void Timer2_setOverflowHandler(void (*func)(void));

/**
 * �^�C�}A���̊��荞�݃n���h����ݒ肵�܂�
 * @param func �n���h���֐��̃|�C���^
 */
void Timer2_setMatchAHandler(void (*func)(void));

/**
 * �I�[�o�[�t���[���̊��荞�݃n���h����ݒ肵�܂�
 * @param func �n���h���֐��̃|�C���^
 */
void Timer2_setMatchBHandler(void (*func)(void));


#endif /* TIMER_H_ */