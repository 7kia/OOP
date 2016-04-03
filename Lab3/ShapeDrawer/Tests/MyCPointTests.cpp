#include "stdafx.h"
#include "MyCPointTests.h"

struct MyCPoint_
{
	const double expectedLength = 0.f;
	const float expectedArea = 0.f;
	const MyCPoint point;
	const SColor expectedColor;
	MyCPoint_()
		: expectedColor(16, 16, 16)
		, point(sf::Vector2f(0.f, 0.f), expectedColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(MyCPoint, MyCPoint_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const IShape*>(&point));
}

BOOST_AUTO_TEST_CASE(has_color)
{
	BOOST_CHECK_EQUAL(point.GetColor(), expectedColor);
}

BOOST_AUTO_TEST_CASE(has_a_length)//"$(TargetPath)" --log_level=test_suite
{
	BOOST_CHECK_EQUAL(point.GetPerimeter(), expectedLength, tt::tolerance(0.1));
}

BOOST_AUTO_TEST_CASE(not_has_a_area)
{
	BOOST_CHECK_EQUAL(point.GetArea(), expectedArea, tt::tolerance(0.1));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Line segment:
	Position first point = (0, 0)
	Position second point = (0, 1)
	Color = #101010
	Length = 1
	Area = 0
)";
	BOOST_CHECK_EQUAL(point.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()


struct DefaultMyCPoint_
{
	const double expectedLength = 0.f;
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
	BOOST_CHECK_EQUAL(point.GetPerimeter(), expectedLength, tt::tolerance(0.1));
}

BOOST_AUTO_TEST_CASE(not_has_a_area)
{
	BOOST_CHECK_EQUAL(point.GetArea(), expectedArea, tt::tolerance(0.1));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Line segment:
	Position first point = (0, 0)
	Position second point = (0, 0)
	Color = #000000
	Length = 0
	Area = 0
)";
	BOOST_CHECK_EQUAL(point.GetStringPresentation(), expectedString);
}

BOOST_AUTO_TEST_SUITE_END()


