#include "PlayerJump.h"
#include"Player.h"

PlayerJump::PlayerJump(int x, int y, int distance)
{
	bezier.setPoint(x, y, x - distance, y, x - (distance / 2), y - 150, 0.02);
}


PlayerJump::~PlayerJump()
{

}


bool PlayerJump::hasFinished()
{
	return bezier.isEnd();
}

void PlayerJump::update(Player &player)
{
	bezier.start();
	player.rect().setPos(bezier.get_x(), bezier.get_y());
}
