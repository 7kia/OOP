// ParseURLTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tests.h"

using namespace std;



BOOST_AUTO_TEST_SUITE(EmptyStringList)

struct EmptyStringList_
{
	CStringList list;
};

BOOST_FIXTURE_TEST_SUITE(EmptyStringList, EmptyStringList_)


BOOST_AUTO_TEST_CASE(when_created_is_empty)
{	
	BOOST_CHECK_EQUAL(list.GetSize(), 0);
}

BOOST_AUTO_TEST_CASE(append_increase_one_to_size)
{
	list.Append("1");
	BOOST_CHECK_EQUAL(list.GetSize(), 1);
	list.Append("xcc");
	BOOST_CHECK_EQUAL(list.GetSize(), 2);
}

BOOST_AUTO_TEST_CASE(_)
{
	BOOST_CHECK(false);
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()




BOOST_AUTO_TEST_SUITE(StringList)

struct StringList_
{
};

BOOST_FIXTURE_TEST_SUITE(StringList, StringList_)


BOOST_AUTO_TEST_CASE(is_empty)
{
	BOOST_CHECK(false);
}


BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
