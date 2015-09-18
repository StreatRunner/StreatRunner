#include "PlayerMove.h"
#include"Player.h"
#include"Controller.h"

PlayerMove::PlayerMove()
{}

bool PlayerMove::hasFinished()
{
	return true;
}

void PlayerMove::update(Player &player)
{
	if (player.side() == Player::LEFT) {
		if (Controller::input_->rightPressed(player.side()))
		{
			player.rect().moveBy(2, 0);
		}
		else if (Controller::input_->leftPressed(player.side())) {
			player.rect().moveBy(-2, 0);

		}
	}
	else {
		if (Controller::input_->rightPressed(player.side())) {
			player.rect().moveBy(2, 0);
		}
		else if (Controller::input_->leftPressed(player.side())) {
			player.rect().moveBy(-2, 0);
		}
	}
}


PlayerMove::~PlayerMove()
{}
