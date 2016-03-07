#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>

#include "Dictionary.h"

enum class stateApplication
{
	Wait_translate_word		,
	Wait_translation		,
	Before_exit				,
	Save_dictionary			,
	Exit

};

static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Неправильное количество аргументов! Должно быть ";
static const std::string MESSAGE_FAILED_OPEN = "Не открыт файл ";
static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " для чтения!";
static const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " для записи!";
//static const std::string MESSAGE_INCORRECT_DATA = "File consist excess data!";

static const int AMOUNT_ARGUMENTS = 2;
static const std::string STRING_DIVIDER = ">>";
static const std::string STRING_FOR_EXIT = ".";
static const std::string STRING_FOR_SAVE = "s";

static const std::string MESSAGE_WAIT_WORD = "Введите слово(а) и программа напечатет перевод.";
static const std::string MESSAGE_INSTRUCTION = MESSAGE_WAIT_WORD +
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


void RunProgram(int argc, char * argv[]);
void CheckParametrs(int argc);

void PrintInstruction();
void PrintMessageSuccessfullInsert(std::string word, std::string translation);
void PrintMessageAboutUnknowWord(std::string word);
void PrintMessageIgnoreWord(std::string word);
void PrintMessageBeforeExit();
void PrintMessageIncorectInput();
void PrintMessageDictionarySaveAs(bool useDefaultName, const std::string &nameFile);
void PrintStringToConsole(std::string &result);

dictionary CreateDictionary(const std::string &nameFile);
void SaveDictionaryInFile(const dictionary& dictionary, const std::string &nameFile);

bool needSetExitState(std::string input);
void WorkWithDictionary(dictionary &dictionary, std::string fileName);
std::pair<std::string, std::string> ExtractElement(const std::string& inputString);