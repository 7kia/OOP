#include "stdafx.h"
#include "UrlRecognizer.h"

using namespace std;
using boost::string_ref;

vector<string> UrlRecognizer::RecognizeUrl(const string & url)
{
	vector<string> result;
	string_ref urlRef(url);

	result.push_back(RecognizeProtocol(urlRef));
	urlRef = urlRef.substr(result.back().size());

	result.push_back(RecognizeDomain(urlRef));
	urlRef = urlRef.substr(result.back().size());

	result.push_back(RecognizeDocument(urlRef));

	return result;
}

std::string UrlRecognizer::RecognizeProtocol(boost::string_ref & url)
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

size_t UrlRecognizer::CheckEndProtocol(boost::string_ref & url)
{
	size_t positionDivider = url.find(PROTOCOL_DIVIDER);

	if (positionDivider == string_ref::npos)
	{
		throw CUrlParsingError(MESSAGE_INCORRECT_PROTOCOL);
	}
	return positionDivider;
}


std::string UrlRecognizer::RecognizeDomain(boost::string_ref & url)
{
	CheckContainsDotInDomain(url);
	size_t positionDivider = CheckEndDomain(url);
	CheckCorrectnessDomainSymbols(url);

	return url.substr(0, positionDivider).to_string();
}

void UrlRecognizer::CheckContainsDotInDomain(boost::string_ref & url)
{
	size_t positionDivider = url.find('.');

	if (positionDivider == string_ref::npos)
	{
		throw CUrlParsingError(MESSAGE_INCORRECT_DOMAIN);
	}
}

size_t UrlRecognizer::CheckEndDomain(boost::string_ref & url)
{
	size_t positionDivider = url.find(DOMAIN_DIVIDER);

	if (positionDivider == string_ref::npos)
	{
		throw CUrlParsingError(MESSAGE_INCORRECT_DOMAIN);
	}
	return positionDivider;
}

void UrlRecognizer::CheckCorrectnessDomainSymbols(boost::string_ref & url)
{
	auto haveInvalideSymbols = [&](char ch)
	{
		return (isspace(ch) || (ch == '/') || (ch == '\''));
	};

	if (find_if(url.begin(), url.end(), haveInvalideSymbols) != url.end())
	{
		throw invalid_argument("Domain name must not contains any spaces, tabulations or slashes.");
	}
}


std::string UrlRecognizer::RecognizeDocument(boost::string_ref & url)
{
	CheckCorrectnessDocumentSymbols(url);

	string result = url.substr(0, url.size()).to_string();
	if (result[0] != '/')
	{
		return '/' + result;
	}

	return result;
}


void UrlRecognizer::CheckCorrectnessDocumentSymbols(boost::string_ref & url)
{
	auto notHaveSpace = [&](char ch)
	{
		return (isspace(ch));
	};

	if (find_if(url.begin(), url.end(), notHaveSpace) != url.end())
	{
		throw invalid_argument(MESSAGE_INCORRECT_DOCUMENT);
	}
}