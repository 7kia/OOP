#pragma once

#include "Dictionary.h"
#include "ApplicationState.h"

static const std::string MESSAGE_FAILED_OPEN = "�� ������ ���� ";
static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " ��� ������!";
static const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " ��� ������!";

class CDictionaryEditor
{
public:
	enum class numberState
	{
		Wait_translate_word,
		Wait_translation,
		Before_exit,
		Save_dictionary,
		Exit
	};

	CDictionaryEditor(dictionary editDictionary);
	void SetState(CApplicationState* state);
	void ProcessString(std::string inputString);
	void SaveDictionaryInFile();
public:
	dictionary m_dictionary;

	std::unique_ptr<CApplicationState> m_state;
	numberState m_numberState;

	std::string m_unknowWord;
	std::string m_fileName;
	bool m_inputDictionaryIsEmpty;
};

void PrintInstruction();