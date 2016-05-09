﻿#include "stdafx.h"
#include "HTTPURL.h"

using namespace std;
using namespace boost;

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
	array<string, 3> partsUrl = RecognizeUrl(url);

	SetData(partsUrl[0]
			, partsUrl[1]
			, partsUrl[2]);
}

void CHttpUrl::SetData(const string & protocol// TODO : correctness
	, string const& domain
	, string const& document
	, unsigned short port)
{
	SetProtocol(protocol);
	SetDomain(domain);
	SetDocument(document);
	SetPort(port);
}


std::string CHttpUrl::GetURL() const
{
	return GetStringPresentationProtocol() + m_domain + m_document;// TODO delete
}


void CHttpUrl::SetDomain(const std::string & domain)
{
	CheckDomainCorrectness(domain);
	m_domain = domain;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}


void CHttpUrl::SetDocument(const std::string & document)
{
	CheckDocumentCorrectness(document);
	m_document = document;
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
		throw invalid_argument(MESSAGE_INCORRECT_PROTOCOL);
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

string CHttpUrl::GetStringPresentationProtocol() const
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
		throw invalid_argument(MESSAGE_INCORRECT_PROTOCOL);
		break;
	}
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
