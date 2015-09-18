#pragma once

class Player;

class CollisionPlayerPlayer
{
public:
	void detect(Player &playyer1, Player &player2);
	CollisionPlayerPlayer();
	~CollisionPlayerPlayer();
};

