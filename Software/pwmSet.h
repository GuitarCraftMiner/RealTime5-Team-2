#ifndef PWM_SET_H
#define PWM_Set_H

#include "CppThread.h"

class pwmSet : public CppThread {

public:
	pwmSet(int _error){
		error = _error;
	}
	
	int getPwm(){return new_pwm;}

private:
	void run();

private:
	int error;
	int new_pwm;
	
};

#endif
