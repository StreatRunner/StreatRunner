#pragma once

class BezierCurve
{
protected:
	int startingPoint_x, startingPoint_y;
	int endPoint_x, endPoint_y;
	int turnPoint_x, turnPoint_y;
	int x, y;
	double speed;
	double t;
	int temp_x, temp_y;
public:
	void setPoint(int startingPoint_x, int starting_y, int endPoint_x, int endPoint_y, int turnPoint_x, int turnPoint_y, double speed);
	void setT(double t);
	bool isEnd();
	void start();
	int get_x();
	int get_y();
	BezierCurve();
	~BezierCurve();
};
