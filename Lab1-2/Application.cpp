#include "stdafx.h"
#include "Application.h"

using namespace std;

template <typename T>
bool IsBetween(const T& value , const T& lowerBound , const T& upperBound)
{
	return (value >= lowerBound) && (value <= upperBound);
}

void CheckArguments(int argc, char *argv[])
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}

	std::string inputNotation = argv[1];
	for (auto digit : inputNotation)
	{
		if (!isdigit(digit))
		{
			throw invalid_argument(MESSAGE_INCORRECT_INPUT_NOTATION);
		}
	}

	std::string outputNotation = argv[2];
	for (auto digit : outputNotation)
	{
		if (!isdigit(digit))
		{
			throw invalid_argument(MESSAGE_INCORRECT_OUTPUT_NOTATION);
		}
	}
}

void CheckNotations(int inputNotaion, int outputNotation)
{
	if (!IsBetween(inputNotaion, MIN_NOTATION, MAX_NOTATION))
	{
		throw invalid_argument(MESSAGE_INCORRECT_RANGE_INPUT_NOTATION);
	}

	if (!IsBetween(outputNotation, MIN_NOTATION, MAX_NOTATION))
	{
		throw invalid_argument(MESSAGE_INCORRECT_RANGE_OUTPUT_NOTATION);
	}
}

void RemoveMathematicSymbol(std::string & number)
{
	if (IsFirstSymbolMathematic(number))
	{
		number = number.substr(1, number.size());
	}
}

bool isNegative(const string &number)
{
	if (number[0] == '-')
	{
		return true;
	}
	return false;
}

void CheckValue(const string &number, const int numberInputNotation)
{
	int valueSymbol;
	for (auto symbol : number)
	{
		valueSymbol = CharToInt(symbol);
		if ((valueSymbol > numberInputNotation) || (valueSymbol == ERROR_CODE))
		{
			throw invalid_argument(MESSAGE_INCORRECT_INPUT_NUMBER);
		}
	}
}

bool IsFirstSymbolMathematic(const string &input)
{
	if ((input[0] == '-') || (input[0] == '+'))
	{
		if (input.size() < 2)
		{
			throw invalid_argument(MESSAGE_INCORRECT_INPUT_NUMBER);
		}
		return true;
	}

	return false;
}

int CharToInt(char character)
{
	if (IsBetween(character , 'A' , 'Z'))
	{
		return static_cast<int>(character - 'A' + 10);
	}
	else if (IsBetween(character , 'a' , 'z'))
	{
		return static_cast<int>(character - 'a' + 10);
	}
	else if (IsBetween(character , '0' , '9'))
	{
		return static_cast<int>(character - '0');
	}

	return ERROR_CODE;
}

void CheckNumericLimitForAddition(int source , int summand)
{
	if ((source > (source + summand)))
	{
		throw overflow_error(MESSAGE_OVERFLOW);
	}
	else if ((source < (source + summand)))
	{
		throw underflow_error(MESSAGE_UNDERFLOW);
	}
}

void CheckNumericLimitForMultiplication(int source , int multiplier)
{
	if ((std::numeric_limits<int>::max() / multiplier) < source)
	{
		throw overflow_error(MESSAGE_OVERFLOW);
	}
	else if ((std::numeric_limits<int>::min() / multiplier) > source)
	{
		throw underflow_error(MESSAGE_UNDERFLOW);
	}
}

int AddAndOverflowCheck(int source, int summand, bool isNegative)
{
	if (isNegative)
	{
		summand *= -1;
	}

	if ((summand > 0) && (source > (std::numeric_limits<int>::max() - summand)))
	{
		throw overflow_error(MESSAGE_OVERFLOW);
	}
	if ((summand < 0) && (source < (std::numeric_limits<int>::min() - summand)))
	{
		throw underflow_error(MESSAGE_UNDERFLOW);
	}

	if (isNegative)
	{
		summand *= -1;
	}

	return source + summand;
}

int MultiplicationAndOverflowCheck(int source, int summand, bool isNegative)
{
	if (source != 0)
	{
		if (isNegative)
		{
			summand *= -1;
		}

		if ((summand > 0) && (summand > (std::numeric_limits<int>::max() / source)))// TODo
		{
			throw overflow_error(MESSAGE_OVERFLOW);
		}
		if ((summand < 0) && (summand < (std::numeric_limits<int>::min() / source)))
		{
			throw underflow_error(MESSAGE_UNDERFLOW);
		}

		if (isNegative)
		{
			summand *= -1;
		}
	}

	return source * summand;
}

int TranslateStringToNumber(std::string input, const int &numberNotation)
{
	bool isSigned = isNegative(input);
	RemoveMathematicSymbol(input);
	CheckValue(input, numberNotation);

	int multiplier = 0;
	int degree = 0;
	int result = 0;
	int summand = 0;

	for (auto digit : input)
	{
		multiplier = CharToInt(digit);

		summand = MultiplicationAndOverflowCheck(static_cast<int>(pow(numberNotation, degree)), multiplier, isSigned);

		result = AddAndOverflowCheck(result, summand, isSigned);

		degree++;
	}

	if (isSigned)
	{
		result *= -1;
	}

	return result;
}

std::string TranslateIntToString(int result , int numberOutputNotation)
{
	std::string outputNumber;

	int divider = numberOutputNotation;
	int remain = 0;
	if (result != 0)
	{
		bool isSigned = result < 0;

		unsigned int absoluteValue = abs(result);
		while (absoluteValue > 0)
		{
			remain = absoluteValue % numberOutputNotation;

			absoluteValue /= numberOutputNotation;

			if (IsBetween(remain , 0 , 9))
			{
				outputNumber.insert(outputNumber.begin() , int('0') + remain);
			}
			else if (IsBetween(remain , 10 , MAX_NOTATION))
			{
				outputNumber.insert(outputNumber.begin() , int('A') + remain - 10);
			}

		}

		if (isSigned)
		{
			outputNumber.insert(outputNumber.begin() , '-');
		}

	}
	else
	{
		outputNumber = '0';
	}

	return outputNumber;
}