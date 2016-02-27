#include "stdafx.h"
#include "MyFunctions.h"

Vector2UL::Vector2UL()
{
}

Vector2UL::Vector2UL(size_t firstNumber, size_t secondNumber)
{
	x = firstNumber;
	y = secondNumber;
}

bool Vector2UL::operator==(const Vector2UL & right) const
{
	if ((x == right.x) && (y == right.y))
	{
		return true;
	}
	return false;
}


bool MyFunctions::IsIn(Vector2UL value, const std::vector<Vector2UL> &list)
{
	for (auto element : list)
	{
		if (value == element)
		{
			return true;
		}
	}
	return false;
}
