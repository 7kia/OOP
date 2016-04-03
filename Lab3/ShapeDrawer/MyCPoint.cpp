#include "stdafx.h"
#include "MyCPoint.h"



MyCPoint::MyCPoint()
	: IShape("Point", DEFAULT_COLOR)
{
}


MyCPoint::MyCPoint(sf::Vector2f position, SColor color)
	: IShape("Point", color)
	, m_position(position)
{
}


MyCPoint::~MyCPoint()
{
}


float MyCPoint::GetPerimeter() const
{
	return 0;
}

float MyCPoint::GetArea() const
{
	return 0;
}

std::string MyCPoint::GetStringPresentation() const
{
	std::ostringstream strm;
	strm << m_type << ":" << std::endl << std::setprecision(10)
		<< "\tPosition = (" << m_position.x << ", " << m_position.y << ")" << std::endl
		<< "\tLength = " << GetPerimeter() << std::endl
		<< "\tColor = " << GetColor() << std::endl
		<< "\tArea = " << GetArea() << std::endl;
	return strm.str();
}

void MyCPoint::SetPosition(sf::Vector2f position)
{
	m_position = position;
}

void MyCPoint::SetPosition(float x, float y)
{
	m_position = sf::Vector2f(x, y);
}

sf::Vector2f MyCPoint::GetPosition() const
{
	return m_position;
}

