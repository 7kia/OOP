// FilterBadWords.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "main.h"

using namespace std;

void PrintInstruction()
{
	wcout << MESSAGE_WAIT_WORDS << endl;
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	//setlocale(LC_ALL, "ru_RU.UTF-8");
	wstring inputString;
	getline(wcin, inputString);

	dictionary badWords = CreateDictionary(L"bad.txt");

	wstring filterString = FilterBadWords(L"��� ����� lol", badWords);

	wcout << filterString;

	return 0;
}

