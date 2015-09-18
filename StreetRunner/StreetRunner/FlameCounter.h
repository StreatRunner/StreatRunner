#pragma once
class FlameCounter
{
private:
	int maxTime;
	int count;
	bool countEnd;
public:
	bool isCountEnd();
	int getCount();
	void reset();
	void stop();
	void start();
	FlameCounter(int max);
	~FlameCounter();
};

