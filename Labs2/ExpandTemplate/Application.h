#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>

#include "ExpandTemplate.h"

static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Minimum must will be ";
static const std::string MESSAGE_ODD_AMOUNT_ARGUMENTS = "Amount arguments will be even.";

static const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";
static const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " for writing!";
static const std::string MESSAGE_INCORRECT_DATA = "File consist excess data!";

static const int ERROR_CODE = -1;
static const int MIN_AMOUNT_ARGUMENTS = 5;
static const int SIZE_MATRIX = 3;

void RunProgram(int argc, char * argv[]);
void CheckParametrs(int argc);
void CheckFiles(std::ifstream &inputFile, std::ofstream &outputFile);

void ExpandTemplatesForFile(std::ifstream &inputFile, const templates &templates,
							std::ofstream &outputFile);
