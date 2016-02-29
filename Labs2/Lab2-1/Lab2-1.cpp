// Lab2-1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <boost/range/algorithm/transform.hpp>

/*
2 ������������ 1 �������
������� 2
������ ������� ������� ������ ���� ������� �� ����������� ������� ��������� �������
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

