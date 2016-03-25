#pragma once

#include "Vector2I.h"

class CRectangle
{
public:
	CRectangle();
	CRectangle(Vector2I leftTopPoint, int width, int height);
	~CRectangle();

	void			SetLeftTopPoint(Vector2I leftTopPoint);
	Vector2I	GetLeftTopPoint() const;

	void			SetWidth(int width);
	int				GetWidth() const;

	void			SetHeight(int height);
	int				GetHeight() const;

	void			SetLeft(int left);
	int				GetLeft() const;

	void			SetRight(int right);
	int				GetRight() const;

	void			SetTop(int top);
	int				GetTop() const;

	void			SetBottom(int bottom);
	int				GetBottom() const;

	int				GetPerimeter() const;
	int				GetArea() const;

	void			Move(int dx, int dy);
	void			Scale(int sx, int sy);
	bool			Intersect(CRectangle const& other);
private:
	Vector2I m_leftTopPoint;
	int			 m_width;
	int			 m_height;
};