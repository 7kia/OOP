// Lab1-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Application.h"

int main(int argc , char *argv[])
{
	boost::timer::cpu_timer timer;

	timer.start();

	if (!RunProgram(argc, argv))
	{
		return 1;
	}

	timer.stop();

	std::cout << boost::timer::format(timer.elapsed(), ROUNDING_NUMBER, "%u") << std::endl;

	return 0;
}

