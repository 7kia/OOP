#include "stdafx.h"
#include "Vector2I.h"

Vector2I::Vector2I()
	: x(0)
	, y(0)
{
}

Vector2I::Vector2I(int firstNumber, int secondNumber)
	: x(firstNumber)
	, y(secondNumber)
{
}

bool Vector2I::operator==(const Vector2I & right) const
{
	return (x == right.x) && (y == right.y);
}