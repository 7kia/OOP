#pragma once

#include "../Shapes/IShape.h"
#include "../Shapes/ISolidShape.h"
#include "../Shapes/Circle.h"
#include "../Shapes/LineSegment.h"
#include "../Shapes/MyCPoint.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Triangle.h"
#include <vector>

class CSorterShapes
{
public:
	void		PrintListShapes(std::vector<IShape*> &listShapes, std::ostringstream &strm);
private:
};