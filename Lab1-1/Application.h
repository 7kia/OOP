#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>

static const int AMOUNT_ARGUMENTS = 5;
static const int ROUNDING_NUMBER = 5;

static const std::string MESSAGE_FAILED_OPEN_FOR_READING = "Failed open input file for reading!";
static const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = "Failed open output file for writing!";
static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";
static const std::string MESSAGE_VERY_BIG_FILE = " have length more two gigabytes!";
static const std::string MESSAGE_ERROR_FOR_WRITING = "Failed writing to output file!";


bool CheckParametrs(int argc, char *argv[]);
bool CheckFiles(std::ifstream &inputFile, std::ofstream &outputFile);
void ReplaceSubstringInFile(std::ifstream &inputFile, std::ofstream &outputFile,
					const std::string &searchString, const std::string &replaceString);
bool RunProgram(int argc, char * argv[]);

#endif
