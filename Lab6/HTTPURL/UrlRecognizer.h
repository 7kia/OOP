#pragma once

#include <boost/algorithm/string.hpp>
#include <boost/utility/string_ref.hpp>
#include <array>
#include "UrlParsingError.h"

namespace RecognizableStrings
{
	static const std::string			HTTP_STRING_PRSENTATION = "http";
	static const std::string			HTTPS_STRING_PRSENTATION = "https";

	static const std::string			PROTOCOL_DIVIDER = "://";
	static const std::string			PORT_DIVIDER = ":";

	static const std::string			DOMAIN_DIVIDER = "/";
}

class CUrlRecognizer
{
public:
	std::array<std::string, 3>	RecognizeUrl(const std::string & url);
protected:
	std::string			RecognizeProtocol(boost::string_ref & url);
	std::string			RecognizeDomain(boost::string_ref & url);
	std::string			RecognizeDocument(const boost::string_ref & url);

	void				CheckDividersInDocumnet(const boost::string_ref & document);
	

	size_t				CheckEndProtocol(boost::string_ref & url);

	void				CheckDomainCorrectness(const std::string & domain);
	void				CheckContainsDotInDomain(const boost::string_ref & url);
	size_t				CheckEndDomain(boost::string_ref & url);
	void				CheckCorrectnessDomainSymbols(const boost::string_ref & url);

	void				CheckDocumentCorrectness(const boost::string_ref & domain);
	void				CheckCorrectnessDocumentSymbols(const boost::string_ref & document);
	void				AddSlashToStartDocument(std::string & document);
};