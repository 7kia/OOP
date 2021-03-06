#include "stdafx.h"
#include "TriangleTests.h"


struct Triangle_
{
	const float expectedLength = 4.828f;
	const float expectedArea = 1.f;

	const sf::Vector2f firstPosition = { 1.f, 0.f };
	const sf::Vector2f secondPosition = { -1.f, 0.f };
	const sf::Vector2f thirdPosition = { 0.f, 1.f };
	const sf::Vector2f excpectedPosition = { 2.f, 9.f };

	const SColor expectedOutlineColor;
	const SColor expectedFillColor;
	const SColor expectedColorForSetVectorMethod;

	const uint8_t expectedRed;
	const uint8_t expectedGreen;
	const uint8_t expectedBlue;

	CTriangle triangle;

	Triangle_()
		: expectedOutlineColor(10, 10, 10)
		, expectedFillColor(160, 160, 160)
		, expectedColorForSetVectorMethod(1, 2, 3)
		, expectedRed(4)
		, expectedGreen(5)
		, expectedBlue(6)
		, triangle(firstPosition, secondPosition, thirdPosition,
			expectedFillColor, expectedOutlineColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Triangle, Triangle_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const CShape*>(&triangle));
}

BOOST_AUTO_TEST_CASE(has_color_outline_color)
{
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), expectedOutlineColor);

	triangle.SetOutlineColor(expectedColorForSetVectorMethod);
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), expectedColorForSetVectorMethod);

	triangle.SetOutlineColor(expectedRed, expectedGreen, expectedBlue);
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), SColor(expectedRed, expectedGreen, expectedBlue));

}

BOOST_AUTO_TEST_CASE(has_color_fill_color)
{
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), expectedFillColor);

	triangle.SetFillColor(expectedColorForSetVectorMethod);
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), expectedColorForSetVectorMethod);

	triangle.SetFillColor(expectedRed, expectedGreen, expectedBlue);
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), SColor(expectedRed, expectedGreen, expectedBlue));

}

BOOST_AUTO_TEST_CASE(has_a_first_point)
{
	VerifyVector2f(triangle.GetFirstPoint(), firstPosition);

	triangle.SetPositionFirstPoint(excpectedPosition);
	VerifyVector2f(triangle.GetFirstPoint(), excpectedPosition);
}

BOOST_AUTO_TEST_CASE(has_a_second_point)
{
	VerifyVector2f(triangle.GetSecondPoint(), secondPosition);

	triangle.SetPositionSecondPoint(excpectedPosition);
	VerifyVector2f(triangle.GetSecondPoint(), excpectedPosition);
}

BOOST_AUTO_TEST_CASE(has_a_third_point)
{
	VerifyVector2f(triangle.GetThirdPoint(), thirdPosition);

	triangle.SetPositionThirdPoint(excpectedPosition);
	VerifyVector2f(triangle.GetThirdPoint(), excpectedPosition);
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
	Fill color = #a0a0a0
	Perimeter = 4.83
	Area = 1
	Outline color = #0a0a0a
	Position first point = (1, 0)
	Position second point = (-1, 0)
	Position third point = (0, 1)
)";
	BOOST_CHECK_EQUAL(triangle.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()


struct DefaultTriangle_
{
	const float expectedLength = 0.f;
	const float expectedArea = 0.f;

	const sf::Vector2f defaultPosition = { 0.f, 0.f };

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
	BOOST_CHECK(static_cast<const CShape*>(&triangle));
}

BOOST_AUTO_TEST_CASE(has_color)
{
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), expectedOutlineColor);
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), expectedFillColor);
}


BOOST_AUTO_TEST_CASE(has_a_first_point)
{
	VerifyVector2f(triangle.GetFirstPoint(), defaultPosition);
}

BOOST_AUTO_TEST_CASE(has_a_second_point)
{
	VerifyVector2f(triangle.GetSecondPoint(), defaultPosition);
}

BOOST_AUTO_TEST_CASE(has_a_third_point)
{
	VerifyVector2f(triangle.GetThirdPoint(), defaultPosition);
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
	Fill color = #000000
	Perimeter = 0
	Area = 0
	Outline color = #000000
	Position first point = (0, 0)
	Position second point = (0, 0)
	Position third point = (0, 0)
)";
	BOOST_CHECK_EQUAL(triangle.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()