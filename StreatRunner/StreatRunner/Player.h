#pragma once

#include<Siv3D.hpp>

class PlayerState;
class Player
{
public:
	enum Side
	{
		RIGHT,
		LEFT,
	};
private:
	Side side_;
	std::shared_ptr <Rect> attack_;
	std::shared_ptr<PlayerState> playerState_;
	Rect rect_;
public:
	std::shared_ptr<Rect>& getAttack();
	void addAttack();
	Rect &rect(); 
	Side side();
	void initialize();
	void update();
	Player(Side side);
	~Player();
};

