#include "stdafx.h"
#include "MyFunctions.h"

Vector2U::Vector2U(uint first , uint second)
{
	x = first;
	y = second;
}

Vector2U::Vector2U()
{
}

bool MyFunctions::CheckLoadFile(FILE **file , char const *name , char const *mode)
{
	errno_t eGetFile = fopen_s(file , name , mode);
	if (eGetFile)
	{
		std::cout << "File " << name << "not load!\n" << std::endl;
	}
	return eGetFile == 0;
}

bool MyFunctions::IsSpaceSymbol(char symbol)
{
	return (symbol != ' ') && (symbol != '\n');
}


void MyFunctions::resetString(char* array)
{
	for (size_t id = 0; id < strlen(array); id++)
	{
		array[id] = '\0';
	}
}

int MyFunctions::ReadNumber(FILE *file)
{
	char stringValue[SIZE_CHAR_BUFFER] = "\0";

	if (!feof(file))
	{
		fgets(stringValue , SIZE_CHAR_BUFFER , file);
	}

	assert(stringValue != "\0");
	return atoi(stringValue);
}

char* MyFunctions::ConstructFullFileName(const char* name , const char* format)
{
	unsigned int size = strlen(name) + strlen(format) + 1;
	char* result = new char[size];

	strcpy_s(result , size , name);
	strcat_s(result , size , ".");
	strcat_s(result , size , format);

	return result;
}

bool MyFunctions::IsInList(Vector2U value ,const std::vector<Vector2U> &list)
{
	for (Vector2U element : list)
	{
		if ((value.x == element.x) && (value.y == element.y))
		{
			return true;
		}
	}
	return false;
}

double MyFunctions::GetDeterminate(double(*matrix)[2])
{
	return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

double MyFunctions::GetDeterminate(double(*matrix)[3])
{
	int determinate = 0;
	int countForDegree = 2;
	for (uint i = 0; i < 3; i++)
	{
		determinate += static_cast<float>(pow(-1 , countForDegree)) * MyFunctions::GetMinor(matrix , i , 0);
		countForDegree++;
	}

	return determinate;
}

double MyFunctions::GetMinor(double(*matrix)[3], uint x, uint y)
{
	double subMatrix[2][2];
	std::vector<Vector2U> passPositions;
	Vector2U addVector;

	for (uint i = 0; i < 3; i++)
	{
		passPositions.push_back(Vector2U(x , i));
		passPositions.push_back(Vector2U(i , y));
	}

	uint posX = 0;
	uint posY = 0;
	for (uint i = 0; i < 3; i++)
	{
		for (uint j = 0; j < 3; j++)
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
