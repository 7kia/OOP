#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <time.h> // for clock()

#include "MatrixOperations.h"

class CApplication
{
public:
	CApplication(int argc , char *argv[]);
	~CApplication();

	bool Run();

private:
	const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";
	const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
	const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";

	const std::string MESSAGE_ZERO_DETERMINATE = "Determinate the matrix = 0!";

	const int ERROR_CODE = -1;
	const int AMOUNT_ARGUMENTS = 2;
	const int SIZE_MATRIX = 3;

	bool isCorrectInputDate = false;

	std::string nameInputFile;

	size_t startTime;
	size_t endTime;

private:
	bool CheckParametrs(int argc , char *argv[]);

	bool FillMatrixFromFile(std::string nameFile , Matrix & matrix);

	bool CheckFileForReading(std::ifstream & file);
};

#endif
