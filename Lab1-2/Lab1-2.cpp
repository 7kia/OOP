// Lab1-2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

/*
������������ ������ 1. 2 ������� 7 �������

������������ ��������� radix.exe, ����������� ������� ����� ��
����� ������������ ������� ��������� � ������ ������������ � 
������ ���������� � ����������� ����� ������. ��� ������������
�������� ��������� ���������� ������� � ���������� �� 2 �� 36. 
������� ��������� � 11-������ �� 36-������ ������ ������������
��������� ����� ���������� �������� �� A �� Z ��� �������������
�������� � 1110�� 3510. �������������������������������:

radix.exe <source notation><destination notation><value>

��������, ��������� �������� ��������� ������ ������������
������� ������������������ ����� 1F � ��� ���������� �������������:
radix.exe 16 10 1F

� ����� ������, ��������� � ����������� ����� ������������ 
������������� ��� \n.

��������� ������ ���� �������� ������������ ������� ���
�������������, ��� � ������������� �����, � ����� ����. ������ 
�������� ������� �������� ������������ � ����������� ����� 
����� �� ������ ��������� (��� ������ ����������������� 
���������).
*/
#include "stdafx.h"
#include "CApplication.h"

using namespace std;

int main(int argc , char *argv[])
{
	try
	{
		CheckParametrs(argc, argv);
		//CheckNotations(argv[1], argv[2]);

		int numberInputNotation = stoi(argv[1]);//"16");//
		int numberOutputNotation = stoi(argv[2]);//"10");//
		CheckNotations(numberInputNotation, numberOutputNotation);
		cout << numberInputNotation << endl;
		cout << numberOutputNotation << endl;


		string inputNumber = argv[3];//"-FFFFFFFFF";//

		int valueInputNumber = TranslateStringToNumber(inputNumber, numberInputNotation);
		std::string outputNumber = TranslateIntToString(valueInputNumber, numberOutputNotation);

		std::cout << MESSAGE_RESULT << outputNumber << std::endl;
		std::cout << MESSAGE_DECIMAL_NOTATION << valueInputNumber << std::endl;
	}
	catch (invalid_argument const& err)
	{
		cout << err.what() << endl;
		return 1;
	}
	catch (underflow_error const& err)// TODO remove
	{
		cout << err.what() << endl;
		return 1;
	}
	catch (overflow_error const& err)
	{
		cout << err.what() << endl;
		return 1;
	}

	return 0;
}