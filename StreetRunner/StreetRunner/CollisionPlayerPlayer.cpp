#include "CollisionPlayerPlayer.h"

#include"Player.h"

CollisionPlayerPlayer::CollisionPlayerPlayer()
{}


CollisionPlayerPlayer::~CollisionPlayerPlayer()
{}


void CollisionPlayerPlayer::detect(Player &player1, Player &player2)
{
	if (player1.rect().intersects(player2.rect()) || player1.rect().x > player2.rect().x) {
		if (player1.rect().y == player2.rect().y) {
			player1.initialize();
			player2.initialize();
		}
		else if (player1.rect().y > player2.rect().y) {
			player1.initialize();
		}
		else {
			player2.initialize();
		}
	}
}