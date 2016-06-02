#include "stdafx.h"
#include "FindMaxEx.h"


bool FindMax(const std::vector<const char *> & array
			, char &maxValue
			, std::function<bool(const char, const char)> const& less)
{
	if (array.empty())
	{
		return false;
	}

	char max = '\0';
	for (const auto & arrayElement : array)
	{
		size_t sizeString = strlen(arrayElement);
		for (size_t index = 0; index < sizeString; index++)
		{
			if (less(max, arrayElement[index]))
			{
				max = arrayElement[index];
			}
		}
	}

	maxValue = max;
	return true;
}