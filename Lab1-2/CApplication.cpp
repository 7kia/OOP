#include "stdafx.h"
#include "CApplication.h"

using namespace std;


template <typename T>
bool IsBetween(const T& value , const T& lowerBound , const T& upperBound)
{
	return (value >= lowerBound) && (value <= upperBound);
}

void CheckParametrs(int argc, char *argv[])
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		if()
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}
}

void CheckNotations(char* inputNotaion, char* outputNotation)
{
	if (!isalnum(*inputNotaion))
	{
		throw invalid_argument(MESSAGE_INCORRECT_INPUT_NOTATION);
	}

	if (!isalnum(*outputNotation))
	{
		throw invalid_argument(MESSAGE_INCORRECT_OUTPUT_NOTATION);
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
	if ((input[0] == '-') && (input[0] == '+'))
	{
		if (input.size() < 2)
		{
			throw invalid_argument(MESSAGE_INCORRECT_INPUT_NUMBER);
		}
		return true;
	}

	return false;
}

bool CApplication::Run()
{
	if (isCorrectInputDate)
	{	
		try
		{
			int valueInputNumber = TranslateStringToNumber(inputNumber , numberInputNotation);
			std::string outputNumber = TranslateIntToString(valueInputNumber , numberOutputNotation);

			std::cout << MESSAGE_RESULT << outputNumber << std::endl;
			std::cout << MESSAGE_DECIMAL_NOTATION << valueInputNumber << std::endl;
		}
		catch (underflow_error const& err)
		{
			cout << err.what() << endl;
		}
		catch (overflow_error const& err)
		{
			cout << err.what() << endl;
		}

		return true;
	}

	return false;
}

bool CApplication::CheckParametrs(int argc , char *argv[])
{
	if (argc == AMOUNT_ARGUMENTS)
	{
		if (!CheckNotation(argv[1], argv[2]))
		{
			return false;
		}
		
		numberInputNotation = atoi(argv[1]);
		numberOutputNotation = atoi(argv[2]);
		inputNumber = argv[3];
		if (!checkInputNumber())
		{
			std::cout << MESSAGE_INCORRECT_INTPUT_NUMBER << std::endl;
			return false;
		}

		return true;
	}
	cout << MESSAGE_INCORRECT_AMOUNT_ARGUMENTS << AMOUNT_ARGUMENTS << endl;

	return false;
}

// TODO : delete
int CApplication::DefineStartValue(int defaultValue , int alternateValue , bool condition)
{
	if (condition)
	{
		return alternateValue;
	}
	return defaultValue;
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

bool CApplication::CheckAbsoluteValue(const std::string &input)
{
	for (auto symbol : input)
	{
		if (!isalnum(symbol))
		{
			return false;
		}
	}

	return true;
}

bool CApplication::CheckInputNumber()
{
	size_t lengthNumber = inputNumber.size();

	if (lengthNumber == 0)
	{
		return false;
	}

	if (IsFirstSymbolMathematic(inputNumber))
	{
		inputNumber = inputNumber.substr(1 , lengthNumber - 1);
		lengthNumber--;
	}

	if (!CheckAbsoluteValue(inputNumber))
	{
		return false;
	}

	unsigned int valueSymbol;
	for (auto symbol : inputNumber)
	{
		valueSymbol = CharToInt(symbol);
		if ((valueSymbol > numberInputNotation) || (valueSymbol == ERROR_CODE))
		{
			return false;
		}
	}

	return true;
}

bool CApplication::CheckNumericLimitForAddition(int source , int summand)
{


	if ((source > (source + summand)))
	{
		throw overflow_error(MESSAGE_OVERFLOW);
		return false;
	}
	else if ((source < (source + summand)))
	{
		throw underflow_error(MESSAGE_UNDERFLOW);
		return false;
	}

	return true;
}

bool CApplication::CheckNumericLimitForMultiplication(int source , int multiplier)
{
	if ((std::numeric_limits<int>::max() / multiplier) < source)
	{
		throw overflow_error(MESSAGE_OVERFLOW);
		return false;
	}
	else if ((std::numeric_limits<int>::min() / multiplier) > source)
	{
		throw underflow_error(MESSAGE_UNDERFLOW);
		return false;
	}

	return true;
}

// TODO : delete const if not need
int TranslateStringToNumber(const std::string &input, const int &numberNotation)
{
	int multiplier = 0;
	int degree = 0;
	int result = 0;
	int summand = 0;

	///////////////////////////////////////////////////////////////////////////
	// There use int instead size_t because, condition break loop is index > 0
	int endValue = 0;
	int startValue = static_cast<int>(input.size()) - 1;

	for (auto digit : input)
	{
		multiplier = CharToInt(digit);

		if (!CheckNumericLimitForMultiplication(static_cast<int>(pow(numberNotation , degree - 1)) , numberNotation))
		{
			break;
		}
		summand = multiplier * static_cast<int>(pow(numberNotation , degree));

		if (!CheckNumericLimitForAddition(result , summand))
		{
			break;
		}
		result += summand;

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
	int remain = 1;
	if (result != 0)
	{
		isSigned = result < 0;

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