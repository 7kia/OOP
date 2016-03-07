#include "stdafx.h"
#include "Application.h"

using namespace std;

void RunProgram(int argc, char * argv[])
{
	CheckParametrs(argc);
	
	dictionary dictionary = CreateDictionary(argv[1]);

	PrintInstruction();

	WorkWithDictionary(dictionary, argv[1]);

	system("PAUSE");
}


bool needSetExitState(std::string input)
{
	if (input == STRING_FOR_EXIT)
	{
		return true;
	}
	return false;
}


void CheckParametrs(int argc)
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}
}

dictionary CreateDictionary(const string & nameFile)
{
	ifstream inputFile;
	inputFile.exceptions(ifstream::badbit);
	inputFile.open(nameFile);
	if (!inputFile.is_open())
	{
		
		cout << MESSAGE_FAILED_OPEN + nameFile + MESSAGE_FAILED_OPEN_FOR_READING << endl;
		cout << MESSAGE_EMPTY_DICTIONARY << endl;
	}

	dictionary result;
	string inputString;
	while (std::getline(inputFile, inputString))
	{
		result.insert(ExtractElement(inputString));
	}

	return result;
}

pair<string, string> ExtractElement(const string& inputString)
{
	size_t indexFound = inputString.find(STRING_DIVIDER);

	string first = inputString.substr(0, indexFound);
	string second = inputString.substr(indexFound + 2);

	return pair<string, string>(first, second);
}


// TODO : redesing
void WorkWithDictionary(dictionary & dictionary, string fileName)
{
	string inputString;
	string unknowWord;
	stateApplication state = stateApplication::Wait_translate_word;
	bool inputDictionaryIsEmpty = dictionary.empty();

	while (state != stateApplication::Exit)
	{
		switch (state)
		{
		case stateApplication::Wait_translate_word:
			std::getline(cin, inputString);


			if (!inputString.empty())
			{
				if (needSetExitState(inputString))
				{
					state = stateApplication::Before_exit;
					continue;
				}

				auto foundElement = dictionary.find(inputString);

				if (foundElement != dictionary.end())
				{
					PrintStringToConsole(foundElement->second);
				}
				else
				{
					unknowWord = inputString;
					state = stateApplication::Wait_translation;
					PrintMessageAboutUnknowWord(unknowWord);
				}
			}
			break;
		case stateApplication::Wait_translation:
			std::getline(cin, inputString);

			if (!inputString.empty())
			{
				if (needSetExitState(inputString))
				{
					state = stateApplication::Before_exit;
					continue;
				}

				dictionary.insert({ unknowWord, inputString });

				state = stateApplication::Wait_translate_word;
				PrintMessageSuccessfullInsert(unknowWord, inputString);

			}
			else
			{
				state = stateApplication::Wait_translate_word;
				PrintMessageIgnoreWord(unknowWord);
			}
			break;
		case stateApplication::Before_exit:
			PrintMessageBeforeExit();

			std::getline(cin, inputString);

			if (!inputString.empty())
			{
				if (inputString == STRING_FOR_SAVE)
				{
					state = stateApplication::Save_dictionary;
				}
				else
				{
					PrintMessageIncorectInput();
				}
			}
			else
			{
				state = stateApplication::Exit;
			}
			break;
		case stateApplication::Save_dictionary:
			PrintMessageDictionarySaveAs(inputDictionaryIsEmpty, fileName);

			if (inputDictionaryIsEmpty)
			{
				SaveDictionaryInFile(dictionary, DEFAULT_NAME_FILE);
			}
			else
			{
				SaveDictionaryInFile(dictionary, fileName);
			}
			state = stateApplication::Exit;
			break;
		default:
			break;
		}
	}

}


void PrintStringToConsole(string &result)
{
	copy(result.begin(), result.end(), ostreambuf_iterator<char>(std::cout));
	cout << endl;
}

void SaveDictionaryInFile(const dictionary & dictionary, const std::string & nameFile)
{
	fstream outputFile(nameFile);
	if (!outputFile.is_open())
	{
		throw ifstream::failure(MESSAGE_FAILED_OPEN + nameFile + MESSAGE_FAILED_OPEN_FOR_WRITING);
	}

	for (const auto &element : dictionary)
	{
		outputFile << element.first + STRING_DIVIDER + element.second + '\n';
	}

}