// HTMLDecode.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "HTMLDecoder.h"

using namespace std;

int main()
{
	string inputString;
	getline(cin, inputString);

	string decodeString = DoHtmlDecode(inputString);
	cout << decodeString << endl;

	return 0;
}

