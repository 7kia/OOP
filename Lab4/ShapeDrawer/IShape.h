#pragma once

#include "SFML\Graphics.hpp"
#include <cmath>
#include <iomanip>
#include <sstream>

struct SColor
{
	SColor(uint8_t r, uint8_t g, uint8_t b);
	uint8_t red = 0;
	uint8_t blue = 0;
	uint8_t green = 0;
	
	bool operator==(SColor const& other) const;
};
std::ostream& operator<<(std::ostream& stream, SColor const& color);

static const SColor DEFAULT_COLOR(0, 0, 0);
static const int AMOUNT_NUMBERS_FOR_OUTPUT = 3;

class IShape
{
public:
	IShape(const std::string & type, SColor color);
	virtual ~IShape();

	virtual float				GetPerimeter() const = 0;
	virtual float				GetArea() const = 0;
	virtual std::string			GetStringPresentation() const = 0;

	virtual void						SetColor(SColor color);
	virtual void						SetColor(uint8_t r, uint8_t g, uint8_t b);
	virtual SColor						GetColor() const;
protected:
	SColor						m_color;
	std::string					m_type;
};

