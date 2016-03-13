#pragma once

#include "stdafx.h"
#include <boost/algorithm/string.hpp>

static const std::wstring STRING_DIVIDER = L">>";

static const std::wstring MESSAGE_FAILED_OPEN = L"�� ������ ���� ";
static const std::wstring MESSAGE_FAILED_OPEN_FOR_READING = L" ��� ������!";

static const std::wstring MESSAGE_EMPTY_DICTIONARY =  L"���� �� ������. ������� ����.";

typedef std::set<std::wstring> dictionary;

dictionary CreateDictionary(const std::wstring &nameFile);
