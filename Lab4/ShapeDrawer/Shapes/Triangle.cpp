#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle()
	: ISolidShape("Triangle", DEFAULT_COLOR, DEFAULT_COLOR)
{
}

CTriangle::CTriangle(sf::Vector2f firstPoint, sf::Vector2f secondPoint, sf::Vector2f thirdPoint,
					SColor fillColor, SColor outlineColor)
	: ISolidShape("Triangle", fillColor, outlineColor)
	, m_firstLine(firstPoint, secondPoint, outlineColor)
	, m_secondLine(secondPoint, thirdPoint, outlineColor)
	, m_thirdLine(thirdPoint, firstPoint, outlineColor)
{
}


CTriangle::~CTriangle()
{
}

float CTriangle::GetPerimeter() const
{
	return m_firstLine.GetPerimeter() + m_secondLine.GetPerimeter() + m_thirdLine.GetPerimeter();
}

float CTriangle::GetArea() const
{
	float halfPerimeter = GetPerimeter() / 2.f;
	float lengthFirtsLine = m_firstLine.GetPerimeter();
	float lengthSecondLine = m_secondLine.GetPerimeter();
	float lengthThirdLine = m_thirdLine.GetPerimeter();

	return sqrtf(halfPerimeter * (halfPerimeter - lengthFirtsLine)
								* (halfPerimeter - lengthSecondLine)
								* (halfPerimeter - lengthThirdLine));
}

std::string CTriangle::GetStringPresentation() const
{
	std::ostringstream strm;
	strm << std::setprecision(3);
	strm << m_type << ":" << std::endl
		<< "\tPosition first point = (" << m_firstLine.GetPositiionFirstPoint().x 
										<< ", " << m_firstLine.GetPositiionFirstPoint().y << ")" << std::endl
		<< "\tPosition second point = (" << m_firstLine.GetPositiionSecondPoint().x
										<< ", " << m_firstLine.GetPositiionSecondPoint().y << ")" << std::endl
		<< "\tPosition third point = (" << m_secondLine.GetPositiionSecondPoint().x
										<< ", " << m_secondLine.GetPositiionSecondPoint().y << ")" << std::endl
		<< "\tOutline color = " << GetOutlineColor() << std::endl
		<< "\tFill color = " << GetFillColor() << std::endl
		<< "\tPerimeter = " << GetPerimeter() << std::endl
		<< "\tArea = " << GetArea() << std::endl;
	return strm.str();
}

