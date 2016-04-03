#include "stdafx.h"
#include "IShape.h"


IShape::IShape(const std::string & type, SColor color)
	: m_type(type)
	, m_color(color)
{
}


IShape::~IShape()
{
}

void IShape::SetColor(SColor color)
{
	m_color = color;
}

void IShape::SetColor(uint8_t r, uint8_t g, uint8_t b)
{
	m_color.red = r;
	m_color.blue = b;
	m_color.green = g;
}

SColor IShape::GetColor() const
{
	return m_color;
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
