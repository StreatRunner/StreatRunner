#pragma once

#include<Siv3D.hpp>
class Player;
class PlayerState
{
public:
	virtual bool hasFinished() = 0;
	virtual void update(Player &player) = 0;
	virtual ~PlayerState() = default;
};


