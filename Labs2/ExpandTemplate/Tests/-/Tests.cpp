// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../ExpandTemplate.h"

BOOST_AUTO_TEST_SUITE(ExpandTemplateTestModule)

BOOST_AUTO_TEST_CASE(Check_on_not_a_lot_of_templates)
{
	std::string inputString = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";;

	templates params;
	params["%USER_NAME%"] = "Ivan Petrov";
	params["{WEEK_DAY}"] = "Friday";

	std::string expandString = ExpandTemplateForString(inputString, params);
	std::string rightString = "Hello, Ivan Petrov. Today is Friday.";
	BOOST_CHECK(expandString == rightString);
}

BOOST_AUTO_TEST_CASE(Check_on_correct_replace)
{
	std::string inputString = "Hello, %US ER_NAME%. Today is {WEEK_DAY}.";;

	templates params;
	params["%USER_NAME%"] = "Super %USER_NAME% {WEEK_DAY}";
	params["{WEEK_DAY}"] = "Friday. {WEEK_DAY}";

	std::string expandString = ExpandTemplateForString(inputString, params);
	std::string rightString = "Hello, Super %USER_NAME% {WEEK_DAY}. Today is Friday. {WEEK_DAY}.";
	BOOST_CHECK(expandString == rightString);
}

BOOST_AUTO_TEST_SUITE_END()
