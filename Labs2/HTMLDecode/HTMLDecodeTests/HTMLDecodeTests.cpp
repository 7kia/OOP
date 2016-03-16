// HTMLDecodeTests.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"

#include "../HTMLDecode/HTMLDecoder.h"

BOOST_AUTO_TEST_SUITE(HTMLDecodeTestModule)

BOOST_AUTO_TEST_CASE(Check_on_empty_string)
{
	std::string emptyString;

	std::string rightString;

	std::string result = DoHtmlDecode(emptyString);

	BOOST_CHECK(result == rightString);
}

BOOST_AUTO_TEST_CASE(Search_element_in_middle)
{
	std::string checkString = "asdasd asda 123 \\ \" apos &apos;&lt; &gt;&amp;&amp;&amp; sfasdfasdf  sa";

	std::string rightString = "asdasd asda 123 \\ \" apos С< >&&& sfasdfasdf  sa";

	std::string result = DoHtmlDecode(checkString);

	BOOST_CHECK(result == rightString);
}

BOOST_AUTO_TEST_CASE(Search_element_in_start)
{
	std::string checkString = "&quot;a&apos;sda&lt;sd&gt; a&amp;sda 123 \\ \" apos С< >&&& sfasdfasdf  sa";

	std::string rightString = "\"aСsda<sd> a&sda 123 \\ \" apos С< >&&& sfasdfasdf  sa";

	std::string result = DoHtmlDecode(checkString);

	BOOST_CHECK(result == rightString);
}

BOOST_AUTO_TEST_CASE(Search_element_in_end)
{
	std::string checkString = "\"aСsda<sd> a&amp;sda 123 \\ \" apos С< >&&& sfasdfasdf  &amp;s&aamp";

	std::string rightString = "\"aСsda<sd> a&sda 123 \\ \" apos С< >&&& sfasdfasdf  &s&aamp";

	std::string result = DoHtmlDecode(checkString);

	BOOST_CHECK(result == rightString);
}

BOOST_AUTO_TEST_CASE(Check_searching_everything_string)
{
	std::string checkString = "&quot;&apos;&lt;&gt;&amp;";

	std::string rightString = "\"С<>&";

	std::string result = DoHtmlDecode(checkString);

	BOOST_CHECK(result == rightString);
}

BOOST_AUTO_TEST_SUITE_END()

