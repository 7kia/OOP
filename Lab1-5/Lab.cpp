#include "stdafx.h"
#include "Lab.h"

using namespace std;

void LoadBitmapFromFile(bitmap &bitmap, string nameFile, char fill, size_t x, size_t y)
{
	ifstream file(nameFile);

	if (!file.is_open())
	{
		assert(false);
		return;// TODO : throw
	}
	std::string addString;

	while (getline(file, addString))
	{
		bitmap.push_back(addString);
	}
}

void FillAreaInBitmap(bitmap &bitmap, char fill, size_t x, size_t y)
{

}


/*
bool CLabAaSD::checkWidthAndHeight()
{
	if ((heightMap < 1) && (widthMap < 1))
	{
		throw MESSAGE_INCORRECT_SIZE;
		return false;
	}
	return true;
}

bool CLabAaSD::checkCounterWidthMap()
{
	if ((static_cast<int>(countWidth) > widthMap) && (static_cast<int>(countWidth) < 0) && (widthMap > 0))
	{
		throw MESSAGE_WIDTH_MORE_EXPECTED;
		return false;
	}
	return true;
}

bool CLabAaSD::checkCounterHeightMap()
{
	if ((static_cast<int>(countHeight) > heightMap) && (static_cast<int>(countHeight) < 0) && (heightMap > 0))
	{
		throw MESSAGE_HEIGHT_MORE_EXPECTED;
		return false;
	}
	return true;
}

size_t CLabAaSD::GetAmountWallsForTrees(forest &forest)
{
	size_t amountWalls = 0;

	for (size_t y = 0; y < forest.size(); y++)
	{
		for (size_t x = 0; x < forest[y].size(); x++)
		{
			if (forest[y][x] == charTree)
			{
				amountWalls += GetAmountWallsForTree(forest, x, y);

			}
		}
	}

	return amountWalls;
}

size_t CLabAaSD::GetInsideWalls(size_t x, size_t y, forest & forest)
{

	size_t amountNeightbos = 0;


	int X = static_cast<int>(x);
	int Y = static_cast<int>(y);

	for (int x1 = -1; x1 <= 1; x1++)
	{
		for (int y1 = -1; y1 <= 1; y1++)
		{
			if (abs(x1) != abs(y1))
			{
				// �������� ������������
				if ((((X + x1) >= 0) && ((Y + y1) >= 0))
					&& ((X + x1) <= widthMap) && ((Y + y1) < forest.size()))
				{
					if (forest[Y + y1][X + x1] == charTree)
					{
						amountNeightbos++;
					}
				}
				//
			}
		}
	}

	return amountNeightbos;

}

bool CLabAaSD::SearchEmptyPlace(int &x, int &y, forest & forest)
{
	// ����� ������
	for (int x1 = -1; x1 <= 1; x1++)
	{
		for (int y1 = -1; y1 <= 1; y1++)
		{

			if (abs(x1) != abs(y1))
			{
				// �������� ������������
				if ((((x + x1) >= 0) && ((y + y1) >= 0))
					&& ((x + x1) <= widthMap) && ((y + y1) < forest.size()))
				{
					if ((forest[y + y1][x + x1] == emptyChar))
					{
						// �������� ������� ��������
						if (((x1 != 0)
							&&
							((forest[y + 1][x + x1] == charTree)
								^
							(forest[y - 1][x + x1] == charTree))
								)
							//
							||
							//
							((y1 != 0)
								&&
								((forest[y + y1][x + 1] == charTree)
									^
									(forest[y + y1][x - 1] == charTree))
								)
							)
							//
						{
							forest[y][x] = searchChar;
							x += x1;
							y += y1;
							return true;
						}
					}
				}
				else
				{
					x++;
					return false;
				}
				//
			}

			

		}
	}

	return false;
}

void CLabAaSD::RemoveInsideWalls(size_t & amount , forest & forest)
{
	bool removeInsideWall = false;
	size_t amountNeightbos = 0;
	size_t subtrahend = 0;

	size_t amountInCurrentPlace = 0;

	int y = 1;
	int x = 1;
	removeInsideWall = false;
	while (y < (forest.size() - 1))
	{
		while (x < (forest[y].size() - 1))
		{
			//amountNeightbos = 0;
			

			if (forest[y][x] != charTree)
			{
				if (amountNeightbos > 1)
				{
					amountInCurrentPlace--;
				}
				amountNeightbos = GetInsideWalls(x, y, forest);
				amountInCurrentPlace += amountNeightbos;


				// ����� ������
				/*
				for (int x1 = -1; x1 <= 1; x1++)
				{
					for (int y1 = -1; y1 <= 1; y1++)
					{

						/.*
											if (abs(x1) != abs(y1))
						{
							// �������� ������������
							if ((((x + x1) >= 0) && ((y + y1) >= 0))
									&& ((x + x1) <= widthMap) && ((y + y1) < forest.size()))
							{
								if (forest[y + y1][x + x1] == charTree)
								{
									amountNeightbos++;
								}
							}

						}

						//*-/
						// �������� ������������
						if ((((x + x1) >= 0) && ((y + y1) >= 0))
							&& ((x + x1) <= widthMap) && ((y + y1) < forest.size()))
						{
							if (forest[y + y1][x + x1] != charTree)
							{
								forest[y + y1][x + x1] = charTree;
								x += x1;
								y += y1;
								removeInsideWall = false;
								continue;
							}
						}
						else
						{
							x++;
							break;
						}
						//

					}
				}

				*./
				
				if (SearchEmptyPlace(x, y, forest))
				{
					continue;
				}
				else if (amountInCurrentPlace > 0)
				{
					forest[y][x] = searchChar;
				}
				

			}

			//if ((subtrahend == 0))
			//{
				amount -= amountInCurrentPlace;
				std::cout << amount << std::endl;
				std::cout << subtrahend << std::endl;
				std::cout << amountInCurrentPlace << std::endl;
				amountInCurrentPlace = 0;
				std::cout << std::endl;
			//}

			/,*
			else if (subtrahend > 0)
			{
				subtrahend += amountInCurrentPlace;
				subtrahend -= 1;
				amount -= subtrahend;
				std::cout << amount << std::endl;
				std::cout << subtrahend << std::endl;
				std::cout << amountInCurrentPlace << std::endl;
				std::cout << std::endl;


			}
			subtrahend = 0;
			amountInCurrentPlace = 0;
			*,/
			

			x++;
		}

		x = 1;
		y++;
	}
}

size_t CLabAaSD::GetAmountWallsForTree(forest &forest, int x , int y)
{
	size_t amountWalls = 4;

	for (int x1 = -1; x1 <= 1; x1++)
	{
		for (int y1 = -1; y1 <= 1; y1++)
		{

			// X+X
			// +X+     X - �� �������� ��������
			// X+X     + - �������� ��������
			if (abs(x1) != abs(y1))
			{
				// �������� ������������
				if ( (((x + x1) >= 0) && ((y + y1) >= 0))
						&& ((x + x1) <= widthMap) && ((y + y1) < forest.size()))
				{

					if (forest[y + y1][x + x1] == charTree)
					{
						amountWalls--;
					}
				}
				//
			}

		}

	}

	return amountWalls;
}


*/

point::point()
{
}

point::point(size_t first, size_t second)
{
	x = first;
	y = second;
}
