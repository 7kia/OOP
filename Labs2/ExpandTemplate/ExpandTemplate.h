#pragma once

#include "stdafx.h"
#include <boost/algorithm/string.hpp>

typedef std::map<std::string, std::string> templates;

std::string ExpandTemplateForString(std::string inputString, templates const &params);