#include "stdafx.h"
#include <algorithm> 

#include "Rectangle.h"

template <typename T>
bool IsBetween(const T& value, const T& lowerBound, const T& upperBound)
{
	return (value >= lowerBound) && (value <= upperBound);
}

CRectangle::CRectangle()
	:m_width(0),
	m_height(0)
{
}

CRectangle::CRectangle(Vector2i leftTopPoint, Vector2i size)
	:m_leftTopPoint(leftTopPoint)
{
	SetWidth(size.x);
	SetHeight(size.y);
}

CRectangle::~CRectangle()
{
}

void CRectangle::SetLeftTopPoint(Vector2i leftTopPoint)
{
	m_leftTopPoint = leftTopPoint;
}

Vector2i CRectangle::GetLeftTopPoint() const
{
	return m_leftTopPoint;
}

void CRectangle::SetWidth(int width)
{
	if (width < 0)
	{
		m_width = 0;
	}
	else
	{
		m_width = width;
	}
}

int CRectangle::GetWidth() const
{
	return m_width;
}

void CRectangle::SetHeight(int height)
{
	if (height < 0)
	{
		m_height = 0;
	}
	else
	{
		m_height = height;
	}
}

int CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::SetLeft(int left)
{
	m_leftTopPoint.x = left;
}

int CRectangle::GetLeft() const
{
	return m_leftTopPoint.x;
}

void CRectangle::SetRight(int right)
{
	m_leftTopPoint.x = right - m_width;
}

int CRectangle::GetRight() const
{
	return m_width + GetLeft();
}

void CRectangle::SetTop(int top)
{
	m_leftTopPoint.y = top;
}

int CRectangle::GetTop() const
{
	return m_leftTopPoint.y;
}

void CRectangle::SetBottom(int bottom)
{
	m_leftTopPoint.y = bottom - m_height;
}

int CRectangle::GetBottom() const
{
	return m_leftTopPoint.y + m_height;
}

int CRectangle::GetPerimeter() const
{
	return (m_height + m_width) * 2;
}

int CRectangle::GetArea() const
{
	return m_height * m_width;
}

void CRectangle::Move(int dx, int dy)
{
	m_leftTopPoint.x += dx;
	m_leftTopPoint.y += dy;
}

void CRectangle::Scale(int sx, int sy)
{
	if ((sx > 0) && (sy > 0))
	{
		m_width *= sx;
		m_height *= sy;
	}
}

// TODO: use min/max to calculate new bounds
bool CRectangle::Intersect(CRectangle const & other)
{
	
	int leftThis = GetLeft();
	int leftOther = other.GetLeft();

	int rightThis = GetRight();
	int rightOther = other.GetRight();

	int topThis = GetTop();
	int topOther = other.GetTop();

	int bottomThis = GetBottom();
	int bottomOther = other.GetBottom();

	int leftIntersect = std::max(leftThis, leftOther);
	int topIntersect = std::max(topThis, topOther);
	int rightIntersect = std::min(rightThis, rightOther);
	int bottomIntersect = std::min(bottomThis, bottomOther);
	

	int widthIntersect = rightIntersect - leftIntersect;
	int heightIntersect = bottomIntersect - topIntersect;

	if (widthIntersect && heightIntersect)
	{
		SetWidth(widthIntersect);
		SetHeight(heightIntersect);
		SetLeftTopPoint(Vector2i(leftIntersect, topIntersect));

		return true;
	}

	m_width = 0;
	m_height = 0;
	return false;
}
