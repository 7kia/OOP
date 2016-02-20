#include "stdafx.h"
#include "CApplication.h"

using namespace std;

void InitializeProgram(int argc , char * argv[])
{
	if (CheckParametrs(argc , argv))
	{
		if (OpenFiles(argv[1] , argv[2]))
		{
			m_searchString = argv[3];
			m_replaceString = argv[4];
		}
	}
}

CApplication::~CApplication()
{
	std::cout << boost::timer::format(timer.elapsed(), ROUNDING_NUMBER, "%u") << std::endl;
}

void CApplication::SearchString()
{
	string stringFromFile;

	timer.start();

	while (getline(m_inputFile , stringFromFile, m_inputFile.widen('\n')))
	{
		//stringFromFile += '\n';

		//ProcessStringFromFile(stringFromFile);

		/*
				if (stringFromFile.size() != 0)
		{
			boost::replace_all(stringFromFile, m_searchString, m_replaceString);
		}

		if (m_inputFile.peek() != EOF)
		{
			stringFromFile += "\n";
		}
		m_outputFile << stringFromFile;

		*/
	}

	timer.stop();
}
///*
void CApplication::ProcessStringFromFile(const string &stringFromFile)
{
	size_t searchStringLength = m_searchString.size();
	size_t lengthStringFromFile = stringFromFile.size();
	size_t index = 0;
	size_t foundIndex = 0;

	string outputString;
	while ((index < lengthStringFromFile) && (foundIndex != string::npos))
	{
		foundIndex = stringFromFile.find(m_searchString[0], index);

		if (foundIndex != string::npos)
		{
			outputString.append(stringFromFile.begin() + index, stringFromFile.begin() + foundIndex - index);

			if (stringFromFile.substr(foundIndex, searchStringLength) == m_searchString)
			{
				outputString.append(m_replaceString);
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

bool CApplication::CheckParametrs(int argc , char *argv[])
{
	if (argc == AMOUNT_ARGUMENTS)
	{
		return true;
	}	
	throw MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS);	
}

bool CApplication::OpenFiles(const string &nameInputFile, const string &nameOutputFile)
{
	m_inputFile.open(nameInputFile);
	if (!m_inputFile.is_open())
	{
		throw MESSAGE_FAILED_OPEN + nameInputFile + MESSAGE_FAILED_OPEN_FOR_READING;		
	}

	m_outputFile.open(nameOutputFile);
	if (!m_outputFile.is_open())
	{
		throw MESSAGE_FAILED_OPEN + nameOutputFile + MESSAGE_FAILED_OPEN_FOR_WRITING;	
	}

	return true;
}
