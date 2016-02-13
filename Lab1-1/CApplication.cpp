#include "CApplication.h"

using namespace std;

CApplication::CApplication(int argc , char * argv[])
{
	startTime = clock();

	if (CheckParametrs(argc , argv))
	{
		nameInputFile = argv[1];
		nameOutputFile = argv[2];

		searchString = argv[3];
		replaceString = argv[4];

		isCorrectInputDate = true;
	}
	else
	{
		isCorrectInputDate = false;
	}
}

CApplication::~CApplication()
{
	endTime = clock();

	std::cout << "Time " << static_cast<float>(endTime - startTime) / 1000.f << " second" << std::endl;
}

bool CApplication::Run()
{
	if (isCorrectInputDate)
	{
		if (OpenFiles())
		{
			SearchString();

			return true;
		}
	}

	return false;
}

void CApplication::SearchString()
{
	string stringFromFile;
	size_t lengthStringFromFile;

	size_t index;
	bool isFindedSearchedString;
	while (!inputFile.eof())
	{
		getline(inputFile, stringFromFile);
		stringFromFile += '\n';

		ProcessStringFromFile(stringFromFile);
	}
}

void CApplication::ProcessStringFromFile(const string &stringFromFile)
{
	size_t lengthSearchString = searchString.size();
	size_t lengthStringFromFile = stringFromFile.size();

	size_t index = 0;
	bool isFindedSearchedString = false;
	while (index < lengthStringFromFile)
	{
		isFindedSearchedString = false;

		if ((index + lengthSearchString - 1) < lengthStringFromFile)
		{
			isFindedSearchedString = SearchEqualSymbols(index , stringFromFile , searchString);

			if (isFindedSearchedString)
			{
				outputFile << replaceString;
				index += lengthSearchString;
			}
		}

		if (!isFindedSearchedString)
		{
			outputFile << stringFromFile[index];
			index++;
		}

	}

}

bool CApplication::SearchEqualSymbols(size_t position, const string &currentString, const string &searchString)
{
	size_t lengthSearchString = searchString.size();

	size_t leftCounter = position;
	size_t rightCounter = position + lengthSearchString - 1;
	size_t idCheckSymbol = 0;

	bool leftIsEqual = false;
	bool rightIsEqual = false;
	while (leftCounter <= rightCounter)
	{
		leftIsEqual = (currentString[leftCounter] == searchString[idCheckSymbol]);
		rightIsEqual = (currentString[rightCounter] == searchString[lengthSearchString - idCheckSymbol - 1]);

		if (leftIsEqual && rightIsEqual)
		{
			leftCounter++;
			rightCounter--;
			idCheckSymbol++;
			continue;
		}
		break;
	}

	return leftIsEqual && rightIsEqual;
}

bool CApplication::CheckParametrs(int argc , char *argv[])
{
	if (argc == AMOUNT_ARGUMENTS)
	{
		return true;
	}
	cout << MESSAGE_INCORRECT_AMOUNT_ARGUMENTS << AMOUNT_ARGUMENTS << endl;

	return false;
}

bool CApplication::OpenFiles()
{
	inputFile.open(nameInputFile);
	if (!CheckFileForReading(inputFile))
	{
		return false;
	}

	outputFile.open(nameOutputFile);
	if (!CheckFileForWriting(outputFile))
	{
		return false;
	}

	return true;
}

bool CApplication::CheckFileSize(ifstream & inputFile)
{
	inputFile.seekg(0 , std::ios::end);
	size_t size = static_cast<size_t>(inputFile.tellg());
	inputFile.seekg(0 , std::ios::beg);
	return size <= MAX_FILE_SIZE;
}

bool CApplication::CheckFileForReading(ifstream & file)
{
	if (!file.is_open())
	{
		cout << MESSAGE_FAILED_OPEN << nameInputFile << MESSAGE_FAILED_OPEN_FOR_READING << endl;
		return false;
	}
	if (!CheckFileSize(file))
	{
		cout << nameInputFile << MESSAGE_VERY_BIG_FILE << endl;
		return false;
	}

	return true;
}

bool CApplication::CheckFileForWriting(ofstream & file)
{
	if (!file.is_open())
	{
		cout << MESSAGE_FAILED_OPEN << nameInputFile << MESSAGE_FAILED_OPEN_FOR_WRITING << endl;
		return false;
	}

	return true;
}