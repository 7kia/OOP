#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

dictionary CreateDictionary(const wstring & nameFile)
{
	wifstream inputFile;
	inputFile.exceptions(wifstream::badbit);
	inputFile.open(nameFile);
	if (!inputFile.is_open())
	{
		wcout << MESSAGE_FAILED_OPEN + nameFile + MESSAGE_FAILED_OPEN_FOR_READING << endl;
		wcout << MESSAGE_EMPTY_DICTIONARY << endl;
	}

	dictionary result;
	wstring inputString;
	while (getline(inputFile, inputString))
	{
		result.insert(inputString);
	}

	return result;
}