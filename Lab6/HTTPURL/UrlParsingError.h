#pragma once

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>

static const std::string MESSAGE_INCORRECT_URL = "Incorrect url.";


static const std::string MESSAGE_INCORRECT_PROTOCOL = "Incorrect protocol. Support ftp, http, https.";
static const std::string MESSAGE_NOT_FOUND_DOMAIN_DIVIDER = "Not found protocol divider.";
static const std::string MESSAGE_DOMAIN_NOT_CONSIST_DOT = "Incorrect domain. Domain must consist dot.";
static const std::string MESSAGE_DOMAIN_CONSIST_INVALID_SYMBOLS = "Domain name must not contains any spaces, tabulations or slashes.";

static const std::string MESSAGE_DOCUMENT_CONSIST_INVALID_SYMBOLS = "Document name must not contains any spaces, tabulations or slashes.";
static const std::string MESSAGE_DOCUMENT_CONSIST_EXCESS_SLASHS = "Document contains excess slashe(s).";

static const std::string MESSAGE_INCORRECT_PORT = "Incorrect port. Will enter not number.";
static const std::string MESSAGE_INCORRECT_RANGE_VALUE_PORT = "Incorrect value port. It out of range.";


class CUrlParsingError : 
	public std::exception
{
public:
	CUrlParsingError(const std::string & message);
};
