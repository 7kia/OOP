#pragma once

struct Vector2i
{
	explicit Vector2i();
	explicit Vector2i(int x, int y);
	bool operator==(const Vector2i &right) const;

	int x;
	int y;
};