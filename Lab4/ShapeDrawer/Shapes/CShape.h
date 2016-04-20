#pragma once

#include <boost/math/constants/constants.hpp>

#include "IShape.h"


static const float pi = boost::math::constants::pi<float>();
static const std::string MESSAGE_INCORRECT_VALUE = "Incorrect value!!!";
struct SColor
{
	SColor(uint8_t r, uint8_t g, uint8_t b);
	SColor(const std::string &value);
	uint8_t red = 0;
	uint8_t green = 0;
	uint8_t blue = 0;

	bool operator==(const SColor & other) const;
};
std::ostream& operator<<(std::ostream& stream, SColor const& color);

static const SColor DEFAULT_COLOR(0, 0, 0);
static const int AMOUNT_NUMBERS_FOR_OUTPUT = 3;

std::ostream& operator<<(std::ostream& stream, const sf::Vector2f & vector);


class CShape :
	public IShape
{
public:
	CShape(const std::string & type, SColor color);
	~CShape();

	void						SetFillColor(SColor color);
	void						SetFillColor(uint8_t r, uint8_t g, uint8_t b);
	SColor						GetFillColor() const;

	std::string					GetType() const;// for render

	void						AppendProperties(std::ostream & strm) const override;

protected:
	SColor						m_fillColor;
	std::string					m_type;
};