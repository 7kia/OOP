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

void IShape::AppendProperties(std::ostream & strm) const
{
	strm << m_type << ":" << std::endl
		<< "\tFill color = " << GetFillColor() << std::endl
		<< "\tPerimeter = " << GetPerimeter() << std::endl
		<< "\tArea = " << GetArea() << std::endl;
}

SColor::SColor(uint8_t r, uint8_t g, uint8_t b)
{
	red = r;
	blue = b;
	green = g;
}

SColor::SColor(const std::string & value)
{
	if ((value[0] == '#') && (value.size() == 7))
	{
		std::istringstream valueRed(value.substr(1, 2));
		std::istringstream valueBlue(value.substr(3, 2));
		std::istringstream valueGreen(value.substr(5, 2));
		valueRed >> std::hex >> red;
		valueBlue >> std::hex >> blue;
		valueGreen >> std::hex >> green;
	}
	else
	{
		throw std::invalid_argument(MESSAGE_INCORRECT_VALUE);
	}
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

std::ostream & operator<<(std::ostream & stream, sf::Vector2f const & vector)
{
	stream << "(" << vector.x << ", " << vector.x << ")";
	return stream;
}
