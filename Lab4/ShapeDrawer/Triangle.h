#pragma once

#include "LineSegment.h"
#include "ISolidShape.h"

class CTriangle final:
	public ISolidShape
{
public:
	CTriangle();
	CTriangle(sf::Vector2f firstPoint, sf::Vector2f secondPoint, sf::Vector2f thirdPoint,
		SColor boundColor, SColor fillColor);
	~CTriangle();

	float				GetPerimeter() const override;
	float				GetArea() const override;
	std::string			GetStringPresentation() const override;

private:
	CLineSegment m_firstLine;
	CLineSegment m_secondLine;
	CLineSegment m_thirdLine;
};

