// Lab1-3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

/*
������������ ������ 1. 3 ������� ������� �2

������������ ���������� invert.exe, ����������� �������������� 
������� 3*3, �.�. ���������� �������� �������  � ��������� 
������������ �������������� ������� � ����������� ����� ������.
������ ��������� ������ ����������

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

void FillMatrixFromFile(const char* nameFile , double(*matrix)[SIZE_MATRIX])
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
		double matrix[SIZE_MATRIX][SIZE_MATRIX];

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
