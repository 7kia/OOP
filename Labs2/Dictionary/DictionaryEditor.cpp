#include "stdafx.h"
#include "DictionaryEditor.h"

CDictionaryEditor::CDictionaryEditor(dictionary editDictionary)
{
	m_dictionary = editDictionary;
	m_state.reset(new CWaitTranslateWord(this));
	PrintInstruction();
	m_inputDictionaryIsEmpty = m_dictionary.empty();
}

void CDictionaryEditor::SetState(CApplicationState* state)
{
	m_state.reset(state);
}

void CDictionaryEditor::ProcessString(std::string inputString)
{
	m_state->ProcessString(inputString);
}

void CDictionaryEditor::SaveDictionaryInFile()
{
	std::fstream outputFile;
	std::string nameOutputFile;

	if (m_inputDictionaryIsEmpty)
	{
		nameOutputFile = DEFAULT_NAME_FILE;
	}
	else
	{
		nameOutputFile = m_fileName;
	}


	if (!outputFile.is_open())
	{
		throw std::ifstream::failure(MESSAGE_FAILED_OPEN + nameOutputFile + MESSAGE_FAILED_OPEN_FOR_WRITING);
	}

	for (const auto &element : m_dictionary)
	{
		outputFile << element.first + STRING_DIVIDER + element.second + '\n';
	}
}
