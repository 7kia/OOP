#include "stdafx.h"
#include "UrlRecognizer.h"

using namespace std;
using boost::string_ref;

vector<string> CUrlRecognizer::RecognizeUrl(const string & url)
{
	vector<string> result;
	string_ref urlRef(url);

	result.push_back(RecognizeProtocol(urlRef));
	urlRef = urlRef.substr(result.back().size() + PROTOCOL_DIVIDER.size());

	result.push_back(RecognizeDomain(urlRef));
	urlRef = urlRef.substr(result.back().size());

	result.push_back(RecognizeDocument(urlRef));

	return result;
}

std::string CUrlRecognizer::RecognizeProtocol(boost::string_ref & url)
{
	size_t positionDivider = CheckEndProtocol(url);

	string result = url.substr(0, positionDivider).to_string();
	if ((result == HTTP_STRING_PRSENTATION) 
		|| (result == HTTPS_STRING_PRSENTATION))
	{
		return result;
	}
	else
	{
		throw CUrlParsingError(MESSAGE_INCORRECT_PROTOCOL);
	}
}

size_t CUrlRecognizer::CheckEndProtocol(boost::string_ref & url)
{
	size_t positionDivider = url.find(PROTOCOL_DIVIDER);

	if (positionDivider == string_ref::npos)
	{
		throw CUrlParsingError(MESSAGE_INCORRECT_PROTOCOL);
	}
	return positionDivider;
}


std::string CUrlRecognizer::RecognizeDomain(boost::string_ref & url)
{
	CheckContainsDotInDomain(url);
	size_t positionDivider = CheckEndDomain(url);

	string result = url.substr(0, positionDivider).to_string();
	CheckCorrectnessDomainSymbols(result);

	return result;
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
	size_t positionDivider = url.find(DOMAIN_DIVIDER);

	if (positionDivider == string_ref::npos)
	{
		return url.size();
	}

	return positionDivider;
}

void CUrlRecognizer::CheckCorrectnessDomainSymbols(const boost::string_ref & domain)
{
	auto haveInvalideSymbols = [&](char ch)
	{
		return (isspace(ch) || (ch == '/'));//|| (ch == '\''));
	};

	if (find_if(domain.begin(), domain.end(), haveInvalideSymbols) != domain.end())
	{
		throw invalid_argument(MESSAGE_DOMAIN_CONSIST_INVALID_SYMBOLS);
	}
}


std::string CUrlRecognizer::RecognizeDocument(boost::string_ref & url)
{
	string result = url.substr(0, url.size()).to_string();
	if (result.size() > 0)
	{
		CheckDividersInDocumnet(result);
		CheckCorrectnessDocumentSymbols(result);
		
	}
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
		positionDivider = referenceOnDocument.find(DOMAIN_DIVIDER);

		if ((position + 1) >= positionDivider)
		{
			throw invalid_argument(MESSAGE_DOCUMENT_CONSIST_EXCESS_SLASHS);
		}
		position = positionDivider + 1;
		referenceOnDocument = referenceOnDocument.substr(position);
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
