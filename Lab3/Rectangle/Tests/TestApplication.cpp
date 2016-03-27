#include "stdafx.h"
#include "TestApplication.h"

BOOST_AUTO_TEST_SUITE(ApplicationTestModule)

bool TestApplictation(int argc, char *argv[])
{
	try
	{
		CApplication application(argc, argv);

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

BOOST_AUTO_TEST_CASE(Check_empty_rectangle)
{
	char *arguments[] = { "Test.exe", "empty1.txt", "empty2.txt", "resultEmpty.txt", "intersectionEmpty.txt" };
	BOOST_CHECK(TestApplictation(5, arguments) == false);
}

BOOST_AUTO_TEST_CASE(Check_correct_rectangles_without_transformation)
{
	char *arguments[] = { "Test.exe", "rect1-1.txt", "rect1-2.txt", "result1.txt", "intersection1.txt" };
	BOOST_CHECK(TestApplictation(5, arguments));

	CompareFiles(arguments[3], PATH_RIGHT_DATA + arguments[3]);
}

BOOST_AUTO_TEST_CASE(Check_correct_rectangles_with_transformation)
{
	char *arguments[] = { "Test.exe", "rect2-1.txt", "rect2-2.txt", "result1.txt", "intersection1.txt" };
	BOOST_CHECK(TestApplictation(5, arguments));
	CompareFiles(arguments[3], PATH_RIGHT_DATA + arguments[3]);

	char *arguments2[] = { "Test.exe", "rect2-1.txt", "rect2-3.txt", "result2.txt", "intersection2.txt" };
	BOOST_CHECK(TestApplictation(5, arguments2));
	CompareFiles(arguments2[3], PATH_RIGHT_DATA + arguments2[3]);

	char *arguments3[] = { "Test.exe", "rect2-1.txt", "rect2-4.txt", "result3.txt", "intersection3.txt" };
	BOOST_CHECK(TestApplictation(5, arguments3));
	CompareFiles(arguments3[3], PATH_RIGHT_DATA + arguments3[3]);

	char *arguments4[] = { "Test.exe", "rect2-1.txt", "rect2-5.txt", "result4.txt", "intersection4.txt" };
	BOOST_CHECK(TestApplictation(5, arguments4));
	CompareFiles(arguments4[3], PATH_RIGHT_DATA + arguments4[3]);

}

BOOST_AUTO_TEST_SUITE_END()
