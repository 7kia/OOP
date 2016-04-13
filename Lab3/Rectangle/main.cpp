// Rectangle.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "main.h"
#include "Runner.h"

using namespace std;

void CheckArguments(int argc)
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
		CheckArguments(argc);

		const listArguments namesFiles = { argv[1], argv[2], argv[3], argv[4] };
		CRunner runner(namesFiles);

		runner.Run();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}

    return 0;
}

