#pragma once

#include "FindMaxExDeclaration.h"

template <typename T, typename Less = std::less<T>>
bool FindMax(std::vector<T> const& array
			, T &maxValue
			, Less const& less = Less())
{
	if (array.empty())
	{
		return false;
	}

	T max = array.front();
	for (size_t index = 1; index < array.size(); index++)
	{
		if (less(max, array[index]))
		{
			max = array[index];
		}
	}

	maxValue = max;
	return true;
}

