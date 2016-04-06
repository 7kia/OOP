#include "stdafx.h"
#include "SorterShapes.h"

void PrintListShapes(const listDataShapes& listShapes, std::ostream &strm)
{
	for (const auto& shape : listShapes)
	{
		strm << shape->GetStringPresentation();
	}
}

listDataShapes GetSortedByDecreasePerimeterList(const listDataShapes& listShapes)
{
	std::vector<elementSortList> sortedList;
	for (const auto &shape : listShapes)
	{
		sortedList.push_back({ shape->GetPerimeter(), shape });
	}

	std::sort(sortedList.begin(), sortedList.end());
	std::reverse(sortedList.begin(), sortedList.end());

	listDataShapes resultList;
	for (const auto element : sortedList)
	{
		resultList.push_back(element.second);
	}

	return resultList;
}

listDataShapes GetSortedByAreaList(const listDataShapes & listShapes)
{
	std::vector<elementSortList> sortedList;
	for (const auto &shape : listShapes)
	{
		sortedList.push_back({ shape->GetArea(), shape });
	}

	std::sort(sortedList.begin(), sortedList.end());

	listDataShapes resultList;
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
