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

struct FindMaxExForDouble_
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

	FindMaxExForDouble_()
	{
		doubleVector = { 4.0, 2.3, 5.0, 9.0, -1.0, 1.6 };
		expectedDoubleVector = doubleVector;


	}
};

BOOST_FIXTURE_TEST_SUITE(FindMaxExForDouble, FindMaxExForDouble_)
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

BOOST_AUTO_TEST_CASE(Min_element_in_middle)
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


struct FindMaxExForString_
{
	std::vector<const char *> checkStringVector;
	std::vector<const char *> emptyStringVector;

	std::vector<const char *> stringVector;
	std::vector<const char *> expectedStringVector;

	char minChar = '\0';
	char expectedMax = 's';
	std::function<bool(const char, const char)> charLess = [&](const char first, const char second)
	{
		return first < second;
	};

	std::function<bool(const char, const char)> charMore = [&](const char first, const char second)
	{
		return first > second;
	};


	FindMaxExForString_()
	{
		stringVector = { "asd", "need", "joke", "viper", "great", "fire" };
		expectedStringVector = stringVector;
	}
};
BOOST_FIXTURE_TEST_SUITE(FindMaxExForString, FindMaxExForString_)
BOOST_AUTO_TEST_SUITE(function_must_not_change_sourse_arguments)
BOOST_AUTO_TEST_CASE(if_array_is_empty)
{
	char expectedMax = minChar;
	char max = expectedMax;
	BOOST_CHECK(!FindMax(checkStringVector, max, charLess));

	VerifyVectors(checkStringVector, emptyStringVector);
	BOOST_CHECK_EQUAL(max, expectedMax);
}
BOOST_AUTO_TEST_CASE(if_was_found_max_then_array_not_changed)
{
	char max = minChar;
	BOOST_CHECK(FindMax(stringVector, max, charLess));

	VerifyVectors(stringVector, expectedStringVector);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(function_change_second_argument_if_array_have_need_element)
BOOST_AUTO_TEST_CASE(Min_element_in_start)
{
	std::vector<const char *> checkVector = { "1x2", "s4", "c", "f9", "1.1" };

	char expectedMinElement = 'x';
	char max = minChar;
	BOOST_CHECK(FindMax(checkVector, max, charLess));

	BOOST_CHECK_EQUAL(max, expectedMinElement);
}

BOOST_AUTO_TEST_CASE(Min_element_in_middle)
{
	std::vector<const char *> checkVector = { "12", "s4", "xc", "f9", "1.1" };

	char expectedMinElement = 'x';
	char max = minChar;
	BOOST_CHECK(FindMax(checkVector, max, charLess));

	BOOST_CHECK_EQUAL(max, expectedMinElement);
}

BOOST_AUTO_TEST_CASE(Min_element_in_end)
{
	std::vector<const char *> checkVector = { "12", "s4", "ac", "f9", "1.1x" };

	char expectedMinElement = 'x';
	char max = minChar;
	BOOST_CHECK(FindMax(checkVector, max, charLess));

	BOOST_CHECK_EQUAL(max, expectedMinElement);
}

BOOST_AUTO_TEST_CASE(Min_element_is_zero)
{
	std::vector<const char *> checkVector = { "12", "s\04", "xc", "f9", "1.1" };

	char expectedMinElement = '\0';
	char max = minChar;
	BOOST_CHECK(FindMax(checkVector, max, charMore));

	BOOST_CHECK_EQUAL(max, expectedMinElement);
}
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()// BOOST_FIXTURE_TEST_SUITE(FindMaxEx, FindMaxEx_)


struct Sportsman
{
	Sportsman()
	{

	};

	Sportsman(const std::string & name
		, unsigned height
		, unsigned weight)
		: name(name)
		, height(height)
		, weight(weight)
	{

	};

	std::string name;
	unsigned height = 0u;
	unsigned weight = 0u;
};

struct FindMaxExForStruct_
{
	Sportsman checkStruct;

	std::vector<Sportsman> structVector;
	std::vector<Sportsman> expectedStructVector;

	char minChar = '\0';
	char expectedMax = 's';
	std::function<bool(const Sportsman &, const Sportsman &)> heightLess
		= [&](const Sportsman & first, const Sportsman & second)
	{
		return first.height < second.height;
	};

	std::function<bool(const Sportsman &, const Sportsman &)> weightLess
		= [&](const Sportsman & first, const Sportsman & second)
	{
		return first.weight < second.weight;
	};



	FindMaxExForStruct_()
	{
		structVector = { { "Masa", 145, 55 },{ "Polt", 165, 95 },{ "Strange", 175, 75 } };
		expectedStructVector = structVector;
	}
};

BOOST_FIXTURE_TEST_SUITE(FindMaxExForStruct, FindMaxExForStruct_)
BOOST_AUTO_TEST_CASE(Find_sportsman_with_max_height)
{
	unsigned expectedHeight = 175u;
	BOOST_CHECK(FindMax(structVector, checkStruct, heightLess));

	BOOST_CHECK_EQUAL(checkStruct.height, expectedHeight);
}

BOOST_AUTO_TEST_CASE(Find_sportsman_with_max_weight)
{
	unsigned expectedWeight = 95u;
	BOOST_CHECK(FindMax(structVector, checkStruct, weightLess));

	BOOST_CHECK_EQUAL(checkStruct.weight, expectedWeight);
}
BOOST_AUTO_TEST_SUITE_END()// BOOST_FIXTURE_TEST_SUITE(FindMaxEx, FindMaxEx_)