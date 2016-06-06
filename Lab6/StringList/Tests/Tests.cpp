// ParseURLTests.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "Tests.h"

using namespace std;


bool VerifyVectors(const vector<string> &first , const vector<string> &second)
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

/*
// «аготовка дл€ тестов
BOOST_AUTO_TEST_CASE(_)
{
BOOST_CHECK(false);
}
*/


