// Lab1-5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Lab.h"

int main()
{
	bitmap map;
	LoadBitmapFromFile(map, "map.txt", ' ', 5, 7);


    return 0;
}

