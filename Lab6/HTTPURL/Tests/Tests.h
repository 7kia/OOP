#pragma once

#include "../HTTPURL.h"
#include "../UrlParsingError.h"

struct SDataForCheck
{
	CHttpUrl::Protocol protocol;
	std::string  domain;
	std::string document;
	unsigned short port;
};