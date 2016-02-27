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
#include "Application.h"

using namespace std;

int main(int argc , char *argv[])
{
	try
	{
		RunProgram(argc, argv);
	}
	catch (invalid_argument const& err)
	{
		cout << err.what() << endl;
		return 1;
	}
	catch (underflow_error const& err)
	{
		cout << err.what() << endl;
		return 1;
	}
	catch (overflow_error const& err)
	{
		cout << err.what() << endl;
		return 1;
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