#pragma once

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>

static const std::string MESSAGE_INCORRECT_URL = "Incorrect url.";


static const std::string MESSAGE_INCORRECT_PROTOCOL = "Incorrect protocol. Support ftp, http, https.";
static const std::string MESSAGE_INCORRECT_DOMAIN = "Incorrect domain. Domain like <word>.<word> .";
static const std::string MESSAGE_INCORRECT_DOCUMENT = "Incorrect document.";
static const std::string MESSAGE_INCORRECT_PORT = "Incorrect port. Will enter not number.";
static const std::string MESSAGE_INCORRECT_RANGE_VALUE_PORT = "Incorrect value port. It out of range.";

class CUrlParsingError : 
	public std::exception
{
public:
	CUrlParsingError(const std::string & message);
};
