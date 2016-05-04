#include "stdafx.h"
#include "UrlParsingError.h"


CUrlParsingError::CUrlParsingError(const std::string & message)
	: std::exception(message.c_str())
{
}
