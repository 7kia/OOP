// Lab2-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ProcessVector.h"

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

	ProcessVector(vector);

    return 0;
}

