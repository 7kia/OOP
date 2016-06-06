#include "stdafx.h"
#include "Tests.h"

using namespace std;

BOOST_FIXTURE_TEST_SUITE(TestReverseIterator, StringListWithSeveralElement_)
	BOOST_AUTO_TEST_CASE(use_decrement_reverse_iterator_can_get_first_element)
	{
		CStringList::CReverseIterator iter = list.rend();

		BOOST_CHECK_EQUAL(*(--iter), list.front());
		////////////////////////////////////////////
		// pattern
		auto patternIter = pattern.rend();
		BOOST_CHECK_EQUAL(*(--patternIter), list.front());
	}
	BOOST_AUTO_TEST_CASE(throw_exception_for_try_decrement_reverse_iterator_have_reference_to_end)
	{
		CStringList::CReverseIterator iter = list.rbegin();

		BOOST_CHECK_THROW(--iter, std::runtime_error);
	}
	BOOST_AUTO_TEST_CASE(use_increment_reverse_iterator_can_get_previous_element)
	{
		CStringList::CReverseIterator iter = list.rbegin();

		BOOST_CHECK_EQUAL(*(++iter), fourthElelment);
		////////////////////////////////////////////
		// pattern
		auto patternIter = pattern.rbegin();
		BOOST_CHECK_EQUAL(*(++patternIter), fourthElelment);
	}
	BOOST_AUTO_TEST_CASE(throw_exception_for_try_increment_reverse_iterator_have_reference_to_begin)
	{
		CStringList::CReverseIterator iter = list.rend();

		BOOST_CHECK_THROW(++iter, std::runtime_error);
	}
	BOOST_AUTO_TEST_CASE(use_reverse_iterator_can_get_reference_for_last)
{
	CStringList::CReverseIterator iter = list.rbegin();

	BOOST_CHECK_EQUAL(*iter, list.back());
	////////////////////////////////////////////
	// pattern
	auto patternIter = pattern.rbegin();
	BOOST_CHECK_EQUAL(*(patternIter), list.back());
}
BOOST_AUTO_TEST_SUITE_END()