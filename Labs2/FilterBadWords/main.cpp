// FilterBadWords.cpp: определяет точку входа для консольного приложения.
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
	system("chcp 1251");

	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	
	setlocale(LC_ALL, "ru_RU.UTF-8");
	//wstring inputString;
	//getline(wcin, inputString);

	dictionary badWords = CreateDictionary(L"bad.txt");

	wstring filterString = FilterBadWords(L"дщд дурак lol", badWords);

	wcout << filterString;

	return 0;
}

