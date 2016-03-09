#include "stdafx.h"
#include "DictionaryEditor.h"

using namespace std;

CDictionaryEditor::CDictionaryEditor(const string &fileName)
{
	m_dictionary = CreateDictionary(fileName);
	m_fileName = fileName;
	//m_state.reset(new CWaitTranslateWord(this));
	m_state = new CWaitTranslateWord(this);
	PrintInstruction();
	m_inputDictionaryIsEmpty = m_dictionary.empty();
}

CDictionaryEditor::~CDictionaryEditor()
{
	delete m_state;
}

void CDictionaryEditor::SetState(CDictionaryState* state)
{
	//m_state.reset(state);
	//m_state.swap(unique_ptr<CApplicationState>(state));
	m_state = state;
}

void CDictionaryEditor::ProcessString(string inputString)
{
	m_state->ProcessString(inputString);
}

void CDictionaryEditor::SaveDictionaryInFile()
{
	fstream outputFile;
	string nameOutputFile;

	if (m_inputDictionaryIsEmpty)
	{
		nameOutputFile = DEFAULT_NAME_FILE;
	}
	else
	{
		nameOutputFile = m_fileName;
	}
	outputFile.open(nameOutputFile);

	if (!outputFile.is_open())
	{
		throw ifstream::failure(MESSAGE_FAILED_OPEN + nameOutputFile + MESSAGE_FAILED_OPEN_FOR_WRITING);
	}

	for (const auto &element : m_dictionary)
	{
		outputFile << element.first + STRING_DIVIDER + element.second + '\n';
	}
}

pair<string, string> ExtractElement(const string& inputString)
{
	size_t indexFound = inputString.find(STRING_DIVIDER);

	string first = inputString.substr(0, indexFound);
	string second = inputString.substr(indexFound + 2);

	return pair<string, string>(first, second);
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
	while (getline(inputFile, inputString))
	{
		result.insert(ExtractElement(inputString));
	}

	return result;
}

void SaveDictionaryInFile(const dictionary & dictionary, const string & nameFile)
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