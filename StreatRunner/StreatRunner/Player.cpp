#include "Player.h"


Player::Player(Side side)
{
	rect_ =  (side_ = side) == LEFT ?
		Rect(0, 570, 25, 50) : Rect(1255, 570, 25, 50);

	state_ = MOVE;
}



void Player::update()
{

}

void Player::move()
{
	if (side_ == LEFT) {
		if (Input::KeyD.pressed) {
			rect_.moveBy(1, 0);
		}
		else if (Input::KeyA.pressed) {
			rect_.moveBy(-1, 0);

		}
	}
	else {
		if (Input::KeyRight.pressed) {
			rect_.moveBy(1, 0);
		}
		else if (Input::KeyLeft.pressed) {
			rect_.moveBy(-1, 0);
		}
	}
}

void Player::jump()
{

}

void Player::attack()
{

}

Rect &Player::rect()
{
	return rect_;
}

Rect Player::rectClone()const
{
	return rect_;
}

Player::~Player()
{}
