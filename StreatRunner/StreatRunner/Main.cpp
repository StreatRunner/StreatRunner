
# include <Siv3D.hpp>
#include"Player.h"
#include"Ground.h"
#include"CollisionPlayerPlayer.h"
#include "CollisionPlayerAttack.h"

void draw(Player player1, Player player2, Ground ground);

void Main()
{
	Window::Resize(1280, 720);
	Graphics::SetBackground(Palette::White);
	Ground ground;
	Player player1(Player::LEFT);
	Player player2(Player::RIGHT);

	while (System::Update())
	{
		player1.update();
		player2.update();
		
		CollisionPlayerPlayer().detect(player1, player2);
		CollisionPlayerAttack().detect(player1, player2);

		draw(player1, player2, ground);
	}
}

void draw(Player player1, Player player2, Ground ground)
{
	if (player1.getAttack() != nullptr) {
		player1.getAttack()->draw(Palette::Yellow);
	}
	if (player2.getAttack() != nullptr) {
		player2.getAttack()->draw(Palette::Yellow);
	}
	player1.rect().draw(Palette::Blue);
	player2.rect().draw(Palette::Red);
	ground.rectClone().draw(Palette::Black);
}
