#pragma once

#include "ProcessRectangles.h"

class CRunner : public CProcessRectangles
{
public:
	CRunner(const listArguments &namesFiles);
	~CRunner();

	void Run();

private:
	const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
	const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";
	const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " for writing!";
	const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";

	const int AMOUNT_ARGUMENTS = 4;

private:
	std::string m_nameFirstCommandFile;
	std::string m_nameSecondCommandFile;
	std::string m_nameOutputFile;
	std::string m_nameInserectFile;

	std::ifstream m_firstCommandFile;
	std::ifstream m_secondCommandFile;
	std::ofstream m_outputFile;
	std::ofstream m_inserectFile;
private:
	void CheckAmountArguments(const listArguments &arguments);

	void OpenFiles();
	void CheckAndOpenFileForReading(std::ifstream & file, const std::string& fileName);
	void CheckAndOpenFileForWriting(std::ofstream & file, const std::string& fileName);
};

