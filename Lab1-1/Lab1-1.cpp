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
static const char* TXT_FILE_FORMAT = "txt";
static const int RESET_VALUE = -1;

bool CheckLoadFile(FILE **file , char const *name , char const *mode)
{
	errno_t eGetFile = fopen_s(file , name , mode);
	if (eGetFile)
	{
		std::cout << "File " << name << "not load!\n" << std::endl;
	}
	return eGetFile == 0;
}

void resetString(char* array)
{
	for (size_t id = 0; id < strlen(array); id++)
	{
		array[id] = '\0';
	}
}

bool checkParametrs(int argc , char *argv[])
{
	if (argc == 5)
	{
		return true;
	}
	std::cout << "Not enough amount parametrs!!! " << std::endl;	

	return false;
}

bool SearchEqualSymbols(int position, char *currentString, const char* searchString)
{
	int lengthSearchString = strlen(searchString);

	int leftCounter = position;
	int rightCounter = position + lengthSearchString - 1;
	unsigned int idCheckSymbol = 0;

	bool leftIsEqual = false;
	bool rightIsEqual = false;
	while (leftCounter <= rightCounter)
	{
		leftIsEqual = (currentString[leftCounter] == searchString[idCheckSymbol]);
		rightIsEqual = (currentString[rightCounter] == searchString[lengthSearchString - idCheckSymbol - 1]);

		if (leftIsEqual && rightIsEqual)
		{
			leftCounter++;
			rightCounter--;
			idCheckSymbol++;
			continue;
		}
		break;
	}

	return leftIsEqual && rightIsEqual;
}

int main(int argc , char *argv[])
{
	if (checkParametrs(argc , argv))
	{
		char nameInputFile[SIZE_CHAR_BUFFER];
		char nameOutputFile[SIZE_CHAR_BUFFER];

		strcpy_s(nameInputFile, argv[1]);
		strcpy_s(nameOutputFile, argv[2]);
		
		strcat_s(nameInputFile , ".");
		strcat_s(nameOutputFile , ".");

		strcat_s(nameInputFile, TXT_FILE_FORMAT);
		strcat_s(nameOutputFile, TXT_FILE_FORMAT);

		const char* searchString = argv[3]; 
		const char* replaceString = argv[4]; 
		int lengthSearchString = strlen(searchString);
		int lengthReplaceString = strlen(replaceString);

		FILE* inputFile;
		FILE* outputFile;

		bool successfulLoadFiles = CheckLoadFile(&inputFile , nameInputFile , "r")
			&& CheckLoadFile(&outputFile , nameOutputFile , "w");
		if (successfulLoadFiles)
		{
			char currentString[SIZE_CHAR_BUFFER];
			resetString(currentString);

			while (!feof(inputFile))
			{
				fgets(currentString , SIZE_CHAR_BUFFER , inputFile);

				int i = 0;
				bool isEqualSymbols = false;
				while ((i < (strlen(currentString))) && (currentString[i] != '\0'))
				{

					if ((i + lengthSearchString - 1) <= strlen(currentString))
					{
						isEqualSymbols = SearchEqualSymbols(i , currentString , searchString);

						if (isEqualSymbols)
						{
							fputs(replaceString , outputFile);
							i += lengthSearchString;
						}
					}

					if (!isEqualSymbols)
					{
						fputc(currentString[i] , outputFile);
						i++;
					}
					isEqualSymbols = false;
				}
			}

			fclose(inputFile);
			fclose(outputFile);
		}
		
	}

	std::cout << "Press any key for exit..." << std::endl;
	_getch();
	return 0;
}

