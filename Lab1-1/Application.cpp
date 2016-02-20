#include "stdafx.h"
#include "Application.h"

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

bool CheckFiles(ifstream &inputFile, ofstream &outputFile)
{
	if (!inputFile.is_open())
	{
		cout <<  MESSAGE_FAILED_OPEN_FOR_READING << endl;
		return false;
	}

	if (!outputFile.is_open())
	{
		cout << MESSAGE_FAILED_OPEN_FOR_WRITING << endl;
		return false;
	}

	return true;
}

bool RunProgram(int argc , char * argv[])
{
	if (CheckParametrs(argc , argv))
	{
		ifstream inputFile(argv[1]);
		ofstream outputFile(argv[2]);

		if (CheckFiles(inputFile, outputFile))
		{
			string searchString = argv[3];
			string replaceString = argv[4];

			ReplaceSubstringInFile(inputFile, outputFile, searchString, replaceString);
			return true;
		}
	}
	return false;
}

void ReplaceSubstringInFile(ifstream &inputFile, ofstream &outputFile, const string &searchString, const string &replaceString)
{
	string stringFromFile;

	while (getline(inputFile, stringFromFile))
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
