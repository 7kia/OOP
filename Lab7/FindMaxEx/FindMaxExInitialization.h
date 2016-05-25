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

/*
template <typename Less = std::less<char>>
bool FindMax<std::string>(std::vector<std::string> const& array
							, char &maxValue
							, Less const& less = Less())
{
	if (array.empty())
	{
		return false;
	}

	char max = '\0';
	for (const auto & arrayElement : array)
	{
		for (const auto & stringElement : arrayElement)
		{
			if (less(max, stringElement))
			{
				max = stringElement;
			}
		}
	}

	maxValue = max;
	return true;
}
*/
