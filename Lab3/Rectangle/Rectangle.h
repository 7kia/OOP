#pragma once

#include <string>
#include <algorithm> 
#include <iostream>
#include "Vector2i.h"

class CRectangle
{
public:
	CRectangle();
	// TODO: keep width, height as Vector2i
	CRectangle(Vector2i leftTopPoint, Vector2i size);
	~CRectangle();

	void			SetLeftTopPoint(Vector2i leftTopPoint);
	Vector2i		GetLeftTopPoint() const;

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
	Vector2i m_leftTopPoint;
	int			 m_width;
	int			 m_height;
};