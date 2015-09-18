#pragma once

#include "Controller.h"
#include<Siv3D.hpp>

class Gamepad :
	public Controller
{
	bool pressed(int index, Player::Side const side)const
	{
		return side == Player::LEFT ?
			s3d::Gamepad(0).button(index).pressed : s3d::Gamepad(1).button(index).pressed;
	}
public:
	bool leftPressed(Player::Side const side)override
	{
		return pressed(1, side);
	}
	bool rightPressed(Player::Side const side)override
	{
		return pressed(2, side);
	}

	bool jumpPressed(Player::Side const side)override
	{
		return pressed(3, side);
	}
	bool attackPressed(Player::Side const side)override
	{
		return pressed(0, side);
	}
	bool anyKeyPressed()override
	{
		auto pads = Input::EnumerateGamepads();
		bool anyKeyPressed = false;
		std::for_each(pads.begin(), pads.end(), [&anyKeyPressed] (GamepadInfo pi)
		{
			for (unsigned i(0); i < pi.num_buttons; ++i) {
				if (s3d::Gamepad(pi.index).button(i).pressed) {
					anyKeyPressed = true;
					return;
				}
			}
		});
		return anyKeyPressed;
	}
};

