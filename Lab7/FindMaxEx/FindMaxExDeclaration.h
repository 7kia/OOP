#pragma once

#include <vector>

/*
template <typename T, typename Less = std::less<T>>
bool FindMax(std::vector<T> const& array
			, T &maxValue
			, Less const& less = Less());
*/

bool FindMax(const std::vector<std::string> & array
	, char &maxValue
	, std::function<bool(const char, const char)> const& less);

