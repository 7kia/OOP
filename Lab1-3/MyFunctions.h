#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#pragma once

struct Vector2UL
{
	Vector2UL();
	Vector2UL(size_t firstNumber, size_t secondNumber);
	bool operator==(const Vector2UL &right) const;

	size_t x;
	size_t y;
};

namespace MyFunctions
{
	bool IsIn(Vector2UL value , const std::vector<Vector2UL> &list);
};


#endif // MYFUNCTIONS_H
