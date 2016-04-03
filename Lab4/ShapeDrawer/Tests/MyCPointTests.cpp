#include "stdafx.h"
#include "MyCPointTests.h"

struct MyCPoint_
{
	const float expectedLength = 0.f;
	const float expectedArea = 0.f;
	const SColor expectedColor;
	const MyCPoint point;
	MyCPoint_()
		: expectedColor(16, 16, 16)
		, point(sf::Vector2f(1.f, 2.f), expectedColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(MyCPoint1, MyCPoint_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const IShape*>(&point));
}

BOOST_AUTO_TEST_CASE(has_a_length)//"$(TargetPath)" --log_level=test_suite
{
	BOOST_CHECK(IsEqual(point.GetPerimeter(), expectedLength));
}

BOOST_AUTO_TEST_CASE(not_has_a_area)
{
	BOOST_CHECK(IsEqual(point.GetArea(), expectedArea));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Point:
	Position = (1, 2)
	Length = 0
	Color = #101010
	Area = 0
)";
	BOOST_CHECK_EQUAL(point.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()


struct DefaultMyCPoint_
{
	const float expectedLength = 0.f;
	const float expectedArea = 0.f;
	const SColor expectedColor;
	const MyCPoint point;
	DefaultMyCPoint_()
		: expectedColor(0, 0, 0)
	{}

};
BOOST_FIXTURE_TEST_SUITE(DefaultMyCPoint, DefaultMyCPoint_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const IShape*>(&point));
}

BOOST_AUTO_TEST_CASE(not_has_a_length)//"$(TargetPath)" --log_level=test_suite
{
	BOOST_CHECK_EQUAL(point.GetPerimeter(), expectedLength, epsilon);
}

BOOST_AUTO_TEST_CASE(not_has_a_area)
{
	BOOST_CHECK_EQUAL(point.GetArea(), expectedArea, epsilon);
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Point:
	Position = (0, 0)
	Length = 0
	Color = #000000
	Area = 0
)";
	BOOST_CHECK_EQUAL(point.GetStringPresentation(), expectedString);
}

BOOST_AUTO_TEST_SUITE_END()


