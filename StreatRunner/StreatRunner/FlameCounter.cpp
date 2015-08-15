#include "FlameCounter.h"


FlameCounter::FlameCounter(int max)
{
	countEnd = false;
	count = 0;
	this->maxTime = max;
}


FlameCounter::~FlameCounter()
{
}


void FlameCounter::stop()
{
	count = 0;
	countEnd = false;
}

bool FlameCounter::isCountEnd()
{
	return countEnd;
}

void FlameCounter::reset()
{
	count = 0;
	countEnd = false;
}

void FlameCounter::start()
{
	if (maxTime > count){
		count++;
	}
	else if (maxTime - 1 <= count){
		countEnd = true;
	}
}

int FlameCounter::getCount()
{
	return count;
}