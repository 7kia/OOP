#include "stdafx.h"
#include "HTTPURL.h"

using namespace std;

vector<string> CHttpUrl::GetPartsUrl(string const& text)
{
	std::string trimmed = boost::trim_copy(text);

	vector<string> parts;

	size_t positionForRecognition = 0;
	parts.push_back(RecogniteProtocol(text, positionForRecognition));

	//boost::split(parts, trimmed, boost::is_space(), boost::token_compress_on);
	return parts;
}

string CHttpUrl::RecogniteProtocol(const string & text, size_t & position)
{

}

CHttpUrl::CHttpUrl(std::string const & url)
{
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
}

CHttpUrl::CHttpUrl(std::string const& domain
					, std::string const& document
					, Protocol protocol = Protocol::HTTP
					, unsigned short port = 80)
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
					, unsigned short port = 80)
{
	SetProtocol(protocol);
	m_domain = domain;
	m_document = document;
	m_port = port;
}
