#include "stdafx.h"
#include "Runner.h"

using namespace std;

CRunner::CRunner(const listArguments &namesFiles)
{	
	CheckAmountArguments(namesFiles);

	m_nameFirstCommandFile = namesFiles[0];
	m_nameSecondCommandFile = namesFiles[1];
	m_nameOutputFile = namesFiles[2];
	m_nameInserectFile = namesFiles[3];
}

CRunner::~CRunner()
{
}

void CRunner::Run()
{
	OpenFiles();

	vector<CRectangle> rectangles = { CRectangle(), CRectangle() };
	ApplyCommandOnRectangle(rectangles[0], m_firstCommandFile);

	ApplyCommandOnRectangle(rectangles[1], m_secondCommandFile);

	rectangles.push_back(rectangles[0]);
	rectangles[2].Intersect(rectangles[1]);
	WriteResultTransformationsInFile(rectangles, m_outputFile);

	WriteResultIntersectionInFile(rectangles, m_inserectFile);

//	outputFile << secondMaxCost;
}

void CRunner::CheckAmountArguments(const listArguments &arguments)
{
	if (arguments.size() != AMOUNT_ARGUMENTS)
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}

}

void CRunner::OpenFiles()
{
	CheckAndOpenFileForReading(m_firstCommandFile, m_nameFirstCommandFile);
	CheckAndOpenFileForReading(m_secondCommandFile, m_nameSecondCommandFile);
	CheckAndOpenFileForWriting(m_outputFile, m_nameOutputFile);
	CheckAndOpenFileForWriting(m_inserectFile, m_nameInserectFile);

}

void CRunner::CheckAndOpenFileForReading(ifstream & file, const string& fileName)
{
	file.open(fileName);
	file.exceptions(ifstream::badbit);
	if (!file.is_open())
	{
		throw ifstream::failure(MESSAGE_FAILED_OPEN + fileName + MESSAGE_FAILED_OPEN_FOR_READING);
	}
}

void CRunner::CheckAndOpenFileForWriting(ofstream & file, const string& fileName)
{
	file.open(fileName);
	file.exceptions(ofstream::badbit);
	if (!file.is_open())
	{
		throw ofstream::failure(MESSAGE_FAILED_OPEN + fileName + MESSAGE_FAILED_OPEN_FOR_WRITING);
	}
}
