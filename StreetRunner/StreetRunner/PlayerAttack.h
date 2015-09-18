#pragma once
#include "PlayerState.h"
#include "FlameCounter.h"

class PlayerAttack :
	public PlayerState
{
private:
	FlameCounter flameCounter;
public:
	bool hasFinished();
	void update(Player &player);
	PlayerAttack();
	~PlayerAttack();
};

