
# include <Siv3D.hpp>
#include"Player.h"
#include"Ground.h"
#include"CollisionPlayerPlayer.h"
#include "CollisionPlayerAttack.h"

void draw(Player player1, Player player2, Rect goal1, Rect goal2);
Color detectGoal(Player player1, Player player2, Rect goal1, Rect goal2);

void Main()
{
	Window::Resize(1280, 720);
	Graphics::SetBackground(Palette::White);
	Color winner;
	Player player1(Player::LEFT);
	Player player2(Player::RIGHT);
	Rect goal1(1080, 0, 5, 720); 
	Rect goal2(200, 0, 5, 720);

	while (System::Update())	{
		player1.update();
		player2.update();
		
		CollisionPlayerPlayer().detect(player1, player2);
		CollisionPlayerAttack().detect(player1, player2);
		winner = detectGoal(player1, player2,goal1, goal2);
		if (winner != Palette::Black) {
			break;
		}
		draw(player1, player2, goal1, goal2);
	}

}

void draw(Player player1, Player player2, Rect goal1, Rect goal2)
{
	static Ground ground;
	if (player1.getAttack() != nullptr) {
		player1.getAttack()->draw(Palette::Yellow);
	}
	if (player2.getAttack() != nullptr) {
		player2.getAttack()->draw(Palette::Yellow);
	}
	player1.rect().draw(Palette::Blue);
	player2.rect().draw(Palette::Red);
	goal1.draw(Palette::Green);
	goal2.draw(Palette::Green);
	ground.rectClone().draw(Palette::Black);
}

Color detectGoal(Player player1, Player player2, Rect goal1, Rect goal2)
{
	if (player1.rect().center.x > goal1.center.x) {
		return Palette::Blue;
	}
	else if (player2.rect().center.x < goal2.center.x) {
		return Palette::Red;
	}
	else {
		return Palette::Black;
	}
}
