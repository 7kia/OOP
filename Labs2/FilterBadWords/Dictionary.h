#pragma once

#include "stdafx.h"
#include <boost/algorithm/string.hpp>

static const std::string STRING_DIVIDER = ">>";

static const std::string MESSAGE_FAILED_OPEN = "Не открыт файл ";
static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " для чтения!";

static const std::string MESSAGE_EMPTY_DICTIONARY =  "Файл не открыт. Словарь пуст.";

typedef std::set<std::string> dictionary;

dictionary CreateDictionary(const std::string &nameFile);
