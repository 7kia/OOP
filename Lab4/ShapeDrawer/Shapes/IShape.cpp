#include "stdafx.h"
#include "IShape.h"


IShape::IShape(const std::string & type, SColor color)
	: m_type(type)
	, m_fillColor(color)
{
}


IShape::~IShape()
{
}

void IShape::SetFillColor(SColor color)
{
	m_fillColor = color;
}

void IShape::SetFillColor(uint8_t r, uint8_t g, uint8_t b)
{
	m_fillColor.red = r;
	m_fillColor.blue = b;
	m_fillColor.green = g;
}

SColor IShape::GetFillColor() const
{
	return m_fillColor;
}

SColor::SColor(uint8_t r, uint8_t g, uint8_t b)
{
	red = r;
	blue = b;
	green = g;
}

bool SColor::operator==(SColor const & other) const
{
	return (red == other.red) && (blue == other.blue) && (green == other.green);
}

std::ostream& operator<<(std::ostream& stream, SColor const& color)
{
	stream << "#" << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(color.red)
					<< std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(color.blue)
					<< std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(color.green);
	return stream;
}
