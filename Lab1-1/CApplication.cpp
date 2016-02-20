#include "stdafx.h"
#include "CApplication.h"

using namespace std;


bool CheckParametrs(int argc, char *argv[])
{
	if (argc == AMOUNT_ARGUMENTS)
	{
		return true;
	}
	cout << MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS) << endl;

	return false;
}

bool OpenFiles(const string &nameInputFile, const string &nameOutputFile,
	ifstream &inputFile, fstream &outputFile)
{
	inputFile.open(nameInputFile);
	if (!inputFile.is_open())
	{
		cout << MESSAGE_FAILED_OPEN + nameInputFile + MESSAGE_FAILED_OPEN_FOR_READING << endl;
		return false;
	}

	outputFile.open(nameOutputFile);
	if (!outputFile.is_open())
	{
		cout << MESSAGE_FAILED_OPEN + nameOutputFile + MESSAGE_FAILED_OPEN_FOR_WRITING << endl;
		return false;
	}

	return true;
}

bool ReplaceSubstringInFile(int argc , char * argv[])
{
	if (CheckParametrs(argc , argv))
	{
		ifstream inputFile;
		fstream outputFile;
		if (OpenFiles(argv[1] , argv[2], inputFile, outputFile))
		{
			string searchString = argv[3];
			string replaceString = argv[4];

			SearchString(inputFile, outputFile, searchString, replaceString);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void SearchString(ifstream &inputFile, fstream &outputFile, const string &searchString, const string &replaceString)
{
	string stringFromFile;

	while (getline(inputFile, stringFromFile, inputFile.widen('\n')))
	{
		if (stringFromFile.size() != 0)
		{
			boost::replace_all(stringFromFile, searchString, replaceString);
		}

		if (inputFile.peek() != EOF)
		{
			stringFromFile += "\n";
		}
		outputFile << stringFromFile;

	}

}
/*
void ProcessStringFromFile(const string &stringFromFile, const string &searchString, const string &replaceString)
{
	size_t searchStringLength = searchString.size();
	size_t lengthStringFromFile = stringFromFile.size();
	size_t index = 0;
	size_t foundIndex = 0;

	string outputString;
	while ((index < lengthStringFromFile) && (foundIndex != string::npos))
	{
		foundIndex = stringFromFile.find(searchString[0], index);

		if (foundIndex != string::npos)
		{
			outputString.append(stringFromFile.begin() + index, stringFromFile.begin() + foundIndex - index);

			if (stringFromFile.substr(foundIndex, searchStringLength) == searchString)
			{
				outputString.append(replaceString);
				index = foundIndex + searchStringLength;
			}
			else
			{
				outputString.append(stringFromFile[foundIndex]);
				index = foundIndex + 1;
			}
		}		
		else
		{
			outputString.append(stringFromFile.begin() + index, stringFromFile.end());
		}
	}

}

//*/