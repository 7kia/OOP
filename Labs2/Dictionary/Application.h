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

static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "������������ ���������� ����������! ������ ���� ";
static const std::string MESSAGE_FAILED_OPEN = "�� ������ ���� ";
static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " ��� ������!";
static const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " ��� ������!";
//static const std::string MESSAGE_INCORRECT_DATA = "File consist excess data!";

static const int AMOUNT_ARGUMENTS = 2;
static const std::string STRING_DIVIDER = ">>";
static const std::string STRING_FOR_EXIT = ".";
static const std::string STRING_FOR_SAVE = "s";

static const std::string MESSAGE_WAIT_WORD = "������� �����(�) � ��������� ��������� �������.";
static const std::string MESSAGE_INSTRUCTION = MESSAGE_WAIT_WORD +
												"��� ������ \"" + STRING_FOR_EXIT + "\".";
static const std::string MESSAGE_IGNORE_WORD_FIRST_PART = "����� ";
static const std::string MESSAGE_IGNORE_WORD_SECOND_PART = " ���������.";


static const std::string MESSAGE_EMPTY_DICTIONARY = "���� �� ������. ������� ����.";
static const std::string MESSAGE_UNKNOW_WORD = "����������� ����� \"";
static const std::string MESSAGE_WRITE_UNKNOW_WORD = "\". ������� ������� ��� ������ ������ ��� ������.";
static const std::string MESSAGE_SAVE_AS = " ��������� ��� ";


static const std::string MESSAGE_BEFORE_EXIT_FIRST_PART = "� ������� ���� ������� ���������.������� ";
static const std::string MESSAGE_BEFORE_EXIT_SECOND_PART = " ��� ���������� ����� �������.";
static const std::string MESSAGE_INCORRECT_INPUT = "�� ����� ������������ ��������. ��������� �������.";

static const std::string DEFAULT_NAME_FILE = "newDict.txt";
static const std::string DICTIONARY_SAVE_AS = "������� ����� ������� � ���� ";


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