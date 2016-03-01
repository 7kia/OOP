// Lab2-1Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab2-1/ProcessVector.h"

BOOST_AUTO_TEST_SUITE(ProcessVectorTestModule);

BOOST_AUTO_TEST_CASE(Check_on_empty_vector)
{
	std::vector<double> checkVector;
	std::vector<double> emptyVector;

	ProcessVector(checkVector);

	BOOST_CHECK(checkVector == emptyVector);
}

BOOST_AUTO_TEST_CASE(Check_on_correct_data)
{
	std::vector<double> checkVector = { 4, 2, 9 };
	std::vector<double> rightVector = { 4, 8, 18 };

	ProcessVector(checkVector);

	BOOST_CHECK(checkVector == rightVector);
}

BOOST_AUTO_TEST_SUITE_END()