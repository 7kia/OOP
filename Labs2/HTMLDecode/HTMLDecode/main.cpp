// HTMLDecode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HTMLDecoder.h"

using namespace std;

void PrintStringToConsole(std::string &result)
{
	std::copy(result.begin(), result.end(), std::ostreambuf_iterator<char>(std::cout));
}

int main()
{
	string inputString;
	getline(cin, inputString);

	string decodeString = DoHtmlDecode(inputString);
	PrintStringToConsole(decodeString);

	return 0;
}

