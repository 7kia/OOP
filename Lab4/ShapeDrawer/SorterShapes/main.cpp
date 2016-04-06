// SorterShapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Application.h"

using namespace std;

int main(int argc, char *argv[])
{
	try
	{
		CheckParametrs(argc);
		CShapeReader reader(argv[1]);

		reader.SortContent(argv[2], argv[3]);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}
	return 0;
}

