#include "stdafx.h"
#include "UrlRecognizer.h"
#include <boost/range/algorithm.hpp>

using namespace std;
using boost::string_ref;

array<string, 3> CUrlRecognizer::RecognizeUrl(const string & url)
{
	array<string, 3> result;
	string_ref urlRef(url);

	result[0] = RecognizeProtocol(urlRef);
	urlRef = urlRef.substr(result[0].size() + RecognizableStrings::PROTOCOL_DIVIDER.size());

	result[1] = RecognizeDomain(urlRef);
	urlRef = urlRef.substr(result[1].size());

	result[2] = RecognizeDocument(urlRef);

	return result;
}

// TODO addd const
std::string CUrlRecognizer::RecognizeProtocol(boost::string_ref & url)
{
	size_t dividerPosition = CheckEndProtocol(url);

	string_ref result = url.substr(0, dividerPosition);
	if ((result == RecognizableStrings::HTTP_STRING_PRSENTATION)
		|| (result == RecognizableStrings::HTTPS_STRING_PRSENTATION))
	{
		return result.to_string();
	}
	else
	{
		throw CUrlParsingError(MESSAGE_INCORRECT_PROTOCOL);
	}
}

size_t CUrlRecognizer::CheckEndProtocol(boost::string_ref & url)
{
	size_t dividerPosition = url.find(RecognizableStrings::PROTOCOL_DIVIDER);

	if (dividerPosition == string_ref::npos)
	{
		throw CUrlParsingError(MESSAGE_INCORRECT_PROTOCOL);
	}
	return dividerPosition;
}


std::string CUrlRecognizer::RecognizeDomain(boost::string_ref & url)
{
	size_t positionDivider = CheckEndDomain(url);
	string result = url.substr(0, positionDivider).to_string();

	CheckDomainCorrectness(result);

	return result;
}


void CUrlRecognizer::CheckDomainCorrectness(const std::string & domain)
{
	CheckCorrectnessDomainSymbols(domain);
	CheckContainsDotInDomain(domain);
}

void CUrlRecognizer::CheckContainsDotInDomain(const boost::string_ref & url)
{
	size_t positionDivider = url.find('.');

	if (positionDivider == string_ref::npos)
	{
		throw invalid_argument(MESSAGE_DOMAIN_NOT_CONSIST_DOT);
	}
}

size_t CUrlRecognizer::CheckEndDomain(boost::string_ref & url)
{
	size_t positionDivider = url.find(RecognizableStrings::DOMAIN_DIVIDER);

	if (positionDivider == string_ref::npos)
	{
		return url.size();
	}

	return positionDivider;
}

void CUrlRecognizer::CheckCorrectnessDomainSymbols(const boost::string_ref & domain)
{
	auto isSymbolInvalid = [&](char ch)
	{
		return (iscntrl(ch) || isspace(ch) || (ch == '/'));//|| (ch == '\''));
	};

	if (find_if(domain, isSymbolInvalid) != domain.end())
	{
		throw invalid_argument(MESSAGE_DOMAIN_CONSIST_INVALID_SYMBOLS);
	}
}


std::string CUrlRecognizer::RecognizeDocument(const boost::string_ref & url)
{
	CheckDocumentCorrectness(url);

	string result = url.substr(0, url.size()).to_string();
	AddSlashToStartDocument(result);

	return result;
}

void CUrlRecognizer::CheckDividersInDocumnet(const boost::string_ref & document)
{
	size_t position = 1;
	size_t positionDivider = 0;

	string_ref referenceOnDocument = document.substr(position);

	while ((position < referenceOnDocument.size()) && (positionDivider <= referenceOnDocument.size()))
	{
		positionDivider = referenceOnDocument.find(RecognizableStrings::DOMAIN_DIVIDER);

		if ((position + 1) >= positionDivider)
		{
			throw invalid_argument(MESSAGE_DOCUMENT_CONSIST_EXCESS_SLASHS);
		}
		position = positionDivider + 1;
		referenceOnDocument = referenceOnDocument.substr(position);
	}
}

void CUrlRecognizer::CheckDocumentCorrectness(const boost::string_ref & document)
{
	if (document.size() > 0)
	{
		CheckDividersInDocumnet(document);
		CheckCorrectnessDocumentSymbols(document);
	}
}

void CUrlRecognizer::CheckCorrectnessDocumentSymbols(const boost::string_ref & document)
{
	auto notHaveSpace = [&](char ch)
	{
		return (isspace(ch));
	};

	if (find_if(document.begin(), document.end(), notHaveSpace) != document.end())
	{
		throw invalid_argument(MESSAGE_DOCUMENT_CONSIST_INVALID_SYMBOLS);
	}
}

void CUrlRecognizer::AddSlashToStartDocument(string & document)
{
	if (document.size() > 0)
	{
		if (document[0] != '/')
		{
			document.insert(document.begin(), '/');
		}
	}
	else
	{
		document = '/';
	}
}
