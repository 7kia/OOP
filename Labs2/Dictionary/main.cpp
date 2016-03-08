// Dictionary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Application.h"

using namespace std;

int main(int argc, char *argv[])
{
	try
	{
		//setlocale(LC_ALL, "Rus");
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		RunProgram(argc, argv);
	}
	catch (std::ifstream::failure const& err) {
		cout << err.what() << endl;
		return 1;
	}
	catch (exception const& err) {
		cout << err.what() << endl;
		return 1;
	}

	return 0;
}

