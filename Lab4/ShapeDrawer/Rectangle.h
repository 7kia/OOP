#pragma once

#include "LineSegment.h"
#include "ISolidShape.h"

class CRectangle final :// was exported from lab 3 Rectangle
	public ISolidShape
{
public:
	CRectangle();
	CRectangle(sf::Vector2f leftTopPoint, float width, float height,
				SColor fillColor, SColor outlineColor);
	~CRectangle();

	void				SetLeftTopPoint(sf::Vector2f leftTopPoint);
	sf::Vector2f		GetLeftTopPoint() const;

	void				SetWidth(float width);
	float				GetWidth() const;

	void				SetHeight(float height);
	float				GetHeight() const;

	void				SetLeft(float left);
	float				GetLeft() const;

	void				SetRight(float right);
	float				GetRight() const;

	void				SetTop(float top);
	float				GetTop() const;

	void				SetBottom(float bottom);
	float				GetBottom() const;

	float				GetPerimeter() const override;
	float				GetArea() const override;
	std::string			GetStringPresentation() const override;

	void				Move(float dx, float dy);
	void				Scale(float sx, float sy);
	bool				Intersect(CRectangle const& other);
private:
	sf::Vector2f		m_leftTopPoint;
	float				m_width;
	float				m_height;
};