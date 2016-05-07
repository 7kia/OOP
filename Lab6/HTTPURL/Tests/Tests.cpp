// ParseURLTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tests.h"

using namespace std;

bool TestStandartConstuctorUrl(const string & input)
{
	CHttpUrl url = CHttpUrl(input);

	return true;
}

bool TestAlternativeConstuctorUrl(SDataForCheck data)
{
	CHttpUrl url(data.protocol
				, data.domain
				, data.document
				, data.port);

	return true;
}

BOOST_AUTO_TEST_SUITE(StandartConstructorUrl)

struct componets_url_
{
	CHttpUrl::Protocol expectedProtocol = CHttpUrl::Protocol::HTTP;
	string expectedDomain = "github.com";
	string expectedDocument = "/7kia/index.html";
	unsigned short expectedPort = 80;

	const string urlString = "http://" + expectedDomain + expectedDocument;
};

BOOST_FIXTURE_TEST_SUITE(componets_url, componets_url_)


BOOST_AUTO_TEST_CASE(have_protocol)
{
	CHttpUrl url(urlString);
	BOOST_CHECK_EQUAL(url.GetPort(), expectedPort);
}

BOOST_AUTO_TEST_CASE(have_domain)
{
	CHttpUrl url(urlString);
	BOOST_CHECK_EQUAL(url.GetDomain(), expectedDomain);
}

BOOST_AUTO_TEST_CASE(have_document)
{
	CHttpUrl url(urlString);
	BOOST_CHECK_EQUAL(url.GetDocument(), expectedDocument);
}

BOOST_AUTO_TEST_CASE(have_port)
{
	CHttpUrl url(urlString);
	BOOST_CHECK_EQUAL(url.GetPort(), expectedPort);
}

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_protocol)
{
	BOOST_CHECK_THROW(TestStandartConstuctorUrl("htFtps://github.com/7kia/OOP/"), CUrlParsingError);
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_domain)
{
	BOOST_CHECK_THROW(TestStandartConstuctorUrl("htFtps://githubcom/7kia/OOP/"), CUrlParsingError);
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_document)
{
	BOOST_CHECK_THROW(TestStandartConstuctorUrl("htFtps://githubcom/7kia/OOP///"), CUrlParsingError);
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_port)
{
	BOOST_CHECK_THROW(TestStandartConstuctorUrl("https://github.com:fd/7kia/OOP/"), CUrlParsingError);
};

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(AlternativeConstructorUrl)

struct componets_url_
{
	CHttpUrl::Protocol expectedProtocol = CHttpUrl::Protocol::HTTP;
	string expectedDomain = "github.com";
	string expectedDocument = "/7kia/index.html";
	unsigned short expectedPort = 80;

	const string urlString = "http://" + expectedDomain + expectedDocument;

};

BOOST_FIXTURE_TEST_SUITE(componets_url, componets_url_)


BOOST_AUTO_TEST_CASE(check_correctness_alternative_constructor)
{
	CHttpUrl url(expectedProtocol
				, expectedDomain
				, expectedDocument
				, expectedPort);

	BOOST_CHECK_EQUAL(url.GetProtocol(), expectedProtocol);
	BOOST_CHECK_EQUAL(url.GetDomain(), expectedDomain);
	BOOST_CHECK_EQUAL(url.GetDocument(), expectedDocument);
	BOOST_CHECK_EQUAL(url.GetPort(), expectedPort);
}

// TODO : boost require << operator for CHttpUrl::Protocol
///*
BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_protocol)
{
	SDataForCheck data;

	data.protocol = static_cast<CHttpUrl::Protocol>(10);
	data.domain = expectedDomain;
	data.document = expectedDocument;
	data.port = expectedPort;

	
	/*
		boost::regex rules("([[:alpha:]|[:digit:]]+\.[[:alpha:]|[:digit:]]+)");//"([[:word:]]+)"
	boost::cmatch result;

	string checkingUrl = "gitc";
	boost::algorithm::to_lower(checkingUrl);
	BOOST_CHECK(regex_match(checkingUrl.c_str(), result, rules));
	if (regex_match(checkingUrl.c_str(), result, rules))
	{
		string checkingUrl2 = "git";
	}
	*/


	BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};
//*/


BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_domain)
{
	SDataForCheck data;

	data.protocol = CHttpUrl::Protocol::HTTP;
	data.domain = "githubcom";
	data.document = expectedDocument;
	data.port = expectedPort;

	BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_document)
{
	SDataForCheck data;

	data.protocol = CHttpUrl::Protocol::HTTP;
	data.domain = expectedDomain;
	data.document = "//7kia/index.html";
	data.port = expectedPort;

	//BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};

/*
BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_port)
{
	SDataForCheck data;

	data.protocol = CHttpUrl::Protocol::HTTP;
	data.domain = expectedDomain;
	data.document = expectedDocument;
	data.port = expectedPort;

	BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};
*/


BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
