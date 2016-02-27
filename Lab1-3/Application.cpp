#include "stdafx.h"
#include "Application.h"

using namespace std;

void RunProgram(int argc, char * argv[])
{
	CheckParametrs(argc, argv);
	
	Matrix inputMatrix;
	MatrixOperations::FillMatrixFromFile(argv[1], inputMatrix);

	Matrix invertMatrix = MatrixOperations::GetInvertMatrix(inputMatrix);

	MatrixOperations::PrintMatrix(invertMatrix);	
}

void CheckParametrs(int argc , char *argv[])
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}
}

void MatrixOperations::FillMatrixFromFile(string nameFile, Matrix &matrix)
{
	ifstream inputFile;
	inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	inputFile.open(nameFile);
	if (!inputFile.is_open())
	{
		throw MESSAGE_FAILED_OPEN + nameFile + MESSAGE_FAILED_OPEN_FOR_READING;
	}

	RowMatrix row;
	double addNumber;
	for (size_t y = 0; y < SIZE_MATRIX; y++)
	{
		for (size_t x = 0; x < SIZE_MATRIX; x++)
		{
			 inputFile >> addNumber;
			 row.push_back(addNumber);
		}
		matrix.push_back(row);
		row.clear();
	}

	if (!inputFile.eof())
	{
		string passString = "";
		inputFile >> passString;
		if (passString != "")
		{
			throw MESSAGE_INCORRECT_DATA;
		}
	}
	


}