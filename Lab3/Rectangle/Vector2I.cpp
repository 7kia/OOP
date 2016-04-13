#include "stdafx.h"
#include "Vector2i.h"
#include <tuple>

Vector2i::Vector2i()
	: x(0)
	, y(0)
{
}

Vector2i::Vector2i(int x, int y)
	: x(x)
	, y(y)
{
}

bool Vector2i::operator==(const Vector2i & right) const
{
	return std::tie(x, y) == std::tie(right.x, right.y);
}