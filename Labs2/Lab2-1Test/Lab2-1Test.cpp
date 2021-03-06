// Lab2-1Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab2-1/ProcessVector.h"

BOOST_AUTO_TEST_SUITE(ProcessVectorTestModule)

BOOST_AUTO_TEST_CASE(Check_on_empty_vector)
{
	std::vector<double> checkVector;
	std::vector<double> emptyVector;

	ProcessVector(checkVector);

	BOOST_CHECK(checkVector == emptyVector);
}

BOOST_AUTO_TEST_CASE(Min_element_in_middle)
{
	std::vector<double> checkVector = { 4, 2, 9 };
	std::vector<double> rightVector = { 4, 8, 18 };

	ProcessVector(checkVector);

	BOOST_CHECK(checkVector == rightVector);
}

BOOST_AUTO_TEST_CASE(Min_element_in_start)
{
	std::vector<double> checkVector = { 1, 4, 2, 9, 1.1 };
	std::vector<double> rightVector = { 1, 1.1, 2, 4, 9 };

	ProcessVector(checkVector);

	BOOST_CHECK(checkVector == rightVector);
}

BOOST_AUTO_TEST_CASE(Min_element_in_end)
{
	std::vector<double> checkVector = { 1.1, 4, 2, 9, 0.1 };
	std::vector<double> rightVector = { 0.010000000000000002,
										0.11000000000000001, 
										0.20000000000000001, 
										0.40000000000000002,
										0.90000000000000002 };

	ProcessVector(checkVector);

	BOOST_CHECK(checkVector == rightVector);
}

BOOST_AUTO_TEST_CASE(Min_element_is_zero)
{
	std::vector<double> checkVector = { 1.1, 4, 2, 0, 0.1 };
	std::vector<double> rightVector = { 0, 0, 0, 0, 0 };

	ProcessVector(checkVector);

	BOOST_CHECK(checkVector == rightVector);
}

BOOST_AUTO_TEST_SUITE_END()