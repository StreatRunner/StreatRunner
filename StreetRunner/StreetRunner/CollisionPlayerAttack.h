#pragma once

class Player;

class CollisionPlayerAttack
{
public:
	void detect(Player &player1, Player &player2);
	CollisionPlayerAttack();
	~CollisionPlayerAttack();
};

