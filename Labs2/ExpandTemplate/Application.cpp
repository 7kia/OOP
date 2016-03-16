#include "stdafx.h"
#include "Application.h"

using namespace std;

void RunProgram(int argc, char * argv[])
{
	CheckParametrs(argc);
	
	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	CheckFiles(inputFile, outputFile);

	templates templates;
	for (size_t index = MIN_AMOUNT_ARGUMENTS - 2; index < argc; index += 2)
	{
		templates.emplace(pair<string, string>(argv[index], argv[index + 1]));
	}

	ExpandTemplatesForFile(inputFile, templates, outputFile);
}

void CheckParametrs(int argc)
{
	if ((argc < MIN_AMOUNT_ARGUMENTS) || (argc % 2 != 1))
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(MIN_AMOUNT_ARGUMENTS)
								+ "\n" + MESSAGE_ODD_AMOUNT_ARGUMENTS);
	}
}


void CheckFiles(ifstream &inputFile, ofstream &outputFile)
{
	inputFile.exceptions(ifstream::failbit | ifstream::badbit);
	if (!inputFile.is_open())
	{
		throw ifstream::failure(MESSAGE_FAILED_OPEN + MESSAGE_FAILED_OPEN_FOR_READING);
	}

	outputFile.exceptions(ifstream::failbit | ifstream::badbit);
	if (!outputFile.is_open())
	{
		throw ifstream::failure(MESSAGE_FAILED_OPEN + MESSAGE_FAILED_OPEN_FOR_WRITING);
	}

}

void ExpandTemplatesForFile(ifstream &inputFile, const templates &templates,
							ofstream &outputFile)
{
	string stringFromFile;
	string outputString;

	while (getline(inputFile, stringFromFile))
	{
		if (stringFromFile.size() != 0)
		{
			outputString = ExpandTemplateForString(stringFromFile, templates);
		}

		if (inputFile.peek() != EOF)
		{
			outputString += "\n";
		}
		outputFile << outputString;
		outputString.clear();
	}
}
