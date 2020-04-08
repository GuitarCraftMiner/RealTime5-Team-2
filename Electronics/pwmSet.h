#ifndef PWM_SET_H
#define PWM_Set_H

#include "CppThread.h"

class pwmSet : public CppThread {

public:
	pwmSet(int _new_pwm) {
		new_pwm = _new_pwm;
	}

private:
	void run();

private:
	int new_pwm;
	
};

#endif
