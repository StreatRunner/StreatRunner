#include "PlayerAttack.h"
#include "Player.h"

PlayerAttack::PlayerAttack() : flameCounter(40)
{

}


PlayerAttack::~PlayerAttack()
{

}

bool PlayerAttack::hasFinished()
{
	return flameCounter.isCountEnd();
}

void PlayerAttack::update(Player &player)
{
	if (flameCounter.getCount() == 0){
		player.getAttack() = std::make_shared<Rect>(75, 75);
		player.getAttack()->setCenter(player.rect()._get_center());
	}
	else{
		if (player.side() == Player::LEFT){
			player.getAttack()->moveBy(3, -3);
		}
		else{
			player.getAttack()->moveBy(-3, -3);
		}
	}

	flameCounter.start();

	if (flameCounter.isCountEnd()){
		player.getAttack() = nullptr;
	}
}