#pragma once

#include "IShape.h"

static const SColor DEFAULT_FILL_COLOR(0, 0, 0);

class ISolidShape
	: public IShape
{
public:
	ISolidShape(const std::string & type, SColor boundColor, SColor fillColor);
	virtual ~ISolidShape();

	// excess because the type figure have not one color
	void				SetColor(SColor color) = 0;
	void				SetColor(uint8_t r, uint8_t g, uint8_t b) = 0;
	SColor				GetColor() const = 0;

	void				SetBoundColor(uint8_t r, uint8_t g, uint8_t b);
	void				SetBoundColor(SColor color);
	SColor				GetBoundColor() const;

	void				SetFillColor(uint8_t r, uint8_t g, uint8_t b);
	void				SetFillColor(SColor color);
	SColor				GetFillColor() const;
private:
	SColor m_fillColor = DEFAULT_FILL_COLOR;
};

