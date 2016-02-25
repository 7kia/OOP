// Lab1-5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Lab.h"

int main()
{
	bitmap map;
	LoadBitmapFromFile(map, "map3.txt");

	FillAreaInBitmap(map, '+', 7, 5);// 1, 1);

	for (auto y : map)
	{
		for (auto x : y)
		{
			std::cout << x;
		}
		std::cout << std::endl;
	}

    return 0;
}

