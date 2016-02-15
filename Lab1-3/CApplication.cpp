#include "stdafx.h"
#include "CApplication.h"

using namespace std;

CApplication::CApplication(int argc , char * argv[])
{
	startTime = clock();

	if (CheckParametrs(argc , argv))
	{
		nameInputFile = argv[1];

		isCorrectInputDate = true;
	}
	else
	{
		isCorrectInputDate = false;
	}
}

CApplication::~CApplication()
{
	endTime = clock();

	std::cout << "Time " << static_cast<float>(endTime - startTime) / 1000.f << " second" << std::endl;
}

bool CApplication::Run()
{
	if (isCorrectInputDate)
	{
		Matrix inputMatrix;
		if (FillMatrixFromFile(nameInputFile, inputMatrix))
		{
			double determinate = MatrixOperations::GetDeterminate(inputMatrix);

			if (determinate != 0)
			{

				Matrix invertMatrix = MatrixOperations::GetTransposeMatrix(inputMatrix);
				Matrix minorMatrix = MatrixOperations::GetMinorMatrix(invertMatrix);


				for (auto &row : minorMatrix)
				{
					for (auto &element : row)
					{
						element /= determinate;
					}
				}
				MatrixOperations::PrintMatrix(minorMatrix);

			}
			else
			{
				cout << MESSAGE_ZERO_DETERMINATE << endl;
			}

			return true;
		}
	}
	
	/*
		if (isCorrectInputDate)
	{	
		try
		{
			double matrix[SIZE_MATRIX][SIZE_MATRIX];

			FillMatrixFromFile(nameInputFile , matrix);

			std::cout << MyFunctions::GetDeterminate(matrix) << std::setprecision(1) << std::fixed << 3 << std::endl;
		}

		return true;
	}
	*/


	return false;
}

bool CApplication::CheckParametrs(int argc , char *argv[])
{
	if (argc == AMOUNT_ARGUMENTS)
	{
		return true;
	}
	cout << MESSAGE_INCORRECT_AMOUNT_ARGUMENTS << AMOUNT_ARGUMENTS << endl;

	return false;
}

bool CApplication::FillMatrixFromFile(std::string nameFile, Matrix &matrix)
{
	std::ifstream inputFile;

	inputFile.open(nameFile);
	if (!CheckFileForReading(inputFile))
	{
		return false;
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
		return false;
	}

	return true;
}

bool CApplication::CheckFileForReading(ifstream & file)
{
	if (!file.is_open())
	{
		cout << MESSAGE_FAILED_OPEN << nameInputFile << MESSAGE_FAILED_OPEN_FOR_READING << endl;
		return false;
	}

	return true;
}