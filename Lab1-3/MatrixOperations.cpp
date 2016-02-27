#include "stdafx.h"
#include "MatrixOperations.h"

double MatrixOperations::GetDeterminate(const Matrix &matrix)
{
	double determinate = 0;
	size_t sizeMatrix = matrix.size();
	if (sizeMatrix > 2)
	{
		int countForDegree = 2;
		for (size_t i = 0; i < 3; i++)
		{
			determinate += matrix[0][i] * pow(-1 , countForDegree) * GetMinor(matrix , i , 0);
			countForDegree++;
		}
	}
	else if(sizeMatrix == 2)
	{
		determinate = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}
	else if(sizeMatrix == 1)
	{
		determinate = matrix[0][0];
	}

	return determinate;
}

// work for 3X3 matrixs
double MatrixOperations::GetMinor(const Matrix &matrix , size_t x , size_t y)
{
	Matrix subMatrix;
	subMatrix.resize(2);
	subMatrix[0].resize(2);
	subMatrix[1].resize(2);

	std::vector<Vector2UL> passPositions;

	for (size_t i = 0; i < 3; i++)
	{
		passPositions.push_back(Vector2UL(x , i));
		passPositions.push_back(Vector2UL(i , y));
	}

	size_t posX = 0;
	size_t posY = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (std::count(passPositions.begin(), passPositions.end(), Vector2UL(j, i)) == 0)
			{
				subMatrix[posY][posX] = matrix[i][j];

				posX++;
				if (posX > 1)
				{
					posX = 0;
					posY++;
					if (posY > 1)
					{
						posY = 0;
					}
				}
			}

		}
	}

	return MatrixOperations::GetDeterminate(subMatrix);
}

Matrix MatrixOperations::GetMinorMatrix(const Matrix & matrix)
{
	Matrix minorMatrix;
	size_t sizeMinorMatrix = matrix.size();
	minorMatrix.resize(sizeMinorMatrix);

	for (size_t index = 0; index < sizeMinorMatrix; index++)
	{
		minorMatrix[index].resize(sizeMinorMatrix);
	}

	int countForDegree = 2;
	for (size_t y = 0; y < sizeMinorMatrix; y++)
	{
		for (size_t x = 0; x < sizeMinorMatrix; x++)
		{
			minorMatrix[y][x] = pow(-1 , countForDegree) * GetMinor(matrix , x , y);
			countForDegree++;
		}
	}

	return minorMatrix;
}

Matrix MatrixOperations::GetTransposeMatrix(const Matrix & matrix)
{
	Matrix transposeMatrix = matrix;
	size_t sizeTransposeMatrix = matrix.size();
	for (size_t y = 0; y < sizeTransposeMatrix; y++)
	{
		for (size_t x = y; x < sizeTransposeMatrix; x++)
		{
			if (x != y)
			{
				std::swap(transposeMatrix[y][x] , transposeMatrix[x][y]);
			}
		}
	};

	return transposeMatrix;
}

Matrix MatrixOperations::GetInvertMatrix(const Matrix & matrix)
{
	double determinate = MatrixOperations::GetDeterminate(matrix);

	if (determinate != 0)
	{

		Matrix transposeMatrix = MatrixOperations::GetTransposeMatrix(matrix);
		Matrix minorMatrix = MatrixOperations::GetMinorMatrix(transposeMatrix);


		for (auto &row : minorMatrix)
		{
			for (auto &element : row)
			{
				element /= determinate;
			}
		}

		return minorMatrix;

	}
	else
	{
		throw MESSAGE_ZERO_DETERMINATE;
	}

}

void MatrixOperations::PrintMatrix(const Matrix &matrix)
{
	std::cout << std::setprecision(3);
	for (auto &row : matrix)
	{
		for (auto &element : row)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
}
