#pragma once

#include"Player.h"

class Controller
{
public:
	static std::shared_ptr<Controller> input_;

	virtual bool leftPressed(Player::Side const side) = 0;
	virtual bool rightPressed(Player::Side const side) = 0;
	virtual bool jumpPressed(Player::Side const side) = 0;
	virtual bool attackPressed(Player::Side const side) = 0;

	virtual bool anyKeyPressed() = 0;
	virtual ~Controller()
	{}
};

