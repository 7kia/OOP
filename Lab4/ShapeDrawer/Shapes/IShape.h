#pragma once

#include "SFML\Graphics.hpp"
#include <boost/math/constants/constants.hpp>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

class IShape
{
public:
	virtual ~IShape();

	virtual float				GetPerimeter() const = 0;
	virtual float				GetArea() const = 0;
	virtual std::string			GetStringPresentation() const = 0;
protected:
	virtual void				AppendProperties(std::ostream & strm) const = 0;
};

