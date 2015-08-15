
# include <Siv3D.hpp>
#include"Player.h"

void Main()
{
	Window::Resize(1280, 720);
	Graphics::SetBackground(Palette::White);
	Rect ground(0, 620, 1280, 100);
	Player player1(Player::LEFT);
	Player player2(Player::RIGHT);

	while (System::Update())
	{
		player1.update();
		player2.update();
		if (player1.getAttack() != nullptr){
			player1.getAttack()->draw(Palette::Yellow);
		}
		if (player2.getAttack() != nullptr){
			player2.getAttack()->draw(Palette::Yellow);
		}
		player1.rect().draw(Palette::Blue);
		player2.rect().draw(Palette::Red);
		ground.draw(Palette::Black);
	}
}
