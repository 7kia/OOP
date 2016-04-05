#include "stdafx.h"
#include "RectangleTests.h"


struct Rectangle_
{
	const float expectedLength = 10.f;
	const float expectedArea = 6.f;
	const SColor expectedOutlineColor;
	const SColor expectedFillColor;
	const CRectangle rectangle;
	Rectangle_()
		: expectedOutlineColor(160, 160, 160)
		, expectedFillColor(10, 10, 10)
		, rectangle(sf::Vector2f(1.f, 1.f), 2.f, 3.f,
					expectedFillColor, expectedOutlineColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, Rectangle_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const IShape*>(&rectangle));
}

BOOST_AUTO_TEST_CASE(has_color)
{
	BOOST_CHECK_EQUAL(rectangle.GetOutlineColor(), expectedOutlineColor);
	BOOST_CHECK_EQUAL(rectangle.GetFillColor(), expectedFillColor);
}

BOOST_AUTO_TEST_CASE(has_a_length)
{
	BOOST_CHECK(IsEqual(rectangle.GetPerimeter(), expectedLength));
}

BOOST_AUTO_TEST_CASE(has_a_area)
{
	BOOST_CHECK(IsEqual(rectangle.GetArea(), expectedArea));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Rectangle:
	Left top point = (1, 1)
	Outline color = #a0a0a0
	Fill color = #0a0a0a
	Perimeter = 10
	Area = 6
)";
	BOOST_CHECK_EQUAL(rectangle.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()


struct DefaultRectangle_
{
	const float expectedLength = 0.f;
	const float expectedArea = 0.f;
	const SColor expectedOutlineColor;
	const SColor expectedFillColor;
	const CRectangle rectangle;
	DefaultRectangle_()
		: expectedOutlineColor(0, 0, 0)
		, expectedFillColor(0, 0, 0)
	{}
};

BOOST_FIXTURE_TEST_SUITE(DefaultRectangle, DefaultRectangle_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const IShape*>(&rectangle));
}

BOOST_AUTO_TEST_CASE(has_color)
{
	BOOST_CHECK_EQUAL(rectangle.GetOutlineColor(), expectedOutlineColor);
	BOOST_CHECK_EQUAL(rectangle.GetFillColor(), expectedFillColor);
}

BOOST_AUTO_TEST_CASE(has_a_length)
{
	BOOST_CHECK(IsEqual(rectangle.GetPerimeter(), expectedLength));
}

BOOST_AUTO_TEST_CASE(has_a_area)
{
	BOOST_CHECK(IsEqual(rectangle.GetArea(), expectedArea));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Rectangle:
	Left top point = (0, 0)
	Outline color = #000000
	Fill color = #000000
	Perimeter = 0
	Area = 0
)";
	BOOST_CHECK_EQUAL(rectangle.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()