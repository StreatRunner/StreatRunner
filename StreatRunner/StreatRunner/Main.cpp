
# include <Siv3D.hpp>
# include <HamFramework.hpp>
#include"Player.h"
#include"Ground.h"
#include"CollisionPlayerPlayer.h"
#include "CollisionPlayerAttack.h"
#include"Controller.h"

void draw(Player player1, Player player2, Rect goal1, Rect goal2);
Color detectGoal(Player player1, Player player2, Rect goal1, Rect goal2);

struct GameData
{
	int t;
};

// シーンのキーの型と、共有データの型を指定
using MyApp = SceneManager<String, GameData>;

struct Game : MyApp::Scene
{
	Player player1;
	Player player2;
	Rect goal1;
	Rect goal2;

	Game() :player1(Player::LEFT), player2(Player::RIGHT), goal1(1080, 0, 5, 720), goal2(200, 0, 5, 720)
	{

	}

	void update() override
	{
		Color winner;
		
		player1.update();
		player2.update();

		CollisionPlayerPlayer().detect(player1, player2);
		CollisionPlayerAttack().detect(player1, player2);
		winner = detectGoal(player1, player2, goal1, goal2);
		if (winner != Palette::Black)
			changeScene(L"Start", 3000);
	}

	void draw() const override
	{
		::draw(player1, player2, goal1, goal2);
	}
};

struct Start : MyApp::Scene
{
	Font title;
	Font message;
	Texture texture;

	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override
	{
		title = Font(80);
		message = Font(30);
		texture = Texture(L"GamepadConfig.png");
	}

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override
	{
		if (Controller::input_->anyKeyPressed()) {
			// 次のシーケンスと、フェードイン・アウトの時間（ミリ秒）
			changeScene(L"Game", 200);
		}
	}

	// 毎フレーム update() の次に呼ばれる
	void draw() const override
	{
		title(L"Street Runner").drawCenter({ Window::Center().x, 85 }, Palette::Blue);
		message(L"Press any button").drawCenter({ Window::Center().x, 610 }, Palette::Orange);
		texture.scale(0.4).drawAt(Window::Center());
	}
};

void Main()
{
	Window::SetFullscreen(true, { 1280, 720 });
	//Window::Resize(1280, 720);
	Cursor::SetStyle(CursorStyle::None);
	Graphics::SetBackground(Palette::White);
	
	MyApp manager(SceneManagerOption::None);

	// フェードイン・アウト時の色
	manager.setFadeColor(Palette::Black);

	// シーンを設定
	manager.add<Start>(L"Start");
	manager.add<Game>(L"Game");

	while (System::Update()) {
		if (!manager.updateAndDraw())
			break;
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
