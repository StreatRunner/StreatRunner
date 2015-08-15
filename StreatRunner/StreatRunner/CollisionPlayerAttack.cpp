#include "CollisionPlayerAttack.h"
#include "Player.h"

CollisionPlayerAttack::CollisionPlayerAttack()
{}


CollisionPlayerAttack::~CollisionPlayerAttack()
{}

void CollisionPlayerAttack::detect(Player &player1, Player &player2)
{
	if (player1.getAttack() != nullptr && player1.getAttack()->intersects(player2.rect())) {
		player2.initialize();
	}
	if (player2.getAttack() != nullptr && player2.getAttack()->intersects(player1.rect())) {
		player1.initialize();
	}
}