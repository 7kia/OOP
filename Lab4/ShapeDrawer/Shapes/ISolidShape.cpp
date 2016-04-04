#include "stdafx.h"
#include "ISolidShape.h"

ISolidShape::ISolidShape(const std::string & type, SColor boundColor, SColor fillColor)
	: IShape(type, boundColor)
	, m_outlineColor(fillColor)
{
}

ISolidShape::~ISolidShape()
{
}


void ISolidShape::SetOutlineColor(uint8_t r, uint8_t g, uint8_t b)
{
	m_outlineColor.red = r;
	m_outlineColor.blue = b;
	m_outlineColor.green = g;
}

void ISolidShape::SetOutlineColor(SColor color)
{
	m_outlineColor = color;
}

SColor ISolidShape::GetOutlineColor() const
{
	return m_outlineColor;
}
