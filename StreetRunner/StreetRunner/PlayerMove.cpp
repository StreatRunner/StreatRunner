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
		if (Controller::input_->rightPressed(player.side()))	{
			auto x = player.rect().x;
			player.rect().x = Clamp(x + 2, 0, 1280-25);
			//player.rect().moveBy(2, 0);
		}
		else if (Controller::input_->leftPressed(player.side())) {
			auto x = player.rect().x;
			player.rect().x = Clamp(x - 2, 0, 1280 - 25);
			//player.rect().moveBy(-2, 0);
		}
	}
	else {
		if (Controller::input_->rightPressed(player.side())) {
			auto x = player.rect().x;
			player.rect().x = Clamp(x + 2, 0, 1280 - 25);
			//player.rect().moveBy(2, 0);
		}
		else if (Controller::input_->leftPressed(player.side())) {
			auto x = player.rect().x;
			player.rect().x = Clamp(x - 2, 0, 1280 - 25);
			//player.rect().moveBy(-2, 0);
		}
	}
}


PlayerMove::~PlayerMove()
{}
