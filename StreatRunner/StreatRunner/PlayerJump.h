#pragma once
#include "PlayerState.h"

#include"BezierCurve.h"
class PlayerJump :
	public PlayerState
{
	BezierCurve bezier;
public:
	bool hasFinished()override;
	void update(Player &player)override;
	PlayerJump(int x, int y, int distance);
	~PlayerJump();
};

