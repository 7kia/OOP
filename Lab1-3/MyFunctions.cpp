#include "stdafx.h"
#include "MyFunctions.h"

bool MyFunctions::IsInList(position value , const std::vector<position> &list)
{
	for (auto element : list)
	{
		if (value == element)
		{
			return true;
		}
	}
	return false;
}
/*
double MyFunctions::GetDeterminate(double(*matrix)[2])
{
	return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

double MyFunctions::GetDeterminate(double(*matrix)[3])
{
	double determinate = 0;
	int countForDegree = 2;
	for (size_t i = 0; i < 3; i++)
	{
		determinate += static_cast<float>(pow(-1 , countForDegree)) * MyFunctions::GetMinor(matrix , i , 0);
		countForDegree++;
	}

	return determinate;
}

double MyFunctions::GetMinor(double(*matrix)[3], size_t x, size_t y)
{
	double subMatrix[2][2];
	std::vector<Vector2U> passPositions;

	for (size_t i = 0; i < 3; i++)
	{
		passPositions.push_back(Vector2U(x , i));
		passPositions.push_back(Vector2U(i , y));
	}

	size_t posX = 0;
	size_t posY = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (!MyFunctions::IsInList(Vector2U(j , i) , passPositions))
			{
				subMatrix[posY][posX] = matrix[i][j];

				posX++;
				if (posX > 1)
				{
					posX = 0;
					posY++;
				}	
			}

		}
	}

	return matrix[y][x] * MyFunctions::GetDeterminate(subMatrix);

}

*/