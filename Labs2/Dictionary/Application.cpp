#include "stdafx.h"
#include "Application.h"

using namespace std;

void RunProgram(int argc, char * argv[])
{
	CheckParametrs(argc);

	CDictionaryEditor editor(argv[1]);

	string inputString;
	while (editor.GetState() != CDictionaryEditor::numberState::Exit)
	{
		getline(cin, inputString);
		editor.ProcessString(inputString);
	}

}

void CheckParametrs(int argc)
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}
}

void PrintStringToConsole(string &result)
{
	copy(result.begin(), result.end(), ostreambuf_iterator<char>(std::cout));
	cout << endl;
}
