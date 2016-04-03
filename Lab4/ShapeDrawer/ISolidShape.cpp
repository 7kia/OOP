#include "stdafx.h"
#include "ISolidShape.h"

ISolidShape::ISolidShape(const std::string & type, SColor boundColor, SColor fillColor)
	: IShape(type, boundColor)
	, m_fillColor(fillColor)
{
}

ISolidShape::~ISolidShape()
{
}

void ISolidShape::SetBoundColor(uint8_t r, uint8_t g, uint8_t b)
{
	m_color.red = r;
	m_color.blue = b;
	m_color.green = g;
}

void ISolidShape::SetBoundColor(SColor color)
{
	m_color = color;
}

SColor ISolidShape::GetBoundColor() const
{
	return m_color;
}

void ISolidShape::SetFillColor(uint8_t r, uint8_t g, uint8_t b)
{
	m_fillColor.red = r;
	m_fillColor.blue = b;
	m_fillColor.green = g;
}

void ISolidShape::SetFillColor(SColor color)
{
	m_fillColor = color;
}

SColor ISolidShape::GetFillColor() const
{
	return m_fillColor;
}
