#include "stdafx.h"
#include "Tests.h"

BOOST_FIXTURE_TEST_SUITE(TestIterator, StringListWithSeveralElement_)
	BOOST_AUTO_TEST_SUITE(operator_start)
		BOOST_AUTO_TEST_CASE(get_element)
		{
			CStringList::CIterator iter = list.begin();

			BOOST_CHECK_EQUAL(*iter, firstElelment);
		}
	BOOST_AUTO_TEST_SUITE_END()// operator_start

	BOOST_AUTO_TEST_SUITE(operator_arrow)
		BOOST_AUTO_TEST_CASE(get_element)
		{
			CStringList::CIterator iter = list.begin();

			BOOST_CHECK_EQUAL(iter->c_str(), firstElelment);
		}
	BOOST_AUTO_TEST_SUITE_END()// operator_arrow

	BOOST_AUTO_TEST_SUITE(operators_compare)
		BOOST_AUTO_TEST_CASE(equal)
		{
			CStringList::CIterator firstiIter = list.begin();
			CStringList::CIterator secondIter = list.begin();
			CStringList::CIterator thirdIter = list.end();
			BOOST_CHECK(firstiIter == secondIter);
			BOOST_CHECK(!(firstiIter == thirdIter));
		}
		BOOST_AUTO_TEST_CASE(not_equal)
		{
			CStringList::CIterator firstiIter = list.begin();
			CStringList::CIterator secondIter = ++list.begin();

			BOOST_CHECK(firstiIter != secondIter);
			BOOST_CHECK(!(firstiIter != list.begin()));
		}
	BOOST_AUTO_TEST_SUITE_END()// operator_start


	BOOST_AUTO_TEST_CASE(can_get_value_list_to_help_operator_star)
	{
		CStringList::CIterator iter = list.begin();

		BOOST_CHECK_EQUAL(*iter, firstElelment);
	}
	BOOST_AUTO_TEST_CASE(can_get_value_list_to_help_operator_arrow)
	{
		CStringList::CIterator iter = list.begin();

		BOOST_CHECK_EQUAL(iter->c_str(), firstElelment);
	}
	BOOST_AUTO_TEST_CASE(iterator_not_must_delete_element_on_which_have_refer_after_destroy)
	{
		BOOST_CHECK_NO_THROW(
			CStringList::CIterator iter1;
		{
			CStringList L2;
			L2.PushToStart("1");

			CStringList::CIterator iter2 = L2.begin();
			iter1 = iter2;
		}
		);
	}
	BOOST_AUTO_TEST_CASE(list_can_get_iterator_for_first_element)
	{
		CStringList::CIterator iter = list.begin();

		BOOST_CHECK_EQUAL(*iter, list.front());
		////////////////////////////////////////////
		// pattern
		auto patternIter = pattern.begin();
		BOOST_CHECK_EQUAL(*patternIter, list.front());

	}
	BOOST_AUTO_TEST_CASE(use_increment_iterator_can_get_reference_for_next)
	{
		CStringList::CIterator iter = list.begin();

		BOOST_CHECK_EQUAL(*(++iter), secondElelment);
		////////////////////////////////////////////
		// pattern
		auto patternIter = pattern.begin();
		BOOST_CHECK_EQUAL(*(++patternIter), secondElelment);
	}
	BOOST_AUTO_TEST_CASE(throw_exception_for_try_increment_iterator_have_reference_to_end)
	{
		CStringList::CIterator iter = list.end();

		BOOST_CHECK_THROW(++iter, std::runtime_error);
	}
	BOOST_AUTO_TEST_CASE(use_decrement_end_iterator_can_get_reference_for_last)
	{
		CStringList::CIterator iter = list.end();

		BOOST_CHECK_EQUAL(*(--iter), list.back());
		////////////////////////////////////////////
		// pattern
		auto patternIter = pattern.end();
		BOOST_CHECK_EQUAL(*(--patternIter), list.back());

	}
	BOOST_AUTO_TEST_CASE(throw_exception_for_try_decrement_iterator_have_reference_to_start)
	{
		CStringList::CIterator iter = list.begin();

		BOOST_CHECK_THROW(--iter, std::runtime_error);
	}

	BOOST_AUTO_TEST_SUITE(TestOperatorAssigned)
		BOOST_AUTO_TEST_CASE(can_assigned_empty_list)
		{
			list = CStringList();

			VerifyVectors(ConvertToVector(list), ConvertToVector(CStringList()));
		}
		BOOST_AUTO_TEST_CASE(can_assigned_not_empty_list)
		{
			CStringList secondList;
			secondList.PushToEnd("sda");
			secondList.PushToEnd("dfg");
			secondList.PushToEnd("qwesdf");

			list = secondList;

			VerifyVectors(ConvertToVector(list), ConvertToVector(secondList));
		}
		BOOST_AUTO_TEST_CASE(can_assigned_ownself_list)
	{
		list = list;
	}
	BOOST_AUTO_TEST_SUITE_END()// TestOperatorAssigned
BOOST_AUTO_TEST_SUITE_END()
