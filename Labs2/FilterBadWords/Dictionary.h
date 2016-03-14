#pragma once

#include "stdafx.h"
#include <boost/algorithm/string.hpp>

static const std::string STRING_DIVIDER = ">>";

static const std::string MESSAGE_FAILED_OPEN = "�� ������ ���� ";
static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " ��� ������!";

static const std::string MESSAGE_EMPTY_DICTIONARY =  "���� �� ������. ������� ����.";

typedef std::set<std::string> dictionary;

dictionary CreateDictionary(const std::string &nameFile);
