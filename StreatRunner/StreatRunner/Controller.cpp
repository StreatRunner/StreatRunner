#include"Controller.h"

#include<Siv3D.hpp>

#include"Keyboard.h"
#include"Gamepad.h"

std::shared_ptr<Controller> Controller::input_ = std::make_shared<::Gamepad>();
