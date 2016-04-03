#pragma once

#include "IShape.h"

static const SColor DEFAULT_FILL_COLOR(0, 0, 0);

class ISolidShape
	: public IShape
{
public:
	ISolidShape();
	~ISolidShape();

	virtual void				SetFillColor() const = 0;
	virtual SColor				GetFillColor() const = 0;
private:
	SColor m_fillColor = DEFAULT_FILL_COLOR;
};

