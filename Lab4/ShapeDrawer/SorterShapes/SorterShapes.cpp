#include "stdafx.h"
#include "SorterShapes.h"

void CSorterShapes::PrintListShapes(std::vector<IShape*>& listShapes, std::ostringstream &strm)
{
	for (const auto& shape : listShapes)
	{
		strm << shape->GetStringPresentation();
	}
}

CSorterShapes::sortList CSorterShapes::GetSortedByPerimeterList(const std::vector<std::shared_ptr<IShape>>& listShapes)
{
	std::vector<elementSortList> sortedList;
	for (const auto &shape : listShapes)
	{
		sortedList.push_back({ shape->GetPerimeter(), shape });
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
CSorterShapes::sortList CSorterShapes::GetSortedList(const std::vector<IShape*>& listShapes,
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
