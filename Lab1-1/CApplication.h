#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <time.h> // for clock()
#include <sys/stat.h>// for search file size

class CApplication
{
public:
	CApplication(int argc , char *argv[]);
	~CApplication();

	bool Run();

private:
	const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
	const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";
	const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " for writing!";
	const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";
	const std::string MESSAGE_VERY_BIG_FILE = " have length more two gigabytes!";

	const int AMOUNT_ARGUMENTS = 5;
	const int BYTE_IN_KILOBYTE = 1024;
	const int BYTE_IN_MEGABYTE = BYTE_IN_KILOBYTE * 1024;
	const int BYTE_IN_GIGABYTE = BYTE_IN_MEGABYTE * 1024;
	const int MAX_FILE_SIZE = 2 * BYTE_IN_GIGABYTE;

	bool isCorrectInputDate = false;

	std::string nameInputFile;
	std::string nameOutputFile;

	std::string searchString;
	std::string replaceString;

	std::ifstream inputFile;
	std::ofstream outputFile;

	size_t startTime;
	size_t endTime;

private:
	bool CheckParametrs(int argc , char *argv[]);

	bool OpenFiles();
	bool CheckFileSize(std::ifstream & inputFile);
	bool CheckFileForReading(std::ifstream &file);
	bool CheckFileForWriting(std::ofstream &file);

	void SearchString();
	void ProcessStringFromFile(const std::string &stringFromFile);
	bool SearchEqualSymbols(size_t position, const std::string & currentString, const std::string & searchString);
};

#endif
