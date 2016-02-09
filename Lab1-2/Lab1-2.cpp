// Lab1-2.cpp: определяет точку входа для консольного приложения.
//

/*
Лабораторная работа 1. 2 задание 7 вариант

Разработайте программу radix.exe, выполняющую перевод чисел из
одной произвольной системы счисления в другую произвольную и 
запись результата в стандартный поток вывода. Под произвольной
системой счисления понимается система с основанием от 2 до 36. 
Системы счисления с 11-ричной до 36-ричной должны использовать
заглавные буквы латинского алфавита от A до Z для представления
разрядов с 1110до 3510. Форматкоманднойстрокиприложения:

radix.exe <source notation><destination notation><value>

Например, следующим способом программа должна осуществлять
перевод шестнадцатеричного числа 1F в его десятичное представление:
radix.exe 16 10 1F

В конце строки, выводимой в стандартный поток выводадолжен 
располагаться код \n.

Программа должна быть способна осуществлять перевод как
положительных, так и отрицательных чисел, а также нуля. Особое 
внимание уделите переводу максимальных и минимальных целых 
чисел на данной платформе (они должны преобразовываться 
корректно).
*/
#include "stdafx.h"

static const int ERROR_CODE = -1;

template<typename T>
bool IsInDiaposon(T number , T start , T end)
{
	if ((number >= start) && (number <= end))
		return true;
	return false;
}

int CharToInt(char symbol)
{
	if (IsInDiaposon(symbol , '0' , '9'))
	{
		return symbol - int('0');
	}
	else if (IsInDiaposon(symbol , 'a' , 'z'))
	{
		return 10 + (symbol - int('a'));
	}
	else if (IsInDiaposon(symbol , 'A' , 'Z'))
	{
		return 10 + (symbol - int('A'));
	}

	return ERROR_CODE;
}

int DefineStartValue(int defaultValue, int alternateValue, bool condition)
{
	if (condition)
	{
		return alternateValue;
	}
	return defaultValue;
}

bool checkInputNumber(char* number , int numberInputNotation)
{
	int valueSymbol;
	for (int i = DefineStartValue(0, 1, number[0] == '-'); i < strlen(number); i++)
	{
		valueSymbol = CharToInt(number[i]);
		if ((valueSymbol > numberInputNotation) || (valueSymbol == ERROR_CODE))
		{
			return false;
		}
	}
	return true;
}

bool checkParametrs(int argc , char *argv[])
{
	if (argc == 4)
	{
		bool isError = false;

		if (!isdigit(*argv[1]))
		{
			std::cout << "Number input system notation is not number!!!" << argc << std::endl;
			isError = true;
		}
		if (!isdigit(*argv[2]))
		{
			std::cout << "Number output system notation is not number!!!" << argc << std::endl;
			isError = true;
		}

		if (!checkInputNumber(argv[3] , atoi(argv[1])))
		{
			std::cout << "Use incorrect number notation or incorrect retranslate number!!!" << argc << std::endl;
			isError = true;
		}

		return !isError;
	}
	std::cout << "Not enough amount parametrs!!! " << argc << std::endl;

	return false;
}

int TranslateStringToNumber(std::string str , int numberNotation)
{
	int multiplier = 0;
	int degree = 0;
	int result = 0;

	bool isSigned = (str[0] == '-');
	int endValue = DefineStartValue(0 , 1 , str[0] == '-');
	for (int i = int(str.size()) - 1; i >= endValue; i--)
	{
		multiplier = CharToInt(str[i]);

		result += multiplier * int(pow(numberNotation , degree));
		degree++;
	}

	if (isSigned)
	{
		result *= -1;
	}

	return result;
}

std::string TranslateIntToString(int result, int numberOutputNotation)
{
	std::string outputNumber;

	int divider = numberOutputNotation;
	int remain = 1;
	if (result != 0)
	{
		bool isSigned = result < 0;

		unsigned int anbsoluteValue = abs(result);
		while (anbsoluteValue > 0)
		{
			remain = anbsoluteValue % numberOutputNotation;

			anbsoluteValue /= numberOutputNotation;

			if (IsInDiaposon(remain , 0 , 9))
			{
				outputNumber.insert(outputNumber.begin() , int('0') + remain);
			}
			else
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

int main(int argc , char *argv[])
{

	if (checkParametrs(argc , argv))
	{
		unsigned int numberInputNotation = atoi(argv[1]);
		unsigned int numberOutputNotation = atoi(argv[2]);

		std::string inputNumber = argv[3];		
		int result = TranslateStringToNumber(inputNumber , numberInputNotation);
		std::string outputNumber = TranslateIntToString(result, numberOutputNotation);

		std::cout << "Result = " << outputNumber << std::endl;
		std::cout << "In desimal notation = " << result << std::endl;
	}

	std::cout << "Press any key for exit..." << std::endl;
	_getch();

   return 0;
}
