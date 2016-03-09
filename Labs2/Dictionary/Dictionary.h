#pragma once

#include "stdafx.h"
#include <boost/algorithm/string.hpp>

static const std::string STRING_DIVIDER = ">>";

typedef std::map<std::string, std::string> dictionary;

std::pair<std::string, std::string> ExtractElement(const std::string& inputString);
dictionary CreateDictionary(const std::string &nameFile);
void SaveDictionaryInFile(const dictionary& dictionary, const std::string &nameFile);
