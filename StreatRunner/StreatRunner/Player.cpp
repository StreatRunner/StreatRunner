#include "Player.h"
#include"PlayerMove.h"
#include"PlayerJump.h"
#include "PlayerAttack.h"
#include "Keyboard.h"

Player::Player(Side side)
	:side_(side)
{
	/*rect_ =  side_ == LEFT ?
		Rect(0, 570, 25, 50) : Rect(1255, 570, 25, 50);

	playerState_ = std::make_shared<PlayerMove>();
	attack_ = nullptr;
	*/
	initialize();
}

void Player::initialize()
{
	rect_ = side_ == LEFT ?
		Rect(0, 570, 25, 60) : Rect(1255, 570, 25, 60);
	
	playerState_ = std::make_shared<PlayerMove>();
	attack_ = nullptr;
}


void Player::update()
{
	
	if (playerState_->hasFinished()) {
		if (Controller::input_->jumpPressed(side_) && side_ == RIGHT){
			playerState_ = std::make_shared<PlayerJump>(this->rect().x, this->rect().y, 100);
		}
		else if (Controller::input_->jumpPressed(side_) && side_ == LEFT) {
			playerState_ = std::make_shared<PlayerJump>(this->rect().x, this->rect().y, -100);
		}
		else if ((Controller::input_->attackPressed(side_) && side_ == RIGHT) || (Controller::input_->attackPressed(side_) && side_ == LEFT))
		{
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
