#include "stdafx.h"
#include "ISolidShape.h"

ISolidShape::ISolidShape(const std::string & type, SColor fillColor, SColor boundColor)
	: IShape(type, fillColor)
	, m_outlineColor(boundColor)
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

void ISolidShape::AppendProperties(std::ostream & strm) const
{
	strm << "\tOutline color = " << GetOutlineColor() << std::endl;
}
