#pragma once

#include<Siv3D.hpp>

class PlayerState;
class Controller;
class Player
{
public:
	enum Side
	{
		RIGHT,
		LEFT,
	};
private:
	Side const side_;
	std::shared_ptr <Rect> attack_;
	std::shared_ptr<PlayerState> playerState_;
	Rect rect_;
	Player &operator=(Player const &) = delete;
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

