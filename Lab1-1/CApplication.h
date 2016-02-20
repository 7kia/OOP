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

static const int AMOUNT_ARGUMENTS = 5;
static const int ROUNDING_NUMBER = 5;

static const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";
static const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " for writing!";
static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";
static const std::string MESSAGE_VERY_BIG_FILE = " have length more two gigabytes!";

bool CheckParametrs(int argc, char *argv[]);
bool OpenFiles(const std::string &nameInputFile, const std::string &nameOutputFile,
	std::ifstream &inputFile, std::fstream &outputFile);
void SearchString(std::ifstream &inputFile, std::fstream &outputFile,
					const std::string &searchString, const std::string &replaceString);
bool ReplaceSubstringInFile(int argc, char * argv[]);


void ProcessStringFromFile(const std::string &stringFromFile, const std::string &searchString,
							const std::string &replaceString);
#endif
