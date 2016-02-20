#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <time.h> // for clock()
#include <cctype>

#include <boost\timer\timer.hpp>

class CApplication
{
public:
	CApplication(int argc , char *argv[]);
	~CApplication();

	bool Run();

private:
	const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";
	const std::string MESSAGE_INCORRECT_INPUT_NOTATION = "Number input system notation is not number(or it is negative)!!!";
	const std::string MESSAGE_INCORRECT_OUTPUT_NOTATION = "Number output system notation is not number(or it is negative)!!!";
	const std::string MESSAGE_INCORRECT_INTPUT_NUMBER =  "Use incorrect number notation or incorrect retranslate number!!!";

	const std::string MESSAGE_OVERFLOW = "Overflow for int!";
	const std::string MESSAGE_UNDERFLOW = "Underflow for int!";

	const std::string MESSAGE_RESULT = "Result = ";
	const std::string MESSAGE_DECIMAL_NOTATION = "In decimal notation = ";


	const int ERROR_CODE = -1;
	const int AMOUNT_ARGUMENTS = 4;

	const int MIN_NOTATION = 1;
	const int MAX_NOTATION = static_cast<size_t>('z' - 'a' + 10);


	bool isCorrectInputDate = false;

	std::string inputNumber;

	unsigned int numberInputNotation;
	unsigned int numberOutputNotation;
	bool isSigned = false;
	bool startNotWithFirstSymbol = false;

	size_t startTime;
	size_t endTime;

private:
	bool CheckParametrs(int argc , char *argv[]);
	bool CheckNotation(char* inputNotaion, char* outputNotation);

	int DefineStartValue(int defaultValue , int alternateValue , bool condition);
	int CharToInt(char character);
	bool IsFirstSymbolMathematic(const std::string &input);
	bool CheckAbsoluteValue(const std::string & input);
	bool checkInputNumber();

	bool CheckNumericLimitForAddition(int source , int summand);
	bool CheckNumericLimitForMultiplication(int source , int multiplier);

	int TranslateStringToNumber(const std::string & input , const int & numberNotation);
	std::string TranslateIntToString(int result , int numberOutputNotation);
};


///////////

static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";
static const std::string MESSAGE_INCORRECT_INPUT_NOTATION = "Number input system notation is not number(or it is negative)!!!";
static const std::string MESSAGE_INCORRECT_OUTPUT_NOTATION = "Number output system notation is not number(or it is negative)!!!";
static const std::string MESSAGE_INCORRECT_INPUT_NUMBER = "Use incorrect number notation or incorrect input number!!!";

static const std::string MESSAGE_OVERFLOW = "Overflow for int!";
static const std::string MESSAGE_UNDERFLOW = "Underflow for int!";

static const std::string MESSAGE_RESULT = "Result = ";
static const std::string MESSAGE_DECIMAL_NOTATION = "In decimal notation = ";

static const int AMOUNT_ARGUMENTS = 4;
static const int ERROR_CODE = -1;

static const int SYMBOL_IS_PLUS = 0;
static const int SYMBOL_IS_MINUS = 1;
static const int SYMBOL_IS_NOT_MATHEMATIC = -1;

void CheckParametrs(int argc, char *argv[]);
void CheckNotations(char* inputNotaion, char* outputNotation);
void RemoveMathematicSymbol(std::string &number);
void CheckValue(const string &number, const int numberInputNotation);
bool isNegative(const std::string &number);
bool IsFirstSymbolMathematic(const std::string &input);
int CharToInt(char character);

#endif
