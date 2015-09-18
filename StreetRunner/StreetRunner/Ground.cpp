#include "Ground.h"


Ground::Ground()
{
	rect = Rect(0, 620, 1280, 100);
}

Rect Ground::rectClone() const
{
	return rect;
}

Ground::~Ground()
{}
