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
	static std::array<std::string, 3>	RecognizeUrl(const std::string & url);// TODO replace `recoginze` with `parse`
protected:
	static std::string					RecognizeProtocol(boost::string_ref & url);
	static std::string					RecognizeDomain(boost::string_ref & url);
	// return string because change input string
	static std::string					RecognizeDocument(const boost::string_ref & url);

	static void							CheckDividersInDocumnet(const boost::string_ref & document);
	

	static size_t						CheckEndProtocol(boost::string_ref & url);

	static void							CheckDomainCorrectness(const std::string & domain);
	static void							CheckContainsDotInDomain(const boost::string_ref & url);
	static size_t						CheckEndDomain(boost::string_ref & url);
	static void							CheckCorrectnessDomainSymbols(const boost::string_ref & url);

	static void							CheckDocumentCorrectness(const boost::string_ref & domain);
	static void							CheckCorrectnessDocumentSymbols(const boost::string_ref & document);
	static void							AddSlashToStartDocument(std::string & document);
};