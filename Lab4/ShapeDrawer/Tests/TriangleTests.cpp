#include "stdafx.h"
#include "TriangleTests.h"


struct Triangle_
{
	const float expectedLength = 4.828f;
	const float expectedArea = 1.f;

	const sf::Vector2f firstPosition = { 1.f, 0.f };
	const sf::Vector2f secondPosition = { -1.f, 0.f };
	const sf::Vector2f thirdPosition = { 0.f, 1.f };

	const SColor expectedOutlineColor;
	const SColor expectedFillColor;

	const CTriangle triangle;

	Triangle_()
		: expectedOutlineColor(160, 160, 160)
		, expectedFillColor(10, 10, 10)
		, triangle(firstPosition, secondPosition, thirdPosition,
			expectedFillColor, expectedOutlineColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Triangle, Triangle_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const IShape*>(&triangle));
}

BOOST_AUTO_TEST_CASE(has_color)
{
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), expectedOutlineColor);
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), expectedFillColor);
}

BOOST_AUTO_TEST_CASE(has_a_length)//"$(TargetPath)" --log_level=test_suite
{
	BOOST_CHECK(IsEqual(triangle.GetPerimeter(), expectedLength));
}

BOOST_AUTO_TEST_CASE(has_a_area)
{
	BOOST_CHECK(IsEqual(triangle.GetArea(), expectedArea));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Triangle:
	Position first point = (1, 0)
	Position second point = (-1, 0)
	Position third point = (0, 1)
	Outline color = #a0a0a0
	Fill color = #0a0a0a
	Perimeter = 4.83
	Area = 1
)";
	BOOST_CHECK_EQUAL(triangle.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()


struct DefaultTriangle_
{
	const float expectedLength = 0.f;
	const float expectedArea = 0.f;
	const SColor expectedOutlineColor;
	const SColor expectedFillColor;
	const CTriangle triangle;
	DefaultTriangle_()
		: expectedOutlineColor(0, 0, 0)
		, expectedFillColor(0, 0, 0)
	{}
};

BOOST_FIXTURE_TEST_SUITE(DefaultTriangle, DefaultTriangle_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const IShape*>(&triangle));
}

BOOST_AUTO_TEST_CASE(has_color)
{
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), expectedOutlineColor);
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), expectedFillColor);
}

BOOST_AUTO_TEST_CASE(has_a_length)
{
	BOOST_CHECK(IsEqual(triangle.GetPerimeter(), expectedLength));
}

BOOST_AUTO_TEST_CASE(has_a_area)
{
	BOOST_CHECK(IsEqual(triangle.GetArea(), expectedArea));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Triangle:
	Position first point = (0, 0)
	Position second point = (0, 0)
	Position third point = (0, 0)
	Outline color = #000000
	Fill color = #000000
	Perimeter = 0
	Area = 0
)";
	BOOST_CHECK_EQUAL(triangle.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()