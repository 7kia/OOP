// ParseURLTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tests.h"

using namespace std;

bool TestIncrorrectUrl(const string & input)
{
	CHttpUrl url = CHttpUrl(input);

	return true;
}

BOOST_AUTO_TEST_SUITE(StandartConstructorUrl)

BOOST_AUTO_TEST_CASE(check_usual_event)
{	
	CHttpUrl url = CHttpUrl("https://github.com/7kia/OOP/");
	BOOST_CHECK_EQUAL(url.GetPort(), 443);
	BOOST_CHECK_EQUAL(url.GetDocument(), "7kia/oop/");
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_url)
{
	BOOST_CHECK_THROW(TestIncrorrectUrl("https:///github.com/7kia/OOP/"), CUrlParsingError);
};

BOOST_AUTO_TEST_CASE(check_correctness_document)
{
	CHttpUrl url = CHttpUrl("HTTP://www.TY.com/llvm/documeclangEngine");
	
	BOOST_CHECK_EQUAL(url.GetPort(), 80);
	BOOST_CHECK_EQUAL(url.GetDocument(), "/llvm/documeclangengine");
};

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(AlternativeConstructorUrl)

struct componets_url_
{
	CHttpUrl::Protocol expectedProtocol = CHttpUrl::Protocol::HTTP;
	string expectedDomain = "github.com";
	string expectedDocument = "/7kia/index.html";
	unsigned int expectedPort = 80;

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
	BOOST_CHECK_THROW(TestIncrorrectUrl("htFtps://github.com/7kia/OOP/"), CUrlParsingError);
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_domain)
{
	BOOST_CHECK_THROW(TestIncrorrectUrl("htFtps://githubcom/7kia/OOP/"), CUrlParsingError);
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_document)
{
	BOOST_CHECK_THROW(TestIncrorrectUrl("htFtps://githubcom/7kia/OOP///"), CUrlParsingError);
};


BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_port)
{
	BOOST_CHECK_THROW(TestIncrorrectUrl("https://github.com:fd/7kia/OOP/"), CUrlParsingError);
};

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
