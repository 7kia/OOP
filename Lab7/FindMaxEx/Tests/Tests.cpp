// Lab2-1Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../FindMaxEx.h"

using namespace std;

template<typename T>
bool VerifyVectors(const vector<T> &first
					, const vector<T> &second)
{
	if (first.size() != second.size())
	{
		return false;
	}

	for (size_t index = 0; index < first.size(); index++)
	{
		BOOST_CHECK(first[index] == second[index]);
	}

	return true;
}

struct FindMaxEx_
{
	std::vector<double> checkDoubleVector;
	std::vector<double> emptyDoubleVector;

	std::vector<double> doubleVector;
	std::vector<double> expectedDoubleVector;

	double minDouble = std::numeric_limits<double>::min();
	double maxDouble = std::numeric_limits<double>::max();
	// TODO for string
	double expectedMax = 9.0;
	std::function<bool(const double, const double)> doubleLess = [&](const double first, const double second)
	{
		return first < second;
	};

	double expectedMin = -1.0;
	std::function<bool(const double, const double)> doubleMore = [&](const double first, const double second)
	{
		return first > second;
	};

	FindMaxEx_() 
	{
		doubleVector = { 4.0, 2.3, 5.0, 9.0, -1.0, 1.6 };
		expectedDoubleVector = doubleVector;

		
	}
};

BOOST_FIXTURE_TEST_SUITE(FindMaxEx, FindMaxEx_)
	BOOST_AUTO_TEST_SUITE(function_must_not_change_sourse_arguments)
		BOOST_AUTO_TEST_CASE(if_array_is_empty)
		{
			double expectedMax = minDouble;
			double max = expectedMax;
			BOOST_CHECK(!FindMax(checkDoubleVector, max, doubleLess));

			VerifyVectors(checkDoubleVector, emptyDoubleVector);
			BOOST_CHECK_EQUAL(max, expectedMax);
		}
		BOOST_AUTO_TEST_CASE(if_was_found_max_then_array_not_changed)
		{
			double max = minDouble;
			BOOST_CHECK(FindMax(doubleVector, max, doubleLess));

			VerifyVectors(doubleVector, expectedDoubleVector);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(function_change_second_argument_if_array_have_need_element)
		BOOST_AUTO_TEST_CASE(Min_element_in_start)
		{
			std::vector<double> checkVector = { 1, 4, 2, 9, 1.1 };

			double expectedMinElement = 1.0;
			double max = maxDouble;
			BOOST_CHECK(FindMax(checkVector, max, doubleMore));

			BOOST_CHECK_EQUAL(max, expectedMinElement);
		}

		BOOST_AUTO_TEST_CASE(Min_element_in_middle)// TODO : кривой английский
		{
			std::vector<double> checkVector = { 4, 2, 9 };

			double expectedMinElement = 2.0;
			double max = maxDouble;
			BOOST_CHECK(FindMax(checkVector, max, doubleMore));

			BOOST_CHECK_EQUAL(max, expectedMinElement);
		}

		BOOST_AUTO_TEST_CASE(Min_element_in_end)
		{
			std::vector<double> checkVector = { 1.1, 4, 2, 9, 0.1 };

			double expectedMinElement = 0.1;
			double max = maxDouble;
			BOOST_CHECK(FindMax(checkVector, max, doubleMore));

			BOOST_CHECK_EQUAL(max, expectedMinElement);
		}

		BOOST_AUTO_TEST_CASE(Min_element_is_zero)
		{
			std::vector<double> checkVector = { 1.1, 0, 2, 9, 0.1 };

			double expectedMinElement = 0.;
			double max = maxDouble;
			BOOST_CHECK(FindMax(checkVector, max, doubleMore));

			BOOST_CHECK_EQUAL(max, expectedMinElement);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()// BOOST_FIXTURE_TEST_SUITE(FindMaxEx, FindMaxEx_)