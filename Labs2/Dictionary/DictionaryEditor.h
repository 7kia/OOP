#pragma once

#include "Dictionary.h"
#include "DictionaryState.h"

static const std::string MESSAGE_FAILED_OPEN = "Не открыт файл ";
static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " для чтения!";
static const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " для записи!";

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

	CDictionaryEditor(const std::string &fileName);
	~CDictionaryEditor();

	void SetState(CDictionaryState* state);
	void ProcessString(std::string inputString);
	void SaveDictionaryInFile();

	numberState GetState();
public:
	dictionary m_dictionary;

	//std::unique_ptr<CApplicationState> m_state;
	CDictionaryState* m_state;
	numberState m_numberState;

	std::string m_unknowWord;
	std::string m_fileName;
	bool m_inputDictionaryIsEmpty;// need for message
};

void PrintInstruction();