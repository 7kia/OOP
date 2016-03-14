#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

dictionary CreateDictionary(const string & nameFile)
{
	ifstream inputFile;
	inputFile.exceptions(ifstream::badbit);
	inputFile.open(nameFile);
	if (!inputFile.is_open())
	{
		cout << MESSAGE_FAILED_OPEN + nameFile + MESSAGE_FAILED_OPEN_FOR_READING << endl;
		cout << MESSAGE_EMPTY_DICTIONARY << endl;
	}

	dictionary result;
	string inputString;
	while (getline(inputFile, inputString))
	{		
		result.emplace(inputString);
	}

	return result;
}