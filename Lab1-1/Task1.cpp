// Task1.cpp: определяет точку входа для консольного приложения.
//


/*

Лабораторная работа 1. 1 задание 4 вариант
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


void resetString(char* array, int size, char value)
{
	for (size_t id = 0; id < size; id++)
	{
		array[id] = value;
	}
}

bool checkParametrs(int argc , char *argv[])
{
	if (argc == 5)
	{
		return true;
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
			unsigned int idCheckSymbol = 0;
			unsigned int countСoincidence = 0;
			int idFirstEqualSymbol = RESET_VALUE;

			char charBuffer[SIZE_CHAR_BUFFER];
			char equalSymbol = '\0';
			resetString(charBuffer , SIZE_CHAR_BUFFER , '\0');
			//resetString(equalSymbols , SIZE_CHAR_BUFFER , '\0');

			while (!feof(inputFile))
			{
				fgets(charBuffer , SIZE_CHAR_BUFFER , inputFile);

				int i = 0;
				while((i < SIZE_CHAR_BUFFER) && (charBuffer[i] != '\0'))
				{
					if (charBuffer[i] == searchString[idCheckSymbol])
					{

						if (idFirstEqualSymbol == RESET_VALUE)
						{
							idFirstEqualSymbol = i;
							equalSymbol = charBuffer[i];
						}

						
						idCheckSymbol++;
						if (idCheckSymbol == strlen(searchString))
						{
							countСoincidence++;
							idCheckSymbol = 0;
							equalSymbol = '\0';

							fputs(replaceString , outputFile);
						}
						i++;
					}
					else
					{
						if (equalSymbol != '\0')
						{
							fputc(equalSymbol , outputFile);
							i = idFirstEqualSymbol + 1;
							equalSymbol = '\0';
						}
						else
						{
							fputc(charBuffer[i] , outputFile);
							i++;
						}

						idCheckSymbol = 0;
					}
					//i++;
				}

				resetString(charBuffer , SIZE_CHAR_BUFFER , '\0');
			}

		}

		fclose(inputFile);
		fclose(outputFile);
	}
	else
	{
		std::cout << "Not enough amount parametrs!!! " << argc << std::endl;
	}

	std::cout << "Press any key for exit..." << std::endl;
	_getch();
	return 0;
}

