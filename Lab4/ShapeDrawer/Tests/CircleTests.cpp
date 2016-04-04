#include "stdafx.h"
#include "CircleTests.h"


struct Circle_
{
	const float expectedLength = 18.849f;
	const float expectedArea = 28.274f;
	const float expectedRadiuse = 3.f;
	const sf::Vector2f expectedPosition = { 1.f, 0.f };
	const SColor expectedOutlineColor;
	const SColor expectedFillColor;
	const CCircle circle;
	Circle_()
		: expectedOutlineColor(160, 160, 160)
		, expectedFillColor(10, 10, 10)
		, circle(expectedPosition, expectedRadiuse,
				expectedFillColor, expectedOutlineColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Circle, Circle_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const IShape*>(&circle));
}

BOOST_AUTO_TEST_CASE(has_color)
{
	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), expectedOutlineColor);
	BOOST_CHECK_EQUAL(circle.GetFillColor(), expectedFillColor);
}

BOOST_AUTO_TEST_CASE(has_a_radiuse)
{
	BOOST_CHECK(circle.GetRadiuse() == expectedRadiuse);
}

BOOST_AUTO_TEST_CASE(has_a_position)
{
	BOOST_CHECK(circle.GetPosition() == expectedPosition);
}

BOOST_AUTO_TEST_CASE(has_a_length)
{
	BOOST_CHECK(IsEqual(circle.GetPerimeter(), expectedLength));
}

BOOST_AUTO_TEST_CASE(has_a_area)
{
	BOOST_CHECK(IsEqual(circle.GetArea(), expectedArea));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Circle:
	Position center = (1, 0)
	Radiuse = 3
	Outline color = #a0a0a0
	Fill color = #0a0a0a
	Perimeter = 18.8
	Area = 28.3
)";
	BOOST_CHECK_EQUAL(circle.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()


struct DefaultCircle_
{
	const float expectedLength = 0.f;
	const float expectedArea = 0.f;
	const float expectedRadiuse = 0.f;
	const sf::Vector2f expectedPosition = { 0.f, 0.f };
	const SColor expectedOutlineColor;
	const SColor expectedFillColor;
	const CCircle circle;
	DefaultCircle_()
		: expectedOutlineColor(0, 0, 0)
		, expectedFillColor(0, 0, 0)
	{}
};

BOOST_FIXTURE_TEST_SUITE(DefaultCircle, DefaultCircle_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const IShape*>(&circle));
}

BOOST_AUTO_TEST_CASE(has_color)
{
	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), expectedOutlineColor);
	BOOST_CHECK_EQUAL(circle.GetFillColor(), expectedFillColor);
}

BOOST_AUTO_TEST_CASE(has_a_radiuse)
{
	BOOST_CHECK(circle.GetRadiuse() == expectedRadiuse);
}

BOOST_AUTO_TEST_CASE(has_a_position)
{
	BOOST_CHECK(circle.GetPosition() == expectedPosition);
}

BOOST_AUTO_TEST_CASE(has_a_length)
{
	BOOST_CHECK(IsEqual(circle.GetPerimeter(), expectedLength));
}

BOOST_AUTO_TEST_CASE(has_a_area)
{
	BOOST_CHECK(IsEqual(circle.GetArea(), expectedArea));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Circle:
	Position center = (0, 0)
	Radiuse = 0
	Outline color = #000000
	Fill color = #000000
	Perimeter = 0
	Area = 0
)";
	BOOST_CHECK_EQUAL(circle.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()