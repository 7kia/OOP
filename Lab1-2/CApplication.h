#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <time.h> // for clock()
#include <cctype>

#include <boost\timer\timer.hpp>

static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";
static const std::string MESSAGE_INCORRECT_INPUT_NOTATION = "Number input system notation is not number(or it is negative)!!!";
static const std::string MESSAGE_INCORRECT_OUTPUT_NOTATION = "Number output system notation is not number(or it is negative)!!!";
static const std::string MESSAGE_INCORRECT_RANGE_INPUT_NOTATION = "Number input system notation not belong range [2, 35]!!!";
static const std::string MESSAGE_INCORRECT_RANGE_OUTPUT_NOTATION = "Number output system notation not belong range [2, 35]!!!";
static const std::string MESSAGE_INCORRECT_INPUT_NUMBER = "Use incorrect number notation or incorrect input number!!!";

static const std::string MESSAGE_OVERFLOW = "Overflow for int!";
static const std::string MESSAGE_UNDERFLOW = "Underflow for int!";

static const std::string MESSAGE_RESULT = "Result = ";
static const std::string MESSAGE_DECIMAL_NOTATION = "In decimal notation = ";

static const int AMOUNT_ARGUMENTS = 4;
static const int ERROR_CODE = -1;

static const int MIN_NOTATION = 1;
static const int MAX_NOTATION = static_cast<int>('z' - 'a' + 10);

void CheckParametrs(int argc, char *argv[]);
void CheckNotations(int inputNotaion, int outputNotation);
void CheckValue(const std::string &number, const int numberInputNotation);

void RemoveMathematicSymbol(std::string &number);
bool isNegative(const std::string &number);
bool IsFirstSymbolMathematic(const std::string &input);

int CharToInt(char character);

int TranslateStringToNumber(std::string input, const int &numberNotation);
std::string TranslateIntToString(int result, int numberOutputNotation);

int AddAndOverflowCheck(int source, int summand, bool isNegative);
int MultiplicationAndOverflowCheck(int source, int summand, bool isNegative);

#endif
