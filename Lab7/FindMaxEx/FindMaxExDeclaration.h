#pragma once

#include <vector>
#include <functional>

bool FindMax(const std::vector<const char *> & array
			, char &maxValue
			, std::function<bool(const char, const char)> const& less);
