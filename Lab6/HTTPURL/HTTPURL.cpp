#include "stdafx.h"
#include "HTTPURL.h"

using namespace std;

void CHttpUrl::RecogniteDivederProtocol(const string & text, size_t & position)
{

}




CHttpUrl::CHttpUrl(const std::string  & url)
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
	boost::regex rules(PROTOCOL_RULE + PROTOCOL_DIVIDER + DOMAIN_RULE + PORT_RULE + DOCUMENT_RULE);
	boost::cmatch result;

	string checkingUrl = url;
	boost::algorithm::to_lower(checkingUrl);

	if (regex_match(checkingUrl.c_str(), result, rules))
	{
		RecordProtocol(result);
		RecordDomain(result);
		RecordPort(result);
		RecordDocument(result);
	}
	else
	{
		throw CUrlParsingError(MESSAGE_INCORRECT_URL);
	}
}


void CHttpUrl::RecordProtocol(const boost::cmatch & recogniteUrl)
{
	// TODO : exception for recogniteUrl[1]
	string protocolStr = string(recogniteUrl[1].first, recogniteUrl[1].second);
	boost::algorithm::to_lower(protocolStr);
	SetProtocol(protocolStr);
}


void CHttpUrl::RecordDomain(const boost::cmatch & recogniteUrl)
{
	// TODO : exception for recogniteUrl[2]
	m_domain = string(recogniteUrl[2].first, recogniteUrl[2].second);
}


void CHttpUrl::RecordPort(const boost::cmatch & recogniteUrl)
{
	try
	{
		// TODO : exception  for recogniteUrl[1]
		string portStr = string(recogniteUrl[3].first, recogniteUrl[3].second);
		if (portStr.size() > 0)
		{
			m_port = stoi(portStr);
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


void CHttpUrl::RecordDocument(const boost::cmatch & recogniteUrl)
{
	// TODO : exception for recogniteUrl[4]
	m_document = string(recogniteUrl[4].first, recogniteUrl[4].second);

	if (m_document.size() > 0)
	{
		if (m_document[0] != '/')
		{
			JoinSlashToDomain();
		}
	}
	else
	{
		JoinSlashToDomain();
	}
}


void CHttpUrl::JoinSlashToDomain()
{
	m_document.insert(m_document.begin(), '/');
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
		throw CUrlParsingError(MESSAGE_INCORRECT_PROTOCOL);
		break;
	}
	return std::string();// TODO delete
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
