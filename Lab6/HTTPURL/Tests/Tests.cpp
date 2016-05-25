// ParseURLTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tests.h"

using namespace std;

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
	BOOST_CHECK_THROW(CHttpUrl("htFtps://github.com/7kia/OOP/"), CUrlParsingError);
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_domain)
{
	BOOST_CHECK_THROW(CHttpUrl("https://githubcom/7kia/OOP/"), invalid_argument);
};

BOOST_AUTO_TEST_CASE(document_must_not_consist_excess_slashs)
{
	BOOST_CHECK_THROW(CHttpUrl("https://github.com/7kia/OOP///"), invalid_argument);
};

BOOST_AUTO_TEST_CASE(document_must_not_consist_spece_symbols)
{
	BOOST_CHECK_THROW(CHttpUrl("https://github.com/7kia/OO  P/"), invalid_argument);
}

BOOST_AUTO_TEST_CASE(no_throw_exeption_for_empty_document)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("https://github.com/"));
	BOOST_REQUIRE_NO_THROW(CHttpUrl("https://github.com"));
}

BOOST_AUTO_TEST_CASE(no_throw_exeption_for_empty_document)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("https://github.com/"));
	BOOST_REQUIRE_NO_THROW(CHttpUrl("https://github.com"));
}

BOOST_AUTO_TEST_CASE(get_url_function_not_return_standart_port)
{
	string stringPresentationUrl = "https://github.com/";
	CHttpUrl url = CHttpUrl(stringPresentationUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), stringPresentationUrl);

	stringPresentationUrl = "http://github.com/";
	url = CHttpUrl(stringPresentationUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), stringPresentationUrl);
}


BOOST_AUTO_TEST_CASE(get_url_function_not_return_standart_port)
{
	string stringPresentationUrl = "https://github.com/";
	CHttpUrl url = CHttpUrl(stringPresentationUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), stringPresentationUrl);

	stringPresentationUrl = "http://github.com/";
	url = CHttpUrl(stringPresentationUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), stringPresentationUrl);
}
// TODO: add `http://localhost:8080/admin.php`
// TODO: add `https://yandex.ru/advanced/search/?q=Cats&lng=ru_RU`
// TODO: add invalid test `http://localhost:88888/admin.php`

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(AlternativeConstructorUrl)

struct componets_url_
{
	CHttpUrl::Protocol expectedProtocol = CHttpUrl::Protocol::HTTP;
	string expectedDomain = "github.com";
	string expectedDocument = "/7kia/index.html";
	unsigned short expectedPort = 80;

	SDataForCheck data;

	const string urlString = "http://" 
							+ expectedDomain
							+ RecognizableStrings::PORT_DIVIDER 
							+ to_string(expectedPort)
							+ expectedDocument;

	componets_url_()
	{
		data.protocol = CHttpUrl::Protocol::HTTP;
		data.domain = expectedDomain;
		data.document = expectedDocument;
		data.port = expectedPort;
	}
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

	BOOST_CHECK_EQUAL(url.GetURL(), urlString);
}

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_protocol)
{
	data.protocol = static_cast<CHttpUrl::Protocol>(10);

	BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};

BOOST_AUTO_TEST_CASE(throw_exeption_if_domain_not_consist_dot)
{
	data.domain = "githubcom";

	BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};

BOOST_AUTO_TEST_CASE(throw_exeption_if_domain_consist_space_symbols)
{
	data.domain = "github. com";

	BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};


BOOST_AUTO_TEST_CASE(throw_exeption_if_domain_consist_slashs)
{
	data.domain = "gi/thub.com";

	BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_document_which_consist_excess_slashs)
{
	data.document = "//7kia/index.html";

	BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};

BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_document_which_consist_spaces_symbols)
{
	data.document = "/7k i  a/index.html";

	BOOST_CHECK_THROW(TestAlternativeConstuctorUrl(data), invalid_argument);
};

BOOST_AUTO_TEST_CASE(no_throw_exeption_for_empty_document)
{
	data.document = "";

	BOOST_REQUIRE_NO_THROW(TestAlternativeConstuctorUrl(data));
};

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
