// Lab1-2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

/*
������������ ������ 1. 2 ������� 7 �������

������������ ��������� radix.exe, ����������� ������� ����� ��
����� ������������ ������� ��������� � ������ ������������ � 
������ ���������� � ����������� ����� ������. ��� ������������
�������� ��������� ���������� ������� � ���������� �� 2 �� 36. 
������� ��������� � 11-������ �� 36-������ ������ ������������
��������� ����� ���������� �������� �� A �� Z ��� �������������
�������� � 1110�� 3510. �������������������������������:

radix.exe <source notation><destination notation><value>

��������, ��������� �������� ��������� ������ ������������
������� ������������������ ����� 1F � ��� ���������� �������������:
radix.exe 16 10 1F

� ����� ������, ��������� � ����������� ����� ������������ 
������������� ��� \n.

��������� ������ ���� �������� ������������ ������� ���
�������������, ��� � ������������� �����, � ����� ����. ������ 
�������� ������� �������� ������������ � ����������� ����� 
����� �� ������ ��������� (��� ������ ����������������� 
���������).


*/
#include "stdafx.h"

static const int SIZE_STRING = 255;

bool CheckLoadFile(FILE **file , char const *name , char const *mode)
{
	errno_t eGetFile = fopen_s(file , name , mode);
	assert(eGetFile == 0);
	if (eGetFile)
	{
		std::cout << "File " << name << "not load!\n" << std::endl;
	}
	return eGetFile == 0;
}


void resetString(char* array , int size , char value)
{
	for (size_t id = 0; id < size; id++)
	{
		array[id] = value;
	}
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
		}
		return !isError;
		
	}
	std::cout << "Not enough amount parametrs!!! " << argc << std::endl;

	return false;
}

template<typename T>
bool IsInDiaposon(T number, T start, T end)
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
}


bool checkInputNumber(char* number)
{
	unsigned int numberInputNotation = 10;//atoi(argv[1]);

	for (int i = 0; i < strlen(number); i++)
	{
		if (CharToInt(number[i]) > numberInputNotation)
		{
			return false;
		}
	}
	return true;
}

int main(int argc , char *argv[])
{

	if (true)//checkParametrs(argc , argv)
	{
		unsigned int numberInputNotation = 16;//atoi(argv[1]);
		unsigned int numberOutputNotation = 10;//atoi(argv[2]);
		unsigned int degree = 0;
		int result = 0;
		std::string inputNumber = "FF";//argv[3];

		int multiplier = 0;
		for (int i = int(inputNumber.size()) - 1; i >= 0; i--)
		{
			multiplier = CharToInt(inputNumber[i]);

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

				/*
								if ((remain == 0) && (copyResult > 0))
				{
					copyResult--;
					remain = numberOutputNotation - 1;
				}
				*/


				if (IsInDiaposon(remain, -9, 9))
				{
					outputNumber.insert(outputNumber.begin(), int('0') + remain);
				}
				else
				{
					outputNumber.insert(outputNumber.begin() , int('A') + remain - 10);
				}

			}

		}
		else
		{
			outputNumber = '0';// check correct output
		}
		

		std::cout << "Result = " << outputNumber << std::endl;

	}

	std::cout << "Press any key for exit..." << std::endl;
	_getch();

   return 0;
}

