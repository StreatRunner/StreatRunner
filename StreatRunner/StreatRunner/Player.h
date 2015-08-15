#pragma once

#include<Siv3D.hpp>

class PlayerUpdater;
class PlayerState;
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
	std::shared_ptr<PlayerState> playerState_;
	Rect rect_;
private:
	void changeState();
public:
	void move();
	void jump();
	void attack();

	Rect &rect(); 
	Side side();
	void update();
	Player(Side side);
	~Player();
};

