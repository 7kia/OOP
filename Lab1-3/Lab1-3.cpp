// Lab1-3.cpp: определяет точку входа для консольного приложения.
//

/*
Лабораторная работа 1. 3 задание Вариант №2

Разработайте приложение invert.exe, выполняющее инвертирование 
матрицы 3*3, т.е. нахождение обратной матрицы  и выводящее 
коэффициенты результирующей матрицы в стандартный поток вывода.
Формат командной строки приложения

invert.exe<matrixfile1>
*/

#include "stdafx.h"
#include "CApplication.h"

int main(int argc , char *argv[])
{
	CApplication application(argc , argv);

	bool isError = !application.Run();

	if (isError)
	{
		return 1;
	}

	return 0;
}