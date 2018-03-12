#pragma once
#include "windows.h"
class Timer
{
	LARGE_INTEGER start, finish, clockFrequency, delta;
public:
	Timer(void);
	void startTimer();
	double endTimer();
	~Timer(void);
};

