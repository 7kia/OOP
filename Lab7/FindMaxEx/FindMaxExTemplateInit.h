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

	auto max = array.begin();
	for (auto it = max + 1; it != array.end(); ++it)
	{
		if (less(*max, *it))
		{
			max = it;
		}
	}

	maxValue = *max;
	return true;
}

