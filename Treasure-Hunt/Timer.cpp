#include "Timer.h"



bool Timer::isTimeOut(Uint32 abstime)
{
	if (abstime - lastTimeout >= timeoutPeriod) {
		lastTimeout = abstime;
		return true;
	}
	return false;
}

void Timer::setTimeOut(Uint32 abstime)
{
	lastTimeout = abstime;
}

void Timer::setTimeOutPeriod(Uint32 timeoutPeriod)
{
	this->timeoutPeriod = timeoutPeriod;
}

Timer::Timer()
{
	lastTimeout = 0;
	timeoutPeriod = 0;
}

Timer::Timer(Uint32 timeoutPeriod):timeoutPeriod(timeoutPeriod)
{
	lastTimeout = 0;
}


Timer::~Timer()
{

}
