#pragma once

#include "IShape.h"

static const SColor DEFAULT_FILL_COLOR(0, 0, 0);

class ISolidShape
	: public IShape
{
public:
	ISolidShape(const std::string & type, SColor boundColor, SColor fillColor);
	virtual ~ISolidShape();

	void				SetOutlineColor(uint8_t r, uint8_t g, uint8_t b);
	void				SetOutlineColor(SColor color);
	SColor				GetOutlineColor() const;
protected:
	void				AppendProperties(std::ostream & strm) const;
private:
	SColor				m_outlineColor = DEFAULT_FILL_COLOR;
};

