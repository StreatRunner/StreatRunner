#include "CollisionPlayerAttack.h"
#include "Player.h"

CollisionPlayerAttack::CollisionPlayerAttack()
{}


CollisionPlayerAttack::~CollisionPlayerAttack()
{}

void CollisionPlayerAttack::detect(Player &player1, Player &player2)
{
	bool colliding2 = 
		player1.getAttack() != nullptr && player1.getAttack()->intersects(player2.rect());
	bool colliding1 =
		player2.getAttack() != nullptr && player2.getAttack()->intersects(player1.rect());

	if (colliding2) {
		player2.initialize();
	}
	if (colliding1) {
		player1.initialize();
	}
}