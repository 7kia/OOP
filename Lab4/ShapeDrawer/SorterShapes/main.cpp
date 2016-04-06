// SorterShapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "main.h"
#include "Runner.h"

using namespace std;

void CheckParametrs(int argc)
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}
}

int main(int argc, char *argv[])
{
	try
	{
		CheckParametrs(argc);
		CShapeReader application(argv[1], argv[2], argv[3]);

		application.Run();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}
	return 0;
}

