// Tests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "../FilterBadWords.h"


BOOST_AUTO_TEST_SUITE(FilterBadWordsTestModule)

BOOST_AUTO_TEST_CASE(Check_on_empty_dictionary_file)
{
	dictionary badWords = CreateDictionary("bad.txt");
	std::string inputString = "";

	std::string filterString = FilterBadWords(inputString, badWords);
	std::string rightString = "";

	BOOST_CHECK(filterString == rightString);
}

BOOST_AUTO_TEST_CASE(Check_filtering_english_and_russian_words)
{
	dictionary badWords = CreateDictionary("bad.txt");
	std::string inputString = "le fuck ������ lehfr \t�����";

	std::string filterString = FilterBadWords(inputString, badWords);
	std::string rightString = "le  ������ lehfr \t";

	BOOST_CHECK(filterString == rightString);
}

BOOST_AUTO_TEST_SUITE_END()
