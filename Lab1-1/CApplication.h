#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <iomanip>// for setprecision

#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>
#include <boost/algorithm/string.hpp>

class CApplication
{
public:
	CApplication(int argc , char *argv[]);
	~CApplication();

	void SearchString();

private:
	const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
	const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";
	const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " for writing!";
	const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";
	const std::string MESSAGE_VERY_BIG_FILE = " have length more two gigabytes!";

	const int AMOUNT_ARGUMENTS = 5;
	const int ROUNDING_NUMBER = 5;

	std::string m_searchString;
	std::string m_replaceString;

	std::ifstream m_inputFile;
	std::ofstream m_outputFile;

	boost::timer::cpu_timer timer;
private:
	bool CheckParametrs(int argc , char *argv[]);

	bool OpenFiles(const std::string & nameInputFile , const std::string & nameOutputFile);

	void ProcessStringFromFile(const std::string &stringFromFile);
};

bool CheckParametrs(int argc, char *argv[]);

bool OpenFiles(const std::string & nameInputFile, const std::string & nameOutputFile);

void ProcessStringFromFile(const std::string &stringFromFile);

#endif
