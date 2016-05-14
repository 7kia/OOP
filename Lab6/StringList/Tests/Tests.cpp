// ParseURLTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tests.h"

using namespace std;


std::vector<std::string> ConvertToVector(const CStringList & list)
{
	std::vector<std::string> result;

	// TODO : rewrite with using iterators

	return result;
}


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


BOOST_AUTO_TEST_CASE(start_and_end_list_from_one_element_refer_to_only)
{
	std::string addElelment = "OOP";
	list.Append(addElelment);

	BOOST_CHECK_EQUAL(list.GetStartElement(), addElelment);
	BOOST_CHECK_EQUAL(list.back(), addElelment);
}

BOOST_AUTO_TEST_CASE(list_can_have_several_elemets)
{
	std::string firstElelment = "OOP";
	std::string secondElelment = "PPO";
	std::string thirdElelment = "MLaTA";

	list.Append(firstElelment);
	list.Append(secondElelment);
	list.Append(thirdElelment);

	BOOST_CHECK_EQUAL(list.GetStartElement(), firstElelment);
	BOOST_CHECK_EQUAL(list.back(), thirdElelment);
}

/*
BOOST_AUTO_TEST_CASE(_)
{
	BOOST_CHECK(false);
}
*/


BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()




BOOST_AUTO_TEST_SUITE(StringListWithSeveralElement)

struct StringListWithSeveralElement_
{
	std::string firstElelment = "OOP";
	std::string secondElelment = "PPO";
	std::string thirdElelment = "MLaTA";

	CStringList list;

	/*
		StringListWithSeveralElement_()
	{
		list.Append(firstElelment);
		list.Append(secondElelment);
		list.Append(thirdElelment);

	}

	*/
};

BOOST_FIXTURE_TEST_SUITE(StringListWithSeveralElement, StringListWithSeveralElement_)





BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
