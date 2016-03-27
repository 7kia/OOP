#include "stdafx.h"
#include "DictionaryEditor.h"

using namespace std;

CDictionaryEditor::CDictionaryEditor(const string &fileName)
{
	m_dictionary = CreateDictionary(fileName);

	m_numberState = numberState::Wait_translate_word;
	PrintInstruction();
	m_inputDictionaryIsEmpty = m_dictionary.empty();

	if (m_inputDictionaryIsEmpty)
	{
		m_fileName = DEFAULT_NAME_FILE;
	}
	else
	{
		m_fileName = fileName;
	}
}

CDictionaryEditor::~CDictionaryEditor()
{
}

void CDictionaryEditor::SetIdState(numberState state)
{
	m_numberState = state;
}

CDictionaryEditor::numberState CDictionaryEditor::GetIdState() const
{
	return m_numberState;
}

void CDictionaryEditor::ProcessString(std::string inputString)
{
	switch (GetState())
	{
	case CDictionaryEditor::numberState::Before_exit:
		StateBeforeExit::ProcessString(*this, inputString);

		if (GetState() == CDictionaryEditor::numberState::Save_dictionary)
		{
			SaveDictionaryInFile();
			SetIdState(CDictionaryEditor::numberState::Exit);
		}
		break;
	case CDictionaryEditor::numberState::Save_dictionary:
		PrintMessageDictionarySaveAs(m_inputDictionaryIsEmpty, m_fileName);

		SaveDictionaryInFile();
		SetIdState(CDictionaryEditor::numberState::Exit);
		break;
	case CDictionaryEditor::numberState::Wait_translate_word:
		StateWaitTranslateWord::ProcessString(*this, inputString);
		break;
	case CDictionaryEditor::numberState::Wait_translation:
		StateWaitTranslation::ProcessString(*this, inputString);
		break;
	case CDictionaryEditor::numberState::Exit:
		break;
	default:
		break;
	}
}

void CDictionaryEditor::SaveDictionaryInFile()
{
	ofstream outputFile;

	outputFile.open(m_fileName);

	if (!outputFile.is_open())
	{
		throw ifstream::failure(MESSAGE_FAILED_OPEN + m_fileName + MESSAGE_FAILED_OPEN_FOR_WRITING);
	}

	for (const auto &element : m_dictionary)
	{
		outputFile << element.first + STRING_DIVIDER + element.second + '\n';
	}
}

CDictionaryEditor::numberState CDictionaryEditor::GetState()
{
	return m_numberState;
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
		result.emplace(ExtractElement(inputString));
	}

	return result;
}

void SaveDictionaryInFile(const dictionary & dictionary, const string & nameFile)
{
	ofstream outputFile(nameFile);
	if (!outputFile.is_open())
	{
		throw ifstream::failure(MESSAGE_FAILED_OPEN + nameFile + MESSAGE_FAILED_OPEN_FOR_WRITING);
	}

	for (const auto &element : dictionary)
	{
		outputFile << element.first + STRING_DIVIDER + element.second + '\n';
	}

}