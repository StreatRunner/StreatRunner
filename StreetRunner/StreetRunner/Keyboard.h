#pragma once

#include "Controller.h"

class Keyboard :
	public Controller
{
public:
	bool leftPressed(Player::Side const side)override
	{
		return (side == Player::LEFT && Input::KeyA.pressed) || (side == Player::RIGHT && Input::KeyLeft.pressed);
	}
	bool rightPressed(Player::Side const side)override
	{
		return (side == Player::LEFT && Input::KeyD.pressed) || (side == Player::RIGHT && Input::KeyRight.pressed);
	}
	bool jumpPressed(Player::Side const side)override
	{
		return (side == Player::LEFT && Input::KeyW.pressed) || (side == Player::RIGHT && Input::KeyUp.pressed);
	}
	bool attackPressed(Player::Side const side)override
	{
		return (side == Player::LEFT && Input::KeyS.pressed) || (side == Player::RIGHT && Input::KeyDown.pressed);
	}
	bool anyKeyPressed()override
	{
		return Input::AnyKeyPressed();
	}

};

