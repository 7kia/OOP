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

static const int SIZE_STRING = 255;
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


bool checkInputNumber(char* number , int numberInputNotation)
{
	int start = 0;

	if (number[0] == '-')
	{
		start = 1;
	}

	for (int i = start; i < strlen(number); i++)
	{
		if (CharToInt(number[i]) > numberInputNotation)
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
		for (int i = 1; i < argc; i++)
		{
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

			if (!isdigit(*argv[3]) && !isalpha(*argv[3]))
			{
				std::cout << "Incorrect translate number!!!" << argc << std::endl;
				isError = true;
			}
			else if(!checkInputNumber(argv[3], atoi(argv[1])))
			{
				std::cout << "Use incorrect number notation or incorrect retranslate number!!!" << argc << std::endl;
				isError = true;
			}
		}
		return !isError;
		
	}
	std::cout << "Not enough amount parametrs!!! " << argc << std::endl;

	return false;
}

int main(int argc , char *argv[])
{

	if (checkParametrs(argc , argv))
	{
		unsigned int numberInputNotation = atoi(argv[1]);
		unsigned int numberOutputNotation = atoi(argv[2]);
		unsigned int degree = 0;
		int result = 0;
		std::string inputNumber = argv[3];
		
		int multiplier = 0;
		for (int i = int(inputNumber.size()) - 1; i >= 0; i--)
		{
			multiplier = CharToInt(inputNumber[i]);
			assert(multiplier != ERROR_CODE);

			result += multiplier * int(pow(numberInputNotation , degree));
			degree++;
		}

		std::string outputNumber;
		int copyResult = result;
		int divider = numberOutputNotation;
		int remain = 1;
		degree = 2;
		if (copyResult > 0)
		{
			
			while (copyResult > 0)
			{
				remain = copyResult % numberOutputNotation;

				copyResult /= numberOutputNotation;

				if (IsInDiaposon(remain, -9, 9))
				{
					outputNumber.insert(outputNumber.begin(), int('0') + remain);
				}
				else
				{
					outputNumber.insert(outputNumber.begin() , int('A') + remain - 10);
				}

			}

			if (inputNumber[0] == '-')
			{
				outputNumber.insert(outputNumber.begin() , '-');
			}

		}	

		std::cout << "Result = " << outputNumber << std::endl;

	}

	std::cout << "Press any key for exit..." << std::endl;
	_getch();

   return 0;
}

