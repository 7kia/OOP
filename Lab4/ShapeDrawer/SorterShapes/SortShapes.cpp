#include "stdafx.h"
#include "SortShapes.h"

void PrintListShapes(const sortList& listShapes, std::ostream &strm)
{
	for (const auto& shape : listShapes)
	{
		strm << shape->GetStringPresentation();
	}
}

sortList GetSortedByDecreasePerimeterList(const sortList& listShapes)
{
	std::vector<elementSortList> sortedList;
	for (const auto &shape : listShapes)
	{
		sortedList.push_back({ shape->GetPerimeter(), shape });
	}

	std::sort(sortedList.begin(), sortedList.end());
	std::reverse(sortedList.begin(), sortedList.end());

	sortList resultList;
	for (const auto element : sortedList)
	{
		resultList.push_back(element.second);
	}

	return resultList;
}

sortList GetSortedByAreaList(const sortList & listShapes)
{
	std::vector<elementSortList> sortedList;
	for (const auto &shape : listShapes)
	{
		sortedList.push_back({ shape->GetArea(), shape });
	}

	std::sort(sortedList.begin(), sortedList.end());

	sortList resultList;
	for (const auto element : sortedList)
	{
		resultList.push_back(element.second);
	}

	return resultList;
}

/*
sortList GetSortedList(const std::vector<IShape*>& listShapes,
	std::function<float()> getMethod,
	std::function<bool(float, float)> conditionSorting)
{
	std::vector<std::pair<float, const IShape*>> sortedList;
	for (const auto &shape : listShapes)
	{
		sortedList.push_back({ getMethod(), shape });
	}

	std::sort(sortedList.begin(), sortedList.end(), conditionSorting);

	sortList resultList;
	for (const auto element : sortedList)
	{
		resultList.push_back(element.second);
	}

	return resultList;
}

*/
