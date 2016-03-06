#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>

#include "Dictionary.h"

static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";
static const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";
static const std::string MESSAGE_INCORRECT_DATA = "File consist excess data!";

static const int AMOUNT_ARGUMENTS = 2;
static const std::string STRING_DIVIDER = ">>";
void RunProgram(int argc, char * argv[]);
void CheckParametrs(int argc);

dictionary CreateDictionary(const std::string &nameFile);
void WriteInDictionary(dictionary &dictionary, std::ifstream file);
std::pair<std::string, std::string> ExtractElement(const std::string& inputString);