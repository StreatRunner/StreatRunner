#include "Player.h"


Player::Player(Side side)
{
	rect_ =  (side_ = side) == LEFT ?
		Rect(0, 570, 25, 50) : Rect(1255, 570, 25, 50);

	state_ = MOVE;
}



void Player::update()
{
	switch (state_)
	{
	case Player::MOVE:
		move();
		break;
	case Player::ATTACK:
		attack();
		break;
	case Player::JUMP:
		jump();
		break;
	default:
		break;
	}
	if (Input::KeyUp.pressed && state_ != Player::JUMP){
		bezierCurve.setPoint(rect_.x, rect_.y, rect_.x - 200, rect_.y, rect_.x - (200 / 2), rect_.y - 250, 0.025);
		state_ = JUMP;
	}

	
}

void Player::changeState()
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
	if (bezierCurve.isEnd() == false){
		bezierCurve.start();
		rect_.x = bezierCurve.get_x();
		rect_.y = bezierCurve.get_y();
	}
	else{
		state_ = MOVE;
	}
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
