// ParseURLTests.cpp: определ€ет точку входа дл€ консольного приложени€.
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

	return true;
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
			BOOST_CHECK(VerifyVectors(ConvertToVector(list), expectedVector));
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

/*
// «аготовка дл€ тестов
BOOST_AUTO_TEST_CASE(_)
{
	BOOST_CHECK(false);
}
*/


BOOST_AUTO_TEST_SUITE(StringListWithSeveralElement)
	struct StringListWithSeveralElement_
	{
		std::string firstElelment = "OOP";
		std::string secondElelment = "PPO";
		std::string thirdElelment = "MLaTA";
		std::string fourthElelment = "CV";
		std::string fifthElelment = "TM";

		CStringList list;
		std::list<std::string> pattern;
		size_t expectedSize = 0;
		///*
		StringListWithSeveralElement_()
		{
			list.PushToEnd(firstElelment);
			list.PushToEnd(secondElelment);
			list.PushToEnd(thirdElelment);
			list.PushToEnd(fourthElelment);
			list.PushToEnd(fifthElelment);

			expectedSize = list.GetSize();

			pattern.push_back(firstElelment);
			pattern.push_back(secondElelment);
			pattern.push_back(thirdElelment);
			pattern.push_back(fourthElelment);
			pattern.push_back(fifthElelment);

		}
		//*/
	};

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

		BOOST_AUTO_TEST_SUITE(TestIterator)
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
		BOOST_AUTO_TEST_SUITE_END()// TestIterator

		BOOST_AUTO_TEST_SUITE(TestReverseIterator)
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
		BOOST_AUTO_TEST_SUITE_END()// TestReverseIterator

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
