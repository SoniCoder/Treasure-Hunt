#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
class Timer
{
	Uint32 lastTimeout;
	Uint32 timeoutPeriod;
public:
	bool isTimeOut(Uint32 abstime);
	void setTimeOut(Uint32 abstime);
	void setTimeOutPeriod(Uint32 timeoutPeriod);
	Timer();
	Timer(Uint32 timeoutPeriod);
	~Timer();
};
#endif