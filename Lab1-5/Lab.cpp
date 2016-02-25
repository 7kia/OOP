#include "stdafx.h"
#include "Lab.h"

using namespace std;

void LoadBitmapFromFile(bitmap &bitmap, string nameFile)
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

void FillAreaInBitmap(bitmap &bitmap, char fill, int x, int y)
{
	char replaceColor = bitmap[y][x];// TODO : add throw

	if (replaceColor == fill)
	{
		return;
	}
	else 
	{
		//bitmap[y][x] = fill;

		point leftReturnPosition(x, y);
		point rightReturnPosition(AdditionWithCheckBorder(x, 1, bitmap[y].size()), y);

		SearchInString(bitmap, fill, replaceColor, leftReturnPosition, side::Left);
		SearchInString(bitmap, fill, replaceColor, rightReturnPosition, side::Right);

		bool replaceTowardUp = false;
		bool replaceTowardDown = false;

		do
		{
			replaceTowardUp = SearchOnVertical(bitmap, fill, replaceColor, leftReturnPosition, rightReturnPosition, vertical::Up);
			if (replaceTowardUp)
			{
				replaceTowardDown = SearchOnVertical(bitmap, fill, replaceColor, leftReturnPosition, rightReturnPosition, vertical::Down);
			}	
			else
			{
				replaceTowardDown = false;
			}
		} while (replaceTowardUp || replaceTowardDown);
		

		leftReturnPosition = point(x, y);
		rightReturnPosition = point(AdditionWithCheckBorder(x, 1, bitmap[y].size()), y);

		do			
		{
			replaceTowardDown = SearchOnVertical(bitmap, fill, replaceColor, leftReturnPosition, rightReturnPosition, vertical::Down);
			if (replaceTowardDown)
			{
				replaceTowardUp = SearchOnVertical(bitmap, fill, replaceColor, leftReturnPosition, rightReturnPosition, vertical::Up);
			}
			else
			{
				replaceTowardUp = false;
			}
		} while (replaceTowardUp || replaceTowardDown);

	}
}


int AdditionWithCheckBorder(int source, int summand)
{
	int result = source + summand;
	if (result < 0)
	{
		//assert(result > 0);// TODO : add throw
		return 0;
	}
	return result;
}

int AdditionWithCheckBorder(int source, int summand, size_t size)
{
	int result = source + summand;
	if ((result < 0) || (result >= size))
	{
		//assert(result > 0);// TODO : add throw
		return 0;
	}
	return result;
}

bool SearchInString(bitmap &bitmap, char fill, char replaceColor, point &returnPosition, side side)
{
	bool found = false;
	int shift = 0;
	switch (side)
	{
	case side::Left:
		shift = -1;
		break;
	case side::Right:
		shift = 1;
		break;
	default:
		break;
	}

	int summand = 0;
	point retPosition = returnPosition;
	do
	{	
		if (bitmap[retPosition.y][retPosition.x] == replaceColor)
		{
			bitmap[retPosition.y][retPosition.x] = fill;
			found = true;
		}
		else
		{	
			//
			returnPosition = retPosition;
			returnPosition.x = AdditionWithCheckBorder(returnPosition.x, -shift, bitmap[returnPosition.y].size());
			return found;
			//
		}

		summand = AdditionWithCheckBorder(retPosition.x, shift);
		if ((summand < 0) || (summand >= bitmap[retPosition.y].size()))
		{
			//
			returnPosition = retPosition;
			returnPosition.x = AdditionWithCheckBorder(returnPosition.x, -shift, bitmap[returnPosition.y].size());
			return found;
			//
		}

		retPosition.x = summand;

	} while (bitmap[retPosition.y][retPosition.x] == replaceColor);

	//
	returnPosition = retPosition;
	returnPosition.x = AdditionWithCheckBorder(returnPosition.x, -shift, bitmap[returnPosition.y].size());
	return found;
	//
}

bool SearchOnVertical(bitmap &bitmap, char fill, char replaceColor, point &leftReturnPosition, point &rightReturnPosition, vertical direction)
{
	point leftPosition = leftReturnPosition;
	point rightPosition = rightReturnPosition;

	int shift = 0;
	switch (direction)
	{
	case vertical::Up:
		shift = -1;
		break;
	case vertical::Down:
		shift = 1;
		break;
	default:
		break;
	}

	point searchPosition = leftPosition;
	point searchPositionForRight = rightPosition;
	bool found = false;
	int summand;

	bool foundLeft = false;
	bool foundRight = false;
	bool isBetween = false;


	do
	{
		////
		// Поиск позиции
		summand = AdditionWithCheckBorder(leftPosition.y, shift, bitmap.size());
		if ((summand < 0) || (summand > bitmap[leftPosition.y].size()))
		{
			//////////////
			// Запоминание точки
			leftReturnPosition = searchPosition;
			rightReturnPosition = searchPositionForRight;
			//////////////
			return found;
		}

		leftPosition.y = summand;
		do
		{

			if (bitmap[leftPosition.y][leftPosition.x] == replaceColor)
			{
				searchPosition = leftPosition;
				searchPositionForRight = searchPosition;
				searchPositionForRight.x = AdditionWithCheckBorder(searchPosition.x, 1, bitmap[leftPosition.y].size());
				break;
			}
			leftPosition.x = AdditionWithCheckBorder(leftPosition.x, 1, bitmap[leftPosition.y].size());

		} while ((leftPosition.x != rightPosition.x) && (AdditionWithCheckBorder(leftPosition.x, 1, bitmap[leftPosition.y].size()) > 0));

		// Если залито сверху то выходим
		if (leftPosition.x > rightPosition.x)
		{
			//////////////
			// Запоминание точки
			leftReturnPosition = searchPosition;
			rightReturnPosition = searchPositionForRight;
			//////////////
			return found;
		}

		foundLeft = SearchInString(bitmap, fill, replaceColor, searchPosition, side::Left);
		foundRight = SearchInString(bitmap, fill, replaceColor, searchPositionForRight, side::Right);
		isBetween = ((leftPosition.y >= 0) && (leftPosition.y <= bitmap.size()));

		if ((foundLeft || foundRight) && !found)
		{
			found = true;
		}

	} while ((foundLeft || foundRight) && isBetween);
	

	//////////////
	// Запоминание точки
	leftReturnPosition = searchPosition;
	rightReturnPosition = searchPositionForRight;
	//////////////
	return found;
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
				// Проверка допустимости
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
	// Поиск соседа
	for (int x1 = -1; x1 <= 1; x1++)
	{
		for (int y1 = -1; y1 <= 1; y1++)
		{

			if (abs(x1) != abs(y1))
			{
				// Проверка допустимости
				if ((((x + x1) >= 0) && ((y + y1) >= 0))
					&& ((x + x1) <= widthMap) && ((y + y1) < forest.size()))
				{
					if ((forest[y + y1][x + x1] == emptyChar))
					{
						// Проверка боковых значений
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


				// Поиск соседа
				/*
				for (int x1 = -1; x1 <= 1; x1++)
				{
					for (int y1 = -1; y1 <= 1; y1++)
					{

						/.*
											if (abs(x1) != abs(y1))
						{
							// Проверка допустимости
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
						// Проверка допустимости
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
			// +X+     X - не проходит проверку
			// X+X     + - проходит проверку
			if (abs(x1) != abs(y1))
			{
				// Проверка допустимости
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
