#include "stdafx.h"
#include "TestApplication.h"

BOOST_AUTO_TEST_SUITE(ApplicationTestModule)

bool TestApplictation(const listArguments &namesFiles)
{
	try
	{
		CRunner application(namesFiles);

		application.Run();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

const std::string PATH_RIGHT_DATA = "Right\\";

void CompareFiles(const std::string & first, const std::string & second)
{
	std::ifstream resultFile(first);
	std::ifstream rightResultFile(second);

	std::istream_iterator<char> iterResultFile(resultFile), endIter;
	std::istream_iterator<char> iterRightRsultFile(rightResultFile);

	BOOST_CHECK_EQUAL_COLLECTIONS(iterResultFile, endIter, iterRightRsultFile, endIter);
};

BOOST_AUTO_TEST_CASE(throw_Exception_on_empty_rectangle_or_rectangles)
{
	const listArguments arguments = { "empty1.txt", "rect1-2.txt", "result1.txt", "intersection1.txt" };
	BOOST_CHECK(TestApplictation(arguments) == false);

	const listArguments arguments2 = { "rect1-1.txt", "empty2.txt", "result1.txt", "intersection1.txt" };
	BOOST_CHECK(TestApplictation(arguments) == false);

	const listArguments arguments3 = { "empty1.txt", "empty2.txt", "result1.txt", "intersection1.txt" };
	BOOST_CHECK(TestApplictation(arguments) == false);

}

BOOST_AUTO_TEST_CASE(Check_correct_rectangles_without_transformation)
{
	const listArguments arguments = { "rect1-1.txt", "rect1-2.txt", "result2.txt", "intersection2.txt" };
	BOOST_CHECK(TestApplictation(arguments));

	CompareFiles(arguments[2], PATH_RIGHT_DATA + arguments[2]);
	CompareFiles(arguments[3], PATH_RIGHT_DATA + arguments[3]);
}

BOOST_AUTO_TEST_CASE(Check_correct_rectangles_with_transformation)
{
	const listArguments arguments = { "rect2-1.txt", "rect2-2.txt", "result3.txt", "intersection3.txt" };
	BOOST_CHECK(TestApplictation(arguments));

	CompareFiles(arguments[2], PATH_RIGHT_DATA + arguments[2]);
	CompareFiles(arguments[3], PATH_RIGHT_DATA + arguments[3]);

	const listArguments arguments2 = { "rect2-1.txt", "rect2-3.txt", "result4.txt", "intersection4.txt" };
	BOOST_CHECK(TestApplictation(arguments2));
	CompareFiles(arguments[2], PATH_RIGHT_DATA + arguments[2]);
	CompareFiles(arguments[3], PATH_RIGHT_DATA + arguments[3]);

	const listArguments arguments3 = { "rect2-1.txt", "rect2-4.txt", "result5.txt", "intersection5.txt" };
	BOOST_CHECK(TestApplictation(arguments3));
	CompareFiles(arguments[2], PATH_RIGHT_DATA + arguments[2]);
	CompareFiles(arguments[3], PATH_RIGHT_DATA + arguments[3]);

	const listArguments arguments4 = { "rect2-1.txt", "rect2-5.txt", "result6.txt", "intersection6.txt" };
	BOOST_CHECK(TestApplictation(arguments4));
	CompareFiles(arguments[2], PATH_RIGHT_DATA + arguments[2]);
	CompareFiles(arguments[3], PATH_RIGHT_DATA + arguments[3]);
}

BOOST_AUTO_TEST_SUITE_END()
