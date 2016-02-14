#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <time.h> // for clock()
#include <cctype>

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
	const std::string MESSAGE_INCORRECT_INTPUT_NUMBER = "Use incorrect number notation or incorrect retranslate number!!!";

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

#endif
