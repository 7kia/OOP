#include "stdafx.h"
#include "Circle.h"



CCircle::CCircle()
	: ISolidShape("Circle", DEFAULT_COLOR, DEFAULT_COLOR)
{
}

CCircle::CCircle(sf::Vector2f center, float radiuse,
				SColor fillColor, SColor outlineColor)
	: ISolidShape("Circle", fillColor, outlineColor)
	, m_positionCenter(center)
	, m_radiuse(radiuse)
{
}


CCircle::~CCircle()
{
}

float CCircle::GetPerimeter() const
{
	return pi * 2.f * m_radiuse;
}

float CCircle::GetArea() const
{
	return pi * m_radiuse * m_radiuse;
}

std::string CCircle::GetStringPresentation() const
{
	std::ostringstream strm;
	strm << std::setprecision(3);

	IShape::AppendProperties(strm);
	ISolidShape::AppendProperties(strm);
	CCircle::AppendProperties(strm);

	return strm.str();
}

void CCircle::SetRadiuse(float radiuse)
{
	if (radiuse < 0.f)
	{
		m_radiuse = 0;
	}
	else
	{
		m_radiuse = radiuse;
	}
}

float CCircle::GetRadiuse() const
{
	return m_radiuse;
}

void CCircle::SetPositionCenter(float x, float y)
{
	m_positionCenter = { x, y };
}

void CCircle::SetPositionCenter(sf::Vector2f position)
{
	m_positionCenter = position;
}

sf::Vector2f CCircle::GetPosition() const
{
	return m_positionCenter;
}

void CCircle::AppendProperties(std::ostream & strm) const
{
	strm << "\tPosition center = (" << m_positionCenter.x << ", " 
									<< m_positionCenter.y << ")" << std::endl
		<< "\tRadiuse = " << GetRadiuse() << std::endl;
}
