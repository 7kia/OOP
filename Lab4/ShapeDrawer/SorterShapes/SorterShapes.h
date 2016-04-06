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
class CSorterShapes
{
public:
	typedef std::pair<float, std::shared_ptr<IShape>> elementSortList;
	typedef std::vector<std::shared_ptr<IShape>> sortList;
public:
	void		PrintListShapes(const sortList &listShapes, std::ostream &strm);

	sortList	GetSortedByDecreasePerimeterList(const sortList& listShapes);
	sortList	GetSortedByAreaList(const sortList& listShapes);


	sortList	GetSortedList(const std::vector<std::shared_ptr<IShape>>& listShapes,
								std::function<float()> getMethod, 
								std::function<bool(float, float)> conditionSorting);
private:
};