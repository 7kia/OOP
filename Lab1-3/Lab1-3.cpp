// Lab1-3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

/*
������������ ������ 1. 3 ������� ������� �2

������������ ���������� invert.exe, ����������� �������������� 
������� 3*3, �.�. ���������� �������� �������  � ��������� 
������������ �������������� ������� � ����������� ����� ������.
������ ��������� ������ ����������

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