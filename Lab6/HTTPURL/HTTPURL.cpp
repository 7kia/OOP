#include "stdafx.h"
#include "HTTPURL.h"

using namespace std;

vector<string> CHttpUrl::GetPartsUrl(string const& text)
{
	std::string trimmed = boost::trim_copy(text);

	vector<string> parts;

	size_t positionForRecognition = 0;
	parts.push_back(RecogniteProtocol(text, positionForRecognition));
	RecogniteDivederProtocol(text, positionForRecognition);
	//parts.push_back(RecogniteDivederProtocol(text, positionForRecognition));

	//boost::split(parts, trimmed, boost::is_space(), boost::token_compress_on);
	return parts;
}

string CHttpUrl::RecogniteProtocol(const string & text, size_t & position)
{
	std::string partProtocol = text.substr(position, HTTP_STRING_PRSENTATION.size());
	std::transform(partProtocol.begin(), partProtocol.end(), partProtocol.begin(), ::tolower);

	if (partProtocol == HTTP_STRING_PRSENTATION)
	{
		if (text[HTTPS_STRING_PRSENTATION.size() - 1] == HTTPS_STRING_PRSENTATION.back())
		{
			position += HTTPS_STRING_PRSENTATION.size();
			return HTTPS_STRING_PRSENTATION;
		}
		position += partProtocol.size();
		return partProtocol;
	}
	else
	{
		// TODO : exception
		//throw CUrlParsingError();
	}

	return string();
}

void CHttpUrl::RecogniteDivederProtocol(const string & text, size_t & position)
{

}


CHttpUrl::CHttpUrl(std::string const & url)
{
	/*
	vector<string> partsUrl = GetPartsUrl(url);

	if (partsUrl.size() == AMOUNT_PARTS_URL)
	{
		SetData(partsUrl[0]
				, partsUrl[1]
				, partsUrl[2]);

	}
	else
	{
		// TODO : exception
		//throw CUrlParsingError();
	}
	*/
	
	// TODO 3-4
	boost::regex rules(PROTOCOL_RULE + PROTOCOL_DIVIDER + "([^/ :]+):?([^/ ]*)" + DOCUMENT_RULE);
	boost::cmatch result;

	auto checkingUrl = url;
	boost::algorithm::to_lower(checkingUrl);

	if (regex_match(checkingUrl.c_str(), result, rules))
	{
		checkingUrl = url;
		auto protocolStr = string(result[1].first, result[1].second);
		boost::algorithm::to_lower(protocolStr);
		SetProtocol(protocolStr);

		string host = string(result[2].first, result[2].second);

		string portStr = string(result[3].first, result[3].second);
		m_port = atoi(portStr.c_str());
		if (m_port == 0)
		{
			m_port = static_cast<int>(m_protocol);
		}

		m_document = string(result[4].first, result[4].second);

	}
	else
	{
		// TODO : exception
		//throw CUrlParsingError();

	}
}

CHttpUrl::CHttpUrl(std::string const& domain
					, std::string const& document
					, Protocol protocol
					, unsigned short port)
	: m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
	, m_port(port)
{
}

std::string CHttpUrl::GetURL() const
{
	switch (m_protocol)
	{
	case Protocol::HTTP:
		return HTTP_STRING_PRSENTATION;
		break;
	case Protocol::HTTPS:
		return HTTPS_STRING_PRSENTATION;
		break;
	default:
		// TODO : exception
		//throw CUrlParsingError();
		break;
	}
	return std::string();
}

void CHttpUrl::SetProtocol(const std::string & protocol)
{
	if (protocol == HTTP_STRING_PRSENTATION)
	{
		m_protocol = Protocol::HTTP;
	}
	else if (protocol == HTTPS_STRING_PRSENTATION)
	{
		m_protocol = Protocol::HTTPS;
	}
	else
	{
		// TODO : exception
		//throw CUrlParsingError();
	}
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

CHttpUrl::Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

void CHttpUrl::SetData(const string & protocol
					, string const& domain
					, string const& document
					, unsigned short port)
{
	SetProtocol(protocol);
	m_domain = domain;
	m_document = document;
	m_port = port;
}
