#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment()
	: IShape("Line segment", DEFAULT_COLOR)
{
}


CLineSegment::CLineSegment(sf::Vector2f firstPoint, sf::Vector2f secondPoint, SColor color)
	: IShape("Line segment", color)
	, m_positionFirstPoint(firstPoint)
	, m_positionSecondPoint(secondPoint)
{
}

CLineSegment::~CLineSegment()
{
}

float CLineSegment::GetPerimeter() const
{
	
	return sqrtf(std::powf((m_positionSecondPoint.x - m_positionFirstPoint.x), 2.f)
					+
				std::powf((m_positionSecondPoint.y - m_positionFirstPoint.y), 2.f));
}

float CLineSegment::GetArea() const
{
	return 0.0f;
}

std::string CLineSegment::GetStringPresentation() const
{
	std::ostringstream strm;
	strm << std::setprecision(3);
	strm << m_type << ":" << std::endl
		<< "\tPosition first point = (" << m_positionFirstPoint.x << ", " << m_positionFirstPoint.y << ")" << std::endl
		<< "\tPosition second point = (" << m_positionSecondPoint.x << ", " << m_positionSecondPoint.y << ")" << std::endl
		<< "\tColor = " << GetColor() << std::endl
		<< "\tLength = " << GetPerimeter() << std::endl
		<< "\tArea = " << GetArea() << std::endl;
	return strm.str();
}
