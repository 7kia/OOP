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
<<<<<<< master
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
=======
	std::cout << boost::timer::format(timer.elapsed(), ROUNDING_NUMBER, "%u") << std::endl;
>>>>>>> local
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
<<<<<<< master
	bool isFindedSearchedString = false;
	while (index < lengthStringFromFile)
=======
	size_t foundIndex = 0;
	while ((index < lengthStringFromFile) && (foundIndex != string::npos))
>>>>>>> local
	{
		isFindedSearchedString = false;

		if ((index + lengthSearchString - 1) < lengthStringFromFile)
		{
<<<<<<< master
			isFindedSearchedString = SearchEqualSymbols(index , stringFromFile , searchString);
=======
			m_outputFile << stringFromFile.substr(index, foundIndex - index);
>>>>>>> local

			if (isFindedSearchedString)
			{
<<<<<<< master
				outputFile << replaceString;
				index += lengthSearchString;
=======
				m_outputFile << stringFromFile[foundIndex];
				index = foundIndex + 1;
>>>>>>> local
			}
		}

		if (!isFindedSearchedString)
		{
<<<<<<< master
			outputFile << stringFromFile[index];
			index++;
=======
			m_outputFile << stringFromFile.substr(index, lengthStringFromFile);
>>>>>>> local
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
<<<<<<< master
	}
	cout << MESSAGE_INCORRECT_AMOUNT_ARGUMENTS << AMOUNT_ARGUMENTS << endl;

	return false;
=======
	}	
	throw MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS);	
>>>>>>> local
}

bool CApplication::OpenFiles()
{
<<<<<<< master
	inputFile.open(nameInputFile);
	if (!CheckFileForReading(inputFile))
	{
		return false;
	}

	outputFile.open(nameOutputFile);
	if (!CheckFileForWriting(outputFile))
	{
		return false;
=======
	m_inputFile.open(nameInputFile);
	if (!m_inputFile.is_open())
	{
		throw MESSAGE_FAILED_OPEN + nameInputFile + MESSAGE_FAILED_OPEN_FOR_READING;		
>>>>>>> local
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
<<<<<<< master
		cout << nameInputFile << MESSAGE_VERY_BIG_FILE << endl;
		return false;
=======
		throw MESSAGE_FAILED_OPEN + nameOutputFile + MESSAGE_FAILED_OPEN_FOR_WRITING;	
>>>>>>> local
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