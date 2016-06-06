#include "stdafx.h"
#include "Tests.h"

BOOST_AUTO_TEST_SUITE(StringListWithSeveralElement)

BOOST_FIXTURE_TEST_SUITE(StringListWithSeveralElement, StringListWithSeveralElement_)
	BOOST_AUTO_TEST_CASE(can_add_element_to_start)
	{
		std::string addString = "TM";

		list.PushToStart(addString);
		BOOST_CHECK_EQUAL(list.front(), addString);
		////////////////////////////////////////////
		// pattern
		pattern.push_front(addString);
		BOOST_CHECK_EQUAL(pattern.front(), addString);
	}
	BOOST_AUTO_TEST_CASE(can_add_element_to_end)
{
	std::string addString = "CV";

	list.PushToEnd(addString);
	BOOST_CHECK_EQUAL(list.back(), addString);
	////////////////////////////////////////////
	// pattern
	pattern.push_back(addString);
	BOOST_CHECK_EQUAL(pattern.back(), addString);
}

	BOOST_AUTO_TEST_SUITE(TestInsert)
		BOOST_AUTO_TEST_CASE(after_insert_increase_size)
		{
			CStringList::CIterator iter = list.begin();
			std::string addString = "ethic";

			list.Insert(iter, addString);
			BOOST_CHECK_EQUAL(list.GetSize(), expectedSize + 1);
		}
		BOOST_AUTO_TEST_CASE(can_insert_in_start)
		{
			CStringList::CIterator iter = list.begin();
			std::string addString = "ethic";

			list.Insert(iter, addString);
			BOOST_CHECK_EQUAL(*(--iter), addString);
			////////////////////////////////////////////
			// pattern
			auto patternIter = pattern.begin();
			pattern.insert(patternIter, addString);
			BOOST_CHECK_EQUAL(*(--patternIter), addString);
		}
		BOOST_AUTO_TEST_CASE(can_insert_in_middle)
		{
			CStringList::CIterator iter = list.begin();
			std::string addString = "Fire";

			++iter;
			++iter;

			list.Insert(iter, addString);
			BOOST_CHECK_EQUAL(*(--iter), addString);
			////////////////////////////////////////////
			// pattern
			auto patternIter = pattern.begin();

			++patternIter;
			++patternIter;

			pattern.insert(patternIter, addString);
			BOOST_CHECK_EQUAL(*(--patternIter), addString);

		}
		BOOST_AUTO_TEST_CASE(can_insert_in_end)
		{
			CStringList::CIterator iter = list.end();
			std::string addString = "Memory";

			list.Insert(--iter, addString);
			BOOST_CHECK_EQUAL(*(--iter), addString);
			////////////////////////////////////////////
			// pattern
			auto patternIter = pattern.end();
			pattern.insert(--patternIter, addString);
			BOOST_CHECK_EQUAL(*(--patternIter), addString);
		}
	BOOST_AUTO_TEST_SUITE_END()// TestInsert

	BOOST_AUTO_TEST_SUITE(TestRemove)
		BOOST_AUTO_TEST_CASE(after_remove_decrease_size)
		{
			CStringList::CIterator iter = list.begin();

			list.Erase(iter);
			BOOST_CHECK_EQUAL(list.GetSize(), expectedSize - 1);
		}
		BOOST_AUTO_TEST_CASE(can_insert_in_start)
		{
			CStringList::CIterator iter = list.begin();

			list.Erase(iter);
			BOOST_CHECK_EQUAL(*(list.begin()), secondElelment);
			////////////////////////////////////////////
			// pattern
			auto patternIter = pattern.begin();
			pattern.erase(patternIter);
			BOOST_CHECK_EQUAL(*(pattern.begin()), secondElelment);
		}
		BOOST_AUTO_TEST_CASE(can_insert_in_middle)
		{
			CStringList::CIterator iter = list.begin();

			++iter;
			++iter;
			list.Erase(iter);

			iter = list.begin();
			++iter;
			++iter;
			BOOST_CHECK_EQUAL(*(iter), fourthElelment);
			////////////////////////////////////////////
			// pattern
			auto patternIter = pattern.begin();

			++patternIter;
			++patternIter;

			pattern.remove(*patternIter);

			patternIter = pattern.begin();

			++patternIter;
			++patternIter;
			BOOST_CHECK_EQUAL(*(patternIter), fourthElelment);
		}
		BOOST_AUTO_TEST_CASE(can_insert_in_end)
		{
			CStringList::CIterator iter = list.end();
			list.Erase(--iter);

			iter = list.end();
			BOOST_CHECK_EQUAL(*(--iter), fourthElelment);
			////////////////////////////////////////////
			// pattern
			auto patternIter = pattern.end();
			pattern.erase(--patternIter);

			patternIter = pattern.end();
			BOOST_CHECK_EQUAL(*(--patternIter), fourthElelment);
		}
	BOOST_AUTO_TEST_SUITE_END()// TestRemove

		

	BOOST_AUTO_TEST_SUITE(ConstructCopy)
		BOOST_AUTO_TEST_CASE(can_assigned_not_empty_list)
		{
			CStringList secondList;

			secondList = list;

			list.Erase(secondList.begin());

			BOOST_CHECK(list.front() != secondList.front());
		}
	BOOST_AUTO_TEST_SUITE_END()// TestReverseIterator
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()