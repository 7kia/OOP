#pragma once

#include "../Shapes/CShape.h"
#include "../Shapes/ISolidShape.h"
#include "../Shapes/Circle.h"
#include "../Shapes/LineSegment.h"
#include "../Shapes/MyCPoint.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Triangle.h"
#include <vector>
#include <memory>
#include <boost/range/algorithm/transform.hpp>

typedef std::vector<std::shared_ptr<CShape>> ListDataShapes;
typedef std::function<bool(const std::shared_ptr<CShape> &, const std::shared_ptr<CShape> &)> ConditionSwap;

void		PrintListShapes(const ListDataShapes &listShapes, std::ostream &strm);

ListDataShapes GetSortedList(const ListDataShapes& listShapes,
							ConditionSwap conditionSwap);
