// Lab1-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CApplication.h"

static const int ROUNDING_NUMBER = 5;

int main(int argc , char *argv[])
{

	boost::timer::cpu_timer timer;

	timer.start();

	if (!ReplaceSubstringInFile())
	{
		return 1;
	}

	timer.stop();

	std::cout << boost::timer::format(timer.elapsed(), ROUNDING_NUMBER, "%u") << std::endl;

	return 0;
}

