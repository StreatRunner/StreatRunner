#include "Player.h"
#include"PlayerMove.h"
#include"PlayerJump.h"

Player::Player(Side side)
{
	rect_ =  (side_ = side) == LEFT ?
		Rect(0, 570, 25, 50) : Rect(1255, 570, 25, 50);

	state_ = MOVE;
	playerState_ = std::make_shared<PlayerMove>();
}



void Player::update()
{
	if (playerState_->hasFinished()) {
		if (side_ == RIGHT && Input::KeyUp.pressed) {
			playerState_ = std::make_shared<PlayerJump>(this->rect().x, this->rect().y, 50);
		}
		else if (side_ == LEFT && Input::KeyW.pressed) {
			playerState_ = std::make_shared<PlayerJump>(this->rect().x, this->rect().y, -50);
		}
		else {
			playerState_ = std::make_shared<PlayerMove>();
		}
	}

	playerState_->update(*this);

	
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
	/*if (bezierCurve.isEnd() == false){
		bezierCurve.start();
		rect_.x = bezierCurve.get_x();
		rect_.y = bezierCurve.get_y();
	}
	else{
		state_ = MOVE;
	}*/
}

void Player::attack()
{

}

Rect &Player::rect()
{
	return rect_;
}

Player::Side Player::side()
{
	return side_;
}

Player::~Player()
{}
