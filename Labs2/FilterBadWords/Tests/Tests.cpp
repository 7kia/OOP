// Tests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "../FilterBadWords.h"


BOOST_AUTO_TEST_SUITE(FilterBadWordsTestModule)

BOOST_AUTO_TEST_CASE(Check_on_empty_dictionary_file)
{
	std::cout << "==========================================" << std::endl;

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	dictionary badWords = CreateDictionary("bad.txt");
	std::string inputString = "";

	std::string filterString = FilterBadWords(inputString, badWords);
	std::string rightString = "";

	BOOST_CHECK(filterString == rightString);
}

BOOST_AUTO_TEST_CASE(Check_filtering_english_and_russian_words)
{
	std::cout << "==========================================" << std::endl;

	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);

	dictionary badWords = CreateDictionary("bad.txt");
	std::string inputString = "le fuck ������ lehfr �����";

	std::string filterString = FilterBadWords(inputString, badWords);
	std::string rightString = "le  ������ lenfr ";

	BOOST_CHECK(filterString == rightString);
}


BOOST_AUTO_TEST_SUITE_END()
