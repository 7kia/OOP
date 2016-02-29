// Lab2-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

std::vector<int> ReadFromConsole()
{
	return { std::istream_iterator<double>(std::cin) , (std::istream_iterator<double>()) };
}

int main()
{
	std::vector<int> vector;

	vector = ReadFromConsole();
    return 0;
}

