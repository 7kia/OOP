// ExpandTemplate.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ExpandTemplate.h"

using namespace std;

int main()
{
	std::string inputString = "-AAABBCCCaCCABC+";;

	templates params;
	params["A"] = "[a]";
	params["AA"] = "[aa]";
	params["B"] = "[b]";
	params["BB"] = "[bb]";
	params["C"] = "[c]";
	params["CC"] = "[cc]";

	std::string expandString = ExpandTemplateForString(inputString, params);
	std::string rightString = "-[aa][a][bb][cc][c]a[cc][a][b][c]+";

	cout << expandString << endl;
	cout << rightString << endl;
    return 0;
}

