#include "Player.h"
#include"PlayerMove.h"
#include"PlayerJump.h"
#include "PlayerAttack.h"

Player::Player(Side side)
{
	rect_ =  (side_ = side) == LEFT ?
		Rect(0, 570, 25, 50) : Rect(1255, 570, 25, 50);

	playerState_ = std::make_shared<PlayerMove>();
	attack_ = nullptr;
}

void Player::initialize()
{
	rect_ = side_ == LEFT ?
		Rect(0, 570, 25, 50) : Rect(1255, 570, 25, 50);

	playerState_ = std::make_shared<PlayerMove>();
	attack_ = nullptr;
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
		else if ((side_ == RIGHT && Input::KeyDown.pressed) || (side_ == LEFT && Input::KeyS.pressed)){
			playerState_ = std::make_shared<PlayerAttack>();
		}
		else {
			playerState_ = std::make_shared<PlayerMove>();
		}
	}

	playerState_->update(*this);

	
}

std::shared_ptr<Rect>& Player::getAttack()
{
	return attack_;
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
