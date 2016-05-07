#pragma once

#include <boost/algorithm/string.hpp>
#include <boost/utility/string_ref.hpp>

#include "UrlParsingError.h"

class UrlRecognizer
{
public:
	std::vector<std::string>	RecognizeUrl(const std::string & url);

private:
	std::string			RecognizeProtocol(boost::string_ref & url);
	std::string			RecognizeDomain(boost::string_ref & url);
	std::string			RecognizeDocument(boost::string_ref & url);
	

	size_t				CheckEndProtocol(boost::string_ref & url);

	void				CheckContainsDotInDomain(boost::string_ref & url);
	size_t				CheckEndDomain(boost::string_ref & url);
	void				CheckCorrectnessDomainSymbols(boost::string_ref & url);

	void				CheckCorrectnessDocumentSymbols(boost::string_ref & url);
	void				AddSlashToStartDocument(boost::string_ref & document);
private:
	const std::string			HTTP_STRING_PRSENTATION = "http";
	const std::string			HTTPS_STRING_PRSENTATION = "https";

	const std::string			PROTOCOL_DIVIDER = "://";
	const std::string			DOMAIN_DIVIDER = "/";

};