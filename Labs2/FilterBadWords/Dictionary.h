#pragma once

#include "stdafx.h"
#include <boost/algorithm/string.hpp>

static const std::wstring STRING_DIVIDER = L">>";

static const std::wstring MESSAGE_FAILED_OPEN = L"Не открыт файл ";
static const std::wstring MESSAGE_FAILED_OPEN_FOR_READING = L" для чтения!";

static const std::wstring MESSAGE_EMPTY_DICTIONARY =  L"Файл не открыт. Словарь пуст.";

typedef std::set<std::wstring> dictionary;

dictionary CreateDictionary(const std::wstring &nameFile);
