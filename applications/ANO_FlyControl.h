#ifndef __ANO_FLYCONTROL_H
#define __ANO_FLYCONTROL_H

#include "ANO_Config.h"

#define FLYANGLE_MAX 250  //�̤j����ɨ�25��

enum {
    PIDROLL,
    PIDPITCH,
    PIDYAW,
		PIDITEMS
};

class ANO_FlyControl
{

public:
	
	ANO_PID pid[PIDITEMS];

	ANO_FlyControl();

	//���A����
	void Attitude_Loop(void);
	
private:
	
	void PID_Reset(void);
};

extern ANO_FlyControl fc;

#endif























