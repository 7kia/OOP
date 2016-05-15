// ParseURLTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tests.h"

using namespace std;


bool VerifyVectors(const vector<string> &first
				, const vector<string> &second)
{
	if (first.size() != second.size())
	{
		return false;
	}

	for (size_t index = 0; index < first.size(); index++)
	{
		BOOST_CHECK_EQUAL(first[index], second[index]);
	}
}

vector<string> ConvertToVector(CStringList & list)
{
	vector<string> result;

	for (auto &str : list)
	{
		result.push_back(str);
	}

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
	BOOST_CHECK_EQUAL(list.IsEmpty(), true);
}

BOOST_AUTO_TEST_CASE(when_created_have_zero_size)
{
	BOOST_CHECK_EQUAL(list.GetSize(), 0);
}

BOOST_AUTO_TEST_CASE(append_increase_one_to_size)
{
	list.PushToEnd("1");
	BOOST_CHECK_EQUAL(list.GetSize(), 1);
	list.PushToEnd("xcc");
	BOOST_CHECK_EQUAL(list.GetSize(), 2);

	//std::list<std::string> l;
	//l.push_back("s");
	//l.
}


BOOST_AUTO_TEST_CASE(start_and_end_list_from_one_element_refer_to_only)
{
	std::string addElelment = "OOP";
	list.PushToEnd(addElelment);

	BOOST_CHECK_EQUAL(list.front(), addElelment);
	BOOST_CHECK_EQUAL(list.back(), addElelment);
}

BOOST_AUTO_TEST_CASE(list_can_have_several_elemets)
{
	std::string firstElelment = "OOP";
	std::string secondElelment = "PPO";
	std::string thirdElelment = "MLaTA";

	list.PushToEnd(firstElelment);
	list.PushToEnd(secondElelment);
	list.PushToEnd(thirdElelment);

	BOOST_CHECK_EQUAL(list.front(), firstElelment);
	BOOST_CHECK_EQUAL(list.back(), thirdElelment);

	vector<string> expectedVector = { firstElelment, secondElelment, thirdElelment };
	VerifyVectors(ConvertToVector(list), expectedVector);
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

	///*
	StringListWithSeveralElement_()
	{
		list.PushToEnd(firstElelment);
		list.PushToEnd(secondElelment);
		list.PushToEnd(thirdElelment);

	}

	//*/
};

BOOST_FIXTURE_TEST_SUITE(StringListWithSeveralElement, StringListWithSeveralElement_)

BOOST_AUTO_TEST_CASE(can_add_element_to_start)
{
	std::string addString = "TM";

	list.PushToStart(addString);
	BOOST_CHECK_EQUAL(list.front(), addString);
}

BOOST_AUTO_TEST_CASE(can_add_element_to_end)
{
	std::string addString = "CV";

	list.PushToEnd(addString);
	BOOST_CHECK_EQUAL(list.back(), addString);
}

BOOST_AUTO_TEST_CASE(list_can_get_iterator_for_first_element)
{
	CStringList::CIterator iter = list.begin();
	
	BOOST_CHECK_EQUAL(*iter, list.front());
}

BOOST_AUTO_TEST_CASE(use_increment_iterator_can_get_reference_for_next)
{
	CStringList::CIterator iter = list.begin();

	BOOST_CHECK_EQUAL(*(++iter), secondElelment);
}

BOOST_AUTO_TEST_CASE(use_decrement_end_iterator_can_get_reference_for_last)
{
	CStringList::CIterator iter = list.end();

	BOOST_CHECK_EQUAL(*(--iter), list.back());
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
