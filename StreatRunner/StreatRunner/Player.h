#pragma once

#include<Siv3D.hpp>

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
public:
	void move();
	void jump();
	void attack();
	Rect rectClone()const;
	void update();
	Player(Side side);
	~Player();
};

