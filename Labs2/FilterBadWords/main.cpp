// FilterBadWords.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "main.h"

using namespace std;

void PrintInstruction()
{
	cout << MESSAGE_WAIT_WORDS << endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	PrintInstruction();
	string inputString;
	getline(cin, inputString);

	dictionary badWords = CreateDictionary("bad.txt");

	string filterString = FilterBadWords(inputString, badWords);

	cout << filterString;

	return 0;
}

