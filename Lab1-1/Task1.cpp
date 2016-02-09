// Task1.cpp: определяет точку входа для консольного приложения.
//


/*
Лабораторная работа 1. 1 задание 4 вариант

Разработайте программу replace.exe, выполняющую замену подстроки 
в текстовом файле на другую строку, и записывающей результат в
выходной файл (отличный от входного). 

Формат командной строки:
replace.exe <input file><output file><search string><replace string>

Программа должна корректно обрабатывать ошибки, связанные с 
открытием входных и выходных файлов. Искомая строка не может быт
пустой.

Размеры входных и выходных файлов ограничены 2 Гб. Размеры искомой
строки и строки-заменителя не ограничены.
Внимание, программа корректно должна обрабатывать ситуацию, когда 
длина искомой строки равна нулю. В этом случае замены символов 
производиться не должно.Также корректно должна обрабатываться 
ситуация с многократным вхождением искомой строки в 
строку-заменитель (например, замена строки «ма» на «мама» 
не должна приводить к зацикливанию).
*/

#include "stdafx.h"

static const unsigned int SIZE_CHAR_BUFFER = 255;
static const char* TEXT_FILE_FORMAT = ".txt";
static const int RESET_VALUE = -1;

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


void resetString(char* array, char value)
{
	for (size_t id = 0; id < strlen(array); id++)
	{
		array[id] = value;
	}
}

bool checkParametrs(int argc , char *argv[])
{
	if (argc == 5)
	{
		for (int i = 1; i < 5; i++)
		{
			if (!isalpha(*argv[i]) && !isdigit(*argv[i]))
			{
				std::cout << "Arguments must consist letters or(and) numbers!!! " << *argv[i] <<  std::endl;
				return false;
			}
		}
		return true;
	}
	else
	{
		std::cout << "Not enough amount parametrs!!! " << std::endl;
	}

	return false;
}

int main(int argc , char *argv[])
{
	if (checkParametrs(argc , argv))
	{
		char nameInputFile[SIZE_CHAR_BUFFER];
		char nameOutputFile[SIZE_CHAR_BUFFER];

		strcpy_s(nameInputFile , argv[1]);
		strcpy_s(nameOutputFile , argv[2]);

		strcat_s(nameInputFile , TEXT_FILE_FORMAT);
		strcat_s(nameOutputFile, TEXT_FILE_FORMAT);
	
		const char* searchString = argv[3];
		const char* replaceString = argv[4];

		FILE* inputFile;
		FILE* outputFile;

		bool successfulLoadFiles = CheckLoadFile(&inputFile , nameInputFile , "r")
															&& CheckLoadFile(&outputFile , nameOutputFile , "w");
		if (successfulLoadFiles)
		{
			int idFirstEqualSymbol = RESET_VALUE;

			char charBuffer[SIZE_CHAR_BUFFER];
			char equalSymbols[SIZE_CHAR_BUFFER];

			char equalSymbol = '\0';
			resetString(charBuffer, '\0');
			resetString(equalSymbols , '\0');

			while (!feof(inputFile))
			{
				fgets(charBuffer , SIZE_CHAR_BUFFER , inputFile);

				unsigned int idCheckSymbol = 0;
				unsigned int countСoincidence = 0;
				bool wasEqualSymbol = false;
				int i = 0;
				while((i < SIZE_CHAR_BUFFER) && (charBuffer[i] != '\0'))
				{
					if (charBuffer[i] == searchString[idCheckSymbol])
					{
						if (idFirstEqualSymbol == RESET_VALUE)
						{
							idFirstEqualSymbol = i + 1;
						}
						equalSymbols[idCheckSymbol] = charBuffer[i];
						equalSymbols[idCheckSymbol + 1] = '\0';
						
						idCheckSymbol++;
						if (idCheckSymbol == strlen(searchString))
						{
							countСoincidence++;
							idCheckSymbol = 0;
							resetString(equalSymbols , '\0');

							fputs(replaceString , outputFile);
						}
						i++;
					}
					else
					{
						bool wasEqualSymbol = equalSymbols[0] != '\0';
						if (wasEqualSymbol)
						{
							//for (int counter = 0; counter < strlen(equalSymbols); counter++)
							//{
								fputs(equalSymbols , outputFile);

							//}

							i -= (strlen(equalSymbols) - 1);
							std::cout << idFirstEqualSymbol << std::endl;
							resetString(equalSymbols , '\0');
						}
						else
						{
							fputc(charBuffer[i] , outputFile);
							i++;
						}

						idFirstEqualSymbol = RESET_VALUE;
						idCheckSymbol = 0;
					}
				}

				resetString(charBuffer, '\0');
			}

		}

		fclose(inputFile);
		fclose(outputFile);
	}
	else
	{
		std::cout << "Not enough amount parametrs!!! " << std::endl;
	}

	std::cout << "Press any key for exit..." << std::endl;
	_getch();
	return 0;
}

