// ParseURLTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tests.h"

bool TestIncrorrectUrl(const std::string & input)
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

