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

typedef std::vector<std::string> bitmap;

struct CLabAaSD
{
	const char searchColor = '1';
	const char fillColor = '0';
	const char pointChar = '+';

};
#endif