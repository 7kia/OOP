#pragma once

#include "Dictionary.h"

std::string FilterBadWords(std::string inputString, const dictionary & dictionary);

template <typename T>
bool IsBetween(const T& value, const T& lowerBound, const T& upperBound);
