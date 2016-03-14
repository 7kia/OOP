#pragma once

#include <string>

static const std::string STRING_FOR_EXIT = ".";
static const std::string STRING_FOR_SAVE = "s";

static const std::string MESSAGE_WAIT_WORDS = "Введите слово(а) и программа напечатет перевод.";
static const std::string MESSAGE_INSTRUCTION = MESSAGE_WAIT_WORDS +
												"Для выхода \"" + STRING_FOR_EXIT + "\".";
static const std::string MESSAGE_IGNORE_WORD_FIRST_PART = "Слово ";
static const std::string MESSAGE_IGNORE_WORD_SECOND_PART = " пропущено.";

static const std::string MESSAGE_EMPTY_DICTIONARY = "Файл не открыт. Словарь пуст.";
static const std::string MESSAGE_UNKNOW_WORD = "Неизвестное слово \"";
static const std::string MESSAGE_WRITE_UNKNOW_WORD = "\". Введите перевод или пустую строку для отказа.";
static const std::string MESSAGE_SAVE_AS = " сохранено как ";

static const std::string MESSAGE_BEFORE_EXIT_FIRST_PART = "В словарь были внесены изменения.Введите ";
static const std::string MESSAGE_BEFORE_EXIT_SECOND_PART = " для сохранения перед выходом.";
static const std::string MESSAGE_INCORRECT_INPUT = "Вы ввели неправильное значение. Повторите попытку.";

static const std::string DEFAULT_NAME_FILE = "newDict.txt";
static const std::string DICTIONARY_SAVE_AS = "Словарь будет сохранён в файл ";

class CDictionaryEditor;

class CDictionaryState
{
public:
	virtual void ProcessString(std::string inputString) = 0;
};

class CWaitTranslateWord : public CDictionaryState
{
public:
	CWaitTranslateWord(CDictionaryEditor *pEditor);
	void ProcessString(std::string inputString) override;
private:
	CDictionaryEditor *m_pEditor;

};

class CWaitTranslation : public CDictionaryState
{
public:
	CWaitTranslation(CDictionaryEditor *pEditor);
	void ProcessString(std::string inputString) override;;
private:
	CDictionaryEditor *m_pEditor;
};

class CBeforeExit : public CDictionaryState
{
public:
	CBeforeExit(CDictionaryEditor *pEditor);
	void ProcessString(std::string inputString) override;;
private:
	CDictionaryEditor *m_pEditor;
};

class CSaveDictionary : public CDictionaryState
{
public:
	CSaveDictionary(CDictionaryEditor *pEditor);

	void ProcessString(std::string inputString) override;;
private:
	CDictionaryEditor *m_pEditor;
};

class CExit : public CDictionaryState
{
public:
	CExit(CDictionaryEditor *pEditor);

	void ProcessString(std::string inputString) override;
};

void PrintMessageSuccessfullInsert(std::string word, std::string translation);
void PrintMessageAboutUnknowWord(std::string word);
void PrintMessageIgnoreWord(std::string word);
void PrintMessageBeforeExit();
void PrintMessageIncorectInput();
void PrintMessageDictionarySaveAs(bool useDefaultName, const std::string &nameFile);
void PrintStringToConsole(std::string &result);
