// ParseURLTests.cpp: ���������� ����� ����� ��� ����������� ����������.
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

vector<string> ConvertToVector(CStringList<string> & list)
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
		CStringList<std::string> stringList;
	};

	BOOST_FIXTURE_TEST_SUITE(EmptyStringList, EmptyStringList_)
		BOOST_AUTO_TEST_CASE(when_created_is_empty)
		{	
			BOOST_CHECK_EQUAL(stringList.IsEmpty(), true);
		}

		BOOST_AUTO_TEST_CASE(when_created_have_zero_size)
		{
			BOOST_CHECK_EQUAL(stringList.GetSize(), 0);
		}

		BOOST_AUTO_TEST_CASE(append_increase_one_to_size)
		{
			stringList.PushToEnd("1");
			BOOST_CHECK_EQUAL(stringList.GetSize(), 1);
			stringList.PushToEnd("xcc");
			BOOST_CHECK_EQUAL(stringList.GetSize(), 2);
		}

		BOOST_AUTO_TEST_CASE(start_and_end_list_from_one_element_refer_to_only)
		{
			std::string addElelment = "OOP";
			stringList.PushToEnd(addElelment);

			BOOST_CHECK_EQUAL(stringList.front(), addElelment);
			BOOST_CHECK_EQUAL(stringList.back(), addElelment);
		}

		BOOST_AUTO_TEST_CASE(list_can_have_several_elemets)
		{
			std::string firstElelment = "OOP";
			std::string secondElelment = "PPO";
			std::string thirdElelment = "MLaTA";

			stringList.PushToEnd(firstElelment);
			stringList.PushToEnd(secondElelment);
			stringList.PushToEnd(thirdElelment);

			BOOST_CHECK_EQUAL(stringList.front(), firstElelment);
			BOOST_CHECK_EQUAL(stringList.back(), thirdElelment);

			vector<string> expectedVector = { firstElelment, secondElelment, thirdElelment };
			BOOST_CHECK(VerifyVectors(ConvertToVector(stringList), expectedVector));
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

/*
// ��������� ��� ������
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

		CStringList<string> stringList;
		std::list<std::string> pattern;
		size_t expectedSize = 0;
		///*
		StringListWithSeveralElement_()
		{
			stringList.PushToEnd(firstElelment);
			stringList.PushToEnd(secondElelment);
			stringList.PushToEnd(thirdElelment);
			stringList.PushToEnd(fourthElelment);
			stringList.PushToEnd(fifthElelment);

			expectedSize = stringList.GetSize();

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

			stringList.PushToStart(addString);
			BOOST_CHECK_EQUAL(stringList.front(), addString);
			////////////////////////////////////////////
			// pattern
			pattern.push_front(addString);
			BOOST_CHECK_EQUAL(pattern.front(), addString);
		}
		BOOST_AUTO_TEST_CASE(can_add_element_to_end)
		{
			std::string addString = "CV";

			stringList.PushToEnd(addString);
			BOOST_CHECK_EQUAL(stringList.back(), addString);
			////////////////////////////////////////////
			// pattern
			pattern.push_back(addString);
			BOOST_CHECK_EQUAL(pattern.back(), addString);
		}

		BOOST_AUTO_TEST_SUITE(TestIterator)
			BOOST_AUTO_TEST_CASE(can_get_value_list_to_help_operator_star)
			{
				CStringList<string>::CIterator iter = stringList.begin();
				
				BOOST_CHECK_EQUAL(*iter, firstElelment);
			}
			BOOST_AUTO_TEST_CASE(can_get_value_list_to_help_operator_arrow)
			{
				CStringList<string>::CIterator iter = stringList.begin();

				BOOST_CHECK_EQUAL(iter->c_str(), firstElelment);
			}
			BOOST_AUTO_TEST_SUITE(TestInsert)
				BOOST_AUTO_TEST_CASE(after_insert_increase_size)
				{
					CStringList<string>::CIterator iter = stringList.begin();
					std::string addString = "ethic";

					stringList.Insert(iter, addString);
					BOOST_CHECK_EQUAL(stringList.GetSize(), expectedSize + 1);
				}
				BOOST_AUTO_TEST_CASE(can_insert_in_start)
				{
					CStringList<string>::CIterator iter = stringList.begin();
					std::string addString = "ethic";

					stringList.Insert(iter, addString);
					BOOST_CHECK_EQUAL(*(--iter), addString);
					////////////////////////////////////////////
					// pattern
					auto patternIter = pattern.begin();
					pattern.insert(patternIter, addString);
					BOOST_CHECK_EQUAL(*(--patternIter), addString);
				}
				BOOST_AUTO_TEST_CASE(can_insert_in_middle)
				{
					CStringList<string>::CIterator iter = stringList.begin();
					std::string addString = "Fire";

					++iter;
					++iter;

					stringList.Insert(iter, addString);
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
					CStringList<string>::CIterator iter = stringList.end();
					std::string addString = "Memory";

					stringList.Insert(--iter, addString);
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
					CStringList<string>::CIterator iter = stringList.begin();

					stringList.Erase(iter);
					BOOST_CHECK_EQUAL(stringList.GetSize(), expectedSize - 1);
				}
				BOOST_AUTO_TEST_CASE(can_insert_in_start)
				{
					CStringList<string>::CIterator iter = stringList.begin();

					stringList.Erase(iter);
					BOOST_CHECK_EQUAL(*(stringList.begin()), secondElelment);			
					////////////////////////////////////////////
					// pattern
					auto patternIter = pattern.begin();
					pattern.erase(patternIter);
					BOOST_CHECK_EQUAL(*(pattern.begin()), secondElelment);
				}
				BOOST_AUTO_TEST_CASE(can_insert_in_middle)
				{
					CStringList<string>::CIterator iter = stringList.begin();

					++iter;
					++iter;
					stringList.Erase(iter);

					iter = stringList.begin();
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
					CStringList<string>::CIterator iter = stringList.end();
					stringList.Erase(--iter);

					iter = stringList.end();
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
					CStringList<string>::CIterator iter1;
					{
						CStringList<string> L2;
						L2.PushToStart("1");

						CStringList<string>::CIterator iter2 = L2.begin();
						iter1 = iter2;
					}
				);
			}
			BOOST_AUTO_TEST_CASE(list_can_get_iterator_for_first_element)
			{
				CStringList<string>::CIterator iter = stringList.begin();
	
				BOOST_CHECK_EQUAL(*iter, stringList.front());
				////////////////////////////////////////////
				// pattern
				auto patternIter = pattern.begin();
				BOOST_CHECK_EQUAL(*patternIter, stringList.front());

			}
			BOOST_AUTO_TEST_CASE(use_increment_iterator_can_get_reference_for_next)
			{
				CStringList<string>::CIterator iter = stringList.begin();

				BOOST_CHECK_EQUAL(*(++iter), secondElelment);
				////////////////////////////////////////////
				// pattern
				auto patternIter = pattern.begin();
				BOOST_CHECK_EQUAL(*(++patternIter), secondElelment);
			}
			BOOST_AUTO_TEST_CASE(throw_exception_for_try_increment_iterator_have_reference_to_end)
			{
				CStringList<string>::CIterator iter = stringList.end();

				BOOST_CHECK_THROW(++iter, std::runtime_error);
			}

			BOOST_AUTO_TEST_CASE(use_decrement_end_iterator_can_get_reference_for_last)
			{
				CStringList<string>::CIterator iter = stringList.end();

				BOOST_CHECK_EQUAL(*(--iter), stringList.back());
				////////////////////////////////////////////
				// pattern
				auto patternIter = pattern.end();
				BOOST_CHECK_EQUAL(*(--patternIter), stringList.back());

			}
			BOOST_AUTO_TEST_CASE(throw_exception_for_try_decrement_iterator_have_reference_to_start)
			{
				CStringList<string>::CIterator iter = stringList.begin();

				BOOST_CHECK_THROW(--iter, std::runtime_error);
			}

			BOOST_AUTO_TEST_SUITE(TestOperatorAssigned)
				BOOST_AUTO_TEST_CASE(can_assigned_empty_list)
				{
					stringList = CStringList<string>();

					VerifyVectors(ConvertToVector(stringList), ConvertToVector(CStringList<string>()));
				}
				BOOST_AUTO_TEST_CASE(can_assigned_not_empty_list)
				{
					CStringList<string> secondList;
					secondList.PushToEnd("sda");
					secondList.PushToEnd("dfg");
					secondList.PushToEnd("qwesdf");

					stringList = secondList;

					VerifyVectors(ConvertToVector(stringList), ConvertToVector(secondList));
				}
				BOOST_AUTO_TEST_CASE(can_assigned_ownself_list)
				{
					stringList = stringList;
				}
			BOOST_AUTO_TEST_SUITE_END()// TestOperatorAssigned
		BOOST_AUTO_TEST_SUITE_END()// TestIterator

		BOOST_AUTO_TEST_SUITE(TestReverseIterator)
			BOOST_AUTO_TEST_CASE(use_decrement_reverse_iterator_can_get_first_element)
			{
				CStringList<string>::CReverseIterator iter = stringList.rend();

				BOOST_CHECK_EQUAL(*(--iter), stringList.front());
				////////////////////////////////////////////
				// pattern
				auto patternIter = pattern.rend();
				BOOST_CHECK_EQUAL(*(--patternIter), stringList.front());
			}
			BOOST_AUTO_TEST_CASE(throw_exception_for_try_decrement_reverse_iterator_have_reference_to_end)
			{
				CStringList<string>::CReverseIterator iter = stringList.rbegin();

				BOOST_CHECK_THROW(--iter, std::runtime_error);
			}
			BOOST_AUTO_TEST_CASE(use_increment_reverse_iterator_can_get_previous_element)
			{
				CStringList<string>::CReverseIterator iter = stringList.rbegin();

				BOOST_CHECK_EQUAL(*(++iter), fourthElelment);
				////////////////////////////////////////////
				// pattern
				auto patternIter = pattern.rbegin();
				BOOST_CHECK_EQUAL(*(++patternIter), fourthElelment);
			}
			BOOST_AUTO_TEST_CASE(throw_exception_for_try_increment_reverse_iterator_have_reference_to_begin)
			{
				CStringList<string>::CReverseIterator iter = stringList.rend();

				BOOST_CHECK_THROW(++iter, std::runtime_error);
			}
			BOOST_AUTO_TEST_CASE(use_reverse_iterator_can_get_reference_for_last)
			{
				CStringList<string>::CReverseIterator iter = stringList.rbegin();

				BOOST_CHECK_EQUAL(*iter, stringList.back());
				////////////////////////////////////////////
				// pattern
				auto patternIter = pattern.rbegin();
				BOOST_CHECK_EQUAL(*(patternIter), stringList.back());
			}
		BOOST_AUTO_TEST_SUITE_END()// TestReverseIterator

			BOOST_AUTO_TEST_SUITE(ConstructCopy)
				BOOST_AUTO_TEST_CASE(can_assigned_not_empty_list)
				{
					CStringList<string> secondList;
				
					secondList = stringList;

					stringList.Erase(secondList.begin());

					BOOST_CHECK(stringList.front() != secondList.front());
				}

			BOOST_AUTO_TEST_SUITE_END()// TestReverseIterator
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
