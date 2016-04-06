#pragma once

#include "../Shapes/IShape.h"
#include "../Shapes/ISolidShape.h"
#include "../Shapes/Circle.h"
#include "../Shapes/LineSegment.h"
#include "../Shapes/MyCPoint.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Triangle.h"
#include <vector>
#include <memory>

typedef std::pair<float, std::shared_ptr<IShape>> elementSortList;
typedef std::vector<std::shared_ptr<IShape>> listDataShapes;

void		PrintListShapes(const listDataShapes &listShapes, std::ostream &strm);

listDataShapes	GetSortedByDecreasePerimeterList(const listDataShapes& listShapes);
listDataShapes	GetSortedByAreaList(const listDataShapes& listShapes);

// TODO : delete if will not neccessary
listDataShapes	GetSortedList(const std::vector<std::shared_ptr<IShape>>& listShapes,
							std::function<float()> getMethod, 
							std::function<bool(float, float)> conditionSorting);
