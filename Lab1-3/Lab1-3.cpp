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