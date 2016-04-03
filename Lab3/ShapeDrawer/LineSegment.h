#pragma once

#include "IShape.h"

class CLineSegment final:
	public IShape
{
public:
	CLineSegment();
	CLineSegment(sf::Vector2f firstPoint, sf::Vector2f secondPoint, SColor color);
	~CLineSegment();

	float				GetPerimeter() const override;
	float				GetArea() const override;
	std::string			GetStringPresentation() const override;
private:
	sf::Vector2f		m_positionFirstPoint;
	sf::Vector2f		m_positionSecondPoint;
};

