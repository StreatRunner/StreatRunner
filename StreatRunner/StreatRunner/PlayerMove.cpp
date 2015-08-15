#include "PlayerMove.h"
#include"Player.h"

PlayerMove::PlayerMove()
{}

bool PlayerMove::hasFinished()
{
	return true;
}

void PlayerMove::update(Player &player)
{
	if (player.side() == Player::LEFT) {
		if (Input::KeyD.pressed) {
			player.rect().moveBy(1, 0);
		}
		else if (Input::KeyA.pressed) {
			player.rect().moveBy(-1, 0);

		}
	}
	else {
		if (Input::KeyRight.pressed) {
			player.rect().moveBy(1, 0);
		}
		else if (Input::KeyLeft.pressed) {
			player.rect().moveBy(-1, 0);
		}
	}
}


PlayerMove::~PlayerMove()
{}
