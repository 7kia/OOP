// Lab2-1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "ProcessVector.h"

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

	ProcessVector(vector);

    return 0;
}

