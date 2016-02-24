#ifndef LAB_H
#define LAB_H

#pragma once
#include "stdafx.h"

#include <string>
#include <assert.h>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <vector>

struct point
{
	point();
	point(size_t first, size_t second);
	size_t x;
	size_t y;
};

enum class side
{
	Left,
	Right
};

enum class vertical
{
	Up,
	Down
};

typedef std::vector<std::string> bitmap;

struct CLabAaSD
{
	const char searchColor = '1';
	const char fillColor = '0';
	const char pointChar = '+';

};

void LoadBitmapFromFile(bitmap &bitmap, std::string nameFile);
void FillAreaInBitmap(bitmap &bitmap, char fill, int x, int y);
int AdditionWithCheckBorder(int source, int summand);
bool SearchInString(bitmap &bitmap, char fill, char replaceColor, point &returnPosition, side side);
void SearchOnVertical(bitmap &bitmap, char fill, char replaceColor, point leftReturnPosition, point rightReturnPosition, vertical direction);


#endif