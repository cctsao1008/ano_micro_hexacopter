#ifndef __ANO_SCHEDULER_H
#define __ANO_SCHEDULER_H

#include "board.h"
#include "ANO_Config.h"

class ANO_Scheduler
{
public:
	//�c�y���
	ANO_Scheduler();
	//���Ȯɰ�p���ܶq
	uint16_t cnt_1ms,cnt_2ms,cnt_5ms,cnt_10ms,cnt_20ms;

};

void ANO_Loop(void);

extern ANO_Scheduler scheduler;

#endif











