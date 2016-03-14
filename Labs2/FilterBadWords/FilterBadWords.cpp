#include "stdafx.h"
#include "FilterBadWords.h"

using namespace std;

template <typename T>
bool IsBetween(const T& value, const T& lowerBound, const T& upperBound)
{
	return (value >= lowerBound) && (value <= upperBound);
};

bool IsAlpha(char symbol)
{
	if (static_cast<int>(symbol) > 0)
	{
		return isalpha(symbol);
	}
	else 
	{
		return IsBetween(static_cast<int>(symbol), -64, -1);
	}
}

std::string FilterBadWords(std::string inputString, const dictionary &dictionary)
{
	string word;

	size_t indexStartWord = 0;
	size_t indexEndWord = 0;
	
	while (indexEndWord < inputString.size())
	{
		if (IsAlpha(inputString[indexEndWord]))
		{
			word += inputString[indexEndWord];
		}
		else
		{
			if (dictionary.find(word) != dictionary.end())
			{
				inputString.erase(indexEndWord - word.size(), word.size());
				indexEndWord -= word.size();
			}
			word.clear();
		}
		
		indexEndWord++;
	}

	if (dictionary.find(word) != dictionary.end())
	{
		inputString.erase(indexEndWord - word.size(), word.size());
		indexEndWord -= word.size();
	}

	return inputString;
}
