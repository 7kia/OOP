// Lab2-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <boost/range/algorithm/transform.hpp>

/*
2 лабораторная 1 задание
Вариант 2
Каждый элемент массива должен быть умножен на минимальный элемент исходного массива
*/


std::vector<double> ReadFromConsole()
{
	return { std::istream_iterator<double>(std::cin) , (std::istream_iterator<double>()) };
}

int main()
{	
	std::vector<double> vector;

	vector = ReadFromConsole();
	auto minValue = std::min_element(vector.begin(), vector.end());

	auto Multiply = [minValue](double source) {
		return source * *minValue;
	};

	boost::transform(vector, vector.begin(), Multiply);

    return 0;
}

