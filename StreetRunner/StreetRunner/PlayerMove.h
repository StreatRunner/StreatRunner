#pragma once

#include "PlayerState.h"

class PlayerMove :
	public PlayerState
{
public:
	bool hasFinished()override;
	void update(Player &player)override;
	PlayerMove();
	~PlayerMove();
};

