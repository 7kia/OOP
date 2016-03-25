#include "stdafx.h"
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

CRectangle::CRectangle(Vector2I leftTopPoint, int width, int height)
	:m_leftTopPoint(leftTopPoint)
{
	SetWidth(width);
	SetHeight(height);
}

CRectangle::~CRectangle()
{
}

void CRectangle::SetLeftTopPoint(Vector2I leftTopPoint)
{
	m_leftTopPoint = leftTopPoint;
}

Vector2I CRectangle::GetLeftTopPoint() const
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

bool CRectangle::Intersect(CRectangle const & other)
{
	bool leftIsIntersect = IsBetween(GetLeft(), other.GetLeft(), other.GetRight());
	bool rightIsIntersect = IsBetween(GetRight(), other.GetLeft(), other.GetRight());
	bool topIsIntersect = IsBetween(GetTop(), other.GetTop(), other.GetBottom());
	bool bottomIsIntersect = IsBetween(GetBottom(), other.GetTop(), other.GetBottom());


	if (leftIsIntersect && topIsIntersect)
	{
		return true;
	}
	else if (rightIsIntersect && topIsIntersect)
	{
		return true;
	}
	else if (rightIsIntersect && bottomIsIntersect)
	{
		return true;
	}
	else if (leftIsIntersect && bottomIsIntersect)
	{
		return true;
	}


	m_width = 0;
	m_height = 0;
	return false;
}
