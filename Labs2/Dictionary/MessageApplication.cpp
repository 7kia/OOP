#include "stdafx.h"
#include "DictionaryState.h"

using namespace std;

void PrintInstruction()
{
	cout << MESSAGE_INSTRUCTION << endl;
}

void PrintMessageIgnoreWord(std::string word)
{
	cout << MESSAGE_IGNORE_WORD_FIRST_PART << word << MESSAGE_IGNORE_WORD_SECOND_PART << endl;
}

void PrintMessageSuccessfullInsert(string word, string translation)
{
	cout << word << MESSAGE_SAVE_AS << translation << endl;
}

void PrintMessageAboutUnknowWord(std::string word)
{
	cout << MESSAGE_UNKNOW_WORD << word << MESSAGE_WRITE_UNKNOW_WORD << endl;
}

void PrintMessageBeforeExit()
{
	cout << MESSAGE_BEFORE_EXIT_FIRST_PART << STRING_FOR_SAVE << MESSAGE_BEFORE_EXIT_SECOND_PART << endl;
}

void PrintMessageIncorectInput()
{
	cout << MESSAGE_INCORRECT_INPUT << endl;
}

void PrintMessageDictionarySaveAs(bool useDefaultName, const std::string & nameFile)
{
	if (useDefaultName)
	{
		cout << DICTIONARY_SAVE_AS << DEFAULT_NAME_FILE << endl;
	}
	else
	{
		cout << DICTIONARY_SAVE_AS << nameFile << endl;
	}
}