#pragma once
#include <Siv3D.hpp>

class Ground
{
private:
	Rect rect;
public:
	Rect rectClone() const;
	Ground();
	~Ground();
};

