#include "stdafx.h"
#include "Application.h"

using namespace std;

void RunProgram(int argc, char * argv[])
{
	CheckParametrs(argc);
	
	dictionary dictionary = CreateDictionary(argv[1]);
// TODO : 
}

void CheckParametrs(int argc)
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}
}

dictionary CreateDictionary(const string & nameFile)
{
	ifstream inputFile;
	inputFile.exceptions(ifstream::badbit);
	inputFile.open(nameFile);
	if (!inputFile.is_open())
	{
		throw ifstream::failure(MESSAGE_FAILED_OPEN + nameFile + MESSAGE_FAILED_OPEN_FOR_READING);
	}

	dictionary result;

	//
	string inputString;
	while (getline(inputFile, inputString))
	{
		result.insert(ExtractElement(inputString));
	}
	//
	return result;
}

// TODO : redesing
void WriteInDictionary(dictionary & dictionary, ifstream file)
{
	string inputString;
	while (getline(file, inputString))
	{

	}
}

pair<string, string> ExtractElement(const string& inputString)
{
	size_t indexFound = inputString.find(STRING_DIVIDER);

	string first = inputString.substr(0, indexFound);
	string second = inputString.substr(indexFound + 2);

	return pair<string, string>(first, second);
}
