// Lab1-3.cpp: определяет точку входа для консольного приложения.
//

/*
Лабораторная работа 1. 3 задание Вариант №2

Разработайте приложение invert.exe, выполняющее инвертирование 
матрицы 3*3, т.е. нахождение обратной матрицы  и выводящее 
коэффициенты результирующей матрицы в стандартный поток вывода.
Формат командной строки приложения

invert.exe<matrixfile1>
*/

#include "stdafx.h"
#include "MyFunctions.h"

static const unsigned int SIZE_MATRIX = 3;
static const char* TXT_FILE_FORMAT = "txt";

bool checkParametrs(int argc , char *argv[])
{
	if (argc == 2)
	{
			return true;
	}
	std::cout << "Must be one parametr!!! " << std::endl;

	return false;
}

void FillMatrixFromFile(const char* nameFile , float (*matrix)[SIZE_MATRIX])
{
	FILE* inputFile;

	bool successfulLoadFiles = MyFunctions::CheckLoadFile(&inputFile , nameFile, "r");
	if (successfulLoadFiles)
	{
		for (int y = 0; y < SIZE_MATRIX; y++)
		{
			for (int x = 0; x < SIZE_MATRIX; x++)
			{
				matrix[y][x] = MyFunctions::ReadNumber(inputFile);
			}
		}
	}

	fclose(inputFile);

}

int main(int argc , char *argv[])
{
	if (checkParametrs(argc , argv))
	{
		float matrix[SIZE_MATRIX][SIZE_MATRIX];

		char fullNameFile[SIZE_CHAR_BUFFER];
		strcpy_s(fullNameFile, SIZE_CHAR_BUFFER, argv[1]);
		MyFunctions::ConstructFullFileName(fullNameFile , TXT_FILE_FORMAT);

		FillMatrixFromFile(fullNameFile , matrix);

		std::cout << MyFunctions::GetDeterminate(matrix) << std::setprecision(1) << std::fixed << 3 << std::endl;
	}


	std::cout << "Press any key for exit..." << std::endl;
	_getch();

    return 0;
}
