#pragma once

#include<Siv3D.hpp>
#include "BezierCurve.h"

class PlayerUpdater;

class Player
{
	friend class PlayerUpdater;
public:
	enum Side
	{
		RIGHT,
		LEFT,
	};
	enum State
	{
		MOVE,
		ATTACK,
		JUMP
	};
private:
	Side side_;
	State state_;
	Rect rect_;
private:
	Rect &rect();
	BezierCurve bezierCurve;
public:
	Rect rectClone()const;
	void update();
	Player(Side side);
	~Player();
};

