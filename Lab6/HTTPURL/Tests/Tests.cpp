// ParseURLTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tests.h"

BOOST_AUTO_TEST_SUITE(ParseURLTests)

BOOST_AUTO_TEST_CASE(ParseURL_try1)
{	
	CHttpUrl url = CHttpUrl("https://github.com/7kia/OOP/");
	BOOST_CHECK_EQUAL(url.GetPort(), 443);
	BOOST_CHECK_EQUAL(url.GetDocument(), "7kia/OOP/");
};

BOOST_AUTO_TEST_CASE(ParseURL_try2)
{
	/*
		int port;
	Protocol protocol;
	std::string host;
	std::string document;
	BOOST_CHECK_EQUAL(ParseURL("https:/github.com/oMystique/OOP/", protocol, port, host, document), false);

	*/
};

BOOST_AUTO_TEST_CASE(ParseURL_try3)
{

	CHttpUrl url = CHttpUrl("HTTP://www.mysite.com/docs/document1.html?page=30&lang=en#title");
	
	BOOST_CHECK_EQUAL(url.GetPort(), 80);
	BOOST_CHECK_EQUAL(url.GetDocument(), "docs/document1.html?page=30&lang=en#title");
};

BOOST_AUTO_TEST_CASE(ParseURL_try4)
{
	CHttpUrl url = CHttpUrl("ftp://files.vk.com:2007/");

	BOOST_CHECK_EQUAL(url.GetPort(), 2007);
	BOOST_CHECK_EQUAL(url.GetDocument(), "");
};

BOOST_AUTO_TEST_SUITE_END()

