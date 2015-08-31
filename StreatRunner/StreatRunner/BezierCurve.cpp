#include "BezierCurve.h"

BezierCurve::~BezierCurve()
{
}

bool BezierCurve::isEnd()
{
	bool end = false;

	if (t >= 1.0){
		end = true;
	}

	return end;
}

int BezierCurve::get_x()
{
	return x;
}

int BezierCurve::get_y()
{
	return y;
}

void BezierCurve::setT(double t)
{
	this->t = t;
}

BezierCurve::BezierCurve()
{
	startingPoint_x = 0;
	startingPoint_y = 0;
	endPoint_x = 0;
	endPoint_y = 0;
	turnPoint_x = 0;
	turnPoint_y = 0;
	x = 0;
	y = 0;
	t = 1.0;
}

void BezierCurve::setPoint(int startingPoint_x, int startingPoint_y, int endPoint_x, int endPoint_y, int turnPoint_x, int turnPoint_y, double speed)
{
	this->startingPoint_x = startingPoint_x;
	this->startingPoint_y = startingPoint_y;
	y = startingPoint_y;
	this->endPoint_x = endPoint_x;
	this->endPoint_y = endPoint_y;
	this->speed = speed;
	t = 0.0;


	// x,yが通したい点
	// p0, p1 , p2はベジエ曲線の制御点。p1をp0,p2,(x,y)の3点とt = 0.5の条件から求めて使ってみる
	this->turnPoint_x = (int)((4 * turnPoint_x - startingPoint_x - endPoint_x) / 2.0);
	this->turnPoint_y = (int)((4 * turnPoint_y - startingPoint_y - endPoint_y) / 2.0);
}

void BezierCurve::start()
{
	temp_y = y;

	if (t < 1.0){
		t += speed;
	}

	x = (int)(((1 - t)*(1 - t)) * startingPoint_x + 2 * (1 - t) * t * turnPoint_x + t * t * endPoint_x);
	y = (int)(((1 - t)*(1 - t)) * startingPoint_y + 2 * (1 - t) * t * turnPoint_y + t * t * endPoint_y);

}