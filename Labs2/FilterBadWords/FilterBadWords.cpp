#include "stdafx.h"
#include "FilterBadWords.h"

using namespace std;

std::wstring FilterBadWords(std::wstring inputString, const dictionary &dictionary)
{
	wstring word;

	size_t indexStartWord = 0;
	size_t indexEndWord = 0;
	
	while (indexEndWord < inputString.size())
	{
		if (iswalpha(inputString[indexEndWord]))// TODO : work only for english words
		{
			word += inputString[indexEndWord];
		}
		else
		{
			if (std::find(dictionary.begin(), dictionary.end(), word) != dictionary.end())
			{
				inputString.erase(indexEndWord - word.size(), word.size());
				indexEndWord -= word.size();
			}
			word.clear();
		}
		
		indexEndWord++;
	}

	if (std::find(dictionary.begin(), dictionary.end(), word) != dictionary.end())
	{
		inputString.erase(indexEndWord - word.size(), word.size());
		indexEndWord -= word.size();
	}

	return inputString;
}
