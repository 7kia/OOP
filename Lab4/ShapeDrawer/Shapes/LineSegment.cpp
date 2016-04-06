#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment()
	: IShape("Line", DEFAULT_COLOR)
{
}


CLineSegment::CLineSegment(sf::Vector2f firstPoint, sf::Vector2f secondPoint, SColor color)
	: IShape("Line", color)
	, m_firstPoint(firstPoint, color)
	, m_secondPoint(secondPoint, color)
{
}

CLineSegment::~CLineSegment()
{
}

float CLineSegment::GetPerimeter() const
{
	
	return sqrtf(std::powf((m_firstPoint.GetPosition().x - m_secondPoint.GetPosition().x), 2.f)
					+
				std::powf((m_firstPoint.GetPosition().y - m_secondPoint.GetPosition().y), 2.f));
}

float CLineSegment::GetArea() const
{
	return 0.0f;
}

std::string CLineSegment::GetStringPresentation() const
{
	std::ostringstream strm;
	strm << std::setprecision(3);

	IShape::AppendProperties(strm);
	CLineSegment::AppendProperties(strm);

	return strm.str();
}

void CLineSegment::SetPositionFirstPoint(sf::Vector2f position)
{
	m_firstPoint.SetPosition(position);
}

void CLineSegment::SetPositionFirstPoint(float x, float y)
{
	m_firstPoint.SetPosition(x, y);
}

sf::Vector2f CLineSegment::GetPositiionFirstPoint() const
{
	return m_firstPoint.GetPosition();
}

void CLineSegment::SetPositionSecondPoint(sf::Vector2f position)
{
	m_firstPoint.SetPosition(position);
}

void CLineSegment::SetPositionSecondPoint(float x, float y)
{
	m_firstPoint.SetPosition(x, y);
}

sf::Vector2f CLineSegment::GetPositiionSecondPoint() const
{
	return m_secondPoint.GetPosition();
}

void CLineSegment::AppendProperties(std::ostream & strm) const
{
	strm << "\tPosition first point = (" << m_firstPoint.GetPosition().x << ", "
										<< m_firstPoint.GetPosition().y << ")" << std::endl
		<< "\tPosition second point = (" << m_secondPoint.GetPosition().x << ", " 
										<< m_secondPoint.GetPosition().y << ")" << std::endl;
}
