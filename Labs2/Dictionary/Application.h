#pragma once

#include <string>

//#include "Dictionary.h"
#include "DictionaryEditor.h"

static const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Неправильное количество аргументов! Должно быть ";

static const int AMOUNT_ARGUMENTS = 2;

void RunProgram(int argc, char * argv[]);
void CheckParametrs(int argc);

bool needSetExitState(std::string input);