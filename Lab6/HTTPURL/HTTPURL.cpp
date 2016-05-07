#include "stdafx.h"
#include "HTTPURL.h"

using namespace std;

vector<string> SplitWords(string const& text)
{
	std::string trimmed = boost::trim_copy(text);

	vector<string> words;
	boost::split(words, trimmed, !boost::is_alnum(), boost::token_compress_on);
	return words;
}

CHttpUrl::CHttpUrl(Protocol protocol
	, std::string const& domain
	, std::string const& document
	, unsigned short port)
{
	SetProtocol(protocol);
	SetDomain(domain);
	SetDocument(document);
	SetPort(port);
}

CHttpUrl::CHttpUrl(const std::string  & url)
{
	boost::regex rules(PROTOCOL_RULE + PROTOCOL_DIVIDER + DOMAIN_RULE + PORT_RULE + DOCUMENT_RULE);
	boost::cmatch result;

	string checkingUrl = url;
	boost::algorithm::to_lower(checkingUrl);
	if (regex_match(checkingUrl.c_str(), result, rules))
	{
		ExtractAndRecordProtocol(result);
		ExtractAndRecordDomain(result);
		ExtractAndRecordPort(result);
		ExtractAndRecordDocument(result);
	}
	else
	{
		throw CUrlParsingError(MESSAGE_INCORRECT_URL);
	}
}


void CHttpUrl::ExtractAndRecordProtocol(const boost::cmatch & recogniteUrl)
{
	// TODO : exception for recogniteUrl[1]
	string protocolStr = string(recogniteUrl[1].first, recogniteUrl[1].second);
	boost::algorithm::to_lower(protocolStr);
	SetProtocol(protocolStr);
}


void CHttpUrl::ExtractAndRecordDomain(const boost::cmatch & recogniteUrl)
{
	SetDomain(string(recogniteUrl[2].first, recogniteUrl[2].second));
}


void CHttpUrl::ExtractAndRecordPort(const boost::cmatch & recogniteUrl)
{
	SetPort(string(recogniteUrl[3].first, recogniteUrl[3].second));
}


void CHttpUrl::ExtractAndRecordDocument(const boost::cmatch & recogniteUrl)
{
	SetDocument(string(recogniteUrl[4].first, recogniteUrl[4].second));
}


void CHttpUrl::JoinSlashToDocument()
{
	m_document.insert(m_document.begin(), '/');
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
		throw CUrlParsingError(MESSAGE_INCORRECT_PROTOCOL);
		break;
	}
	return std::string();// TODO delete
}


void CHttpUrl::SetDomain(const std::string & domain)
{
	//boost::regex rules(DOMAIN_RULE);
	//boost::cmatch result;

	vector<string> words = SplitWords(domain);

	if (words.size() == 2)//regex_match(domain.c_str(), result, rules)
	{
		m_domain = domain;
	}
	else
	{
		throw invalid_argument(MESSAGE_INCORRECT_DOMAIN);
	}
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}


void CHttpUrl::SetDocument(const std::string & document)
{
	m_document = document;

	if (m_document.size() > 0)
	{
		if (m_document[0] != '/')
		{
			JoinSlashToDocument();
		}
	}
	else
	{
		JoinSlashToDocument();
	}

	vector<string> words = SplitWords(m_document);

}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
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
		throw CUrlParsingError(MESSAGE_INCORRECT_PROTOCOL);
	}
}

void CHttpUrl::SetProtocol(Protocol proctocol)
{
	switch (proctocol)
	{
	case Protocol::HTTP:
	case Protocol::HTTPS:
		m_protocol = proctocol;
		break;
	default:
		throw invalid_argument(MESSAGE_INCORRECT_PROTOCOL);
		break;
	}
}

CHttpUrl::Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}


void CHttpUrl::SetPort(const std::string & port)
{
	try
	{
		if (port.size() > 0)
		{
			m_port = stoi(port);
		}

		if (m_port == 0)
		{
			m_port = static_cast<int>(m_protocol);
		}
	}
	catch (const std::invalid_argument & exception)
	{
		cout << MESSAGE_INCORRECT_PORT << endl;
	}
	catch (const std::out_of_range & exception)
	{
		cout << MESSAGE_INCORRECT_RANGE_VALUE_PORT << endl;
	}
}

void CHttpUrl::SetPort(unsigned int port)
{
	m_port = port;
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
	SetDomain(domain);
	SetDocument(document);
	SetPort(port);
}
