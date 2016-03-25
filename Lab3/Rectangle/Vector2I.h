#pragma once

struct Vector2I
{
	Vector2I();
	Vector2I(int firstNumber, int secondNumber);
	bool operator==(const Vector2I &right) const;

	int x;
	int y;
};