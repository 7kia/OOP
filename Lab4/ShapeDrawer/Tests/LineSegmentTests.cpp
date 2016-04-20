#include "stdafx.h"
#include "LineSegmentTests.h"

struct LineSegment_
{
	const float expectedLength = 1.414f;
	const float expectedArea = 0.f;

	const SColor expectedFillColor;
	const SColor expectedColorForSetVectorMethod;

	const uint8_t expectedRed;
	const uint8_t expectedGreen;
	const uint8_t expectedBlue;

	const sf::Vector2f firstPosition = { 0.f, 0.f };
	const sf::Vector2f secondPosition = { 1.f, 1.f };
	const sf::Vector2f expectedPosition = { 2.f, -4.f };

	CLineSegment line;
	LineSegment_()
		: expectedFillColor(16, 16, 16)
		, expectedColorForSetVectorMethod(1, 2, 3)
		, expectedRed(4)
		, expectedGreen(5)
		, expectedBlue(6)
		, line(firstPosition, secondPosition, expectedFillColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(LineSegment, LineSegment_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const CShape*>(&line));
}

BOOST_AUTO_TEST_CASE(has_color_fill_color)
{
	BOOST_CHECK_EQUAL(line.GetFillColor(), expectedFillColor);

	line.SetFillColor(expectedColorForSetVectorMethod);
	BOOST_CHECK_EQUAL(line.GetFillColor(), expectedColorForSetVectorMethod);

	line.SetFillColor(expectedRed, expectedGreen, expectedBlue);
	BOOST_CHECK_EQUAL(line.GetFillColor(), SColor(expectedRed, expectedGreen, expectedBlue));
}

BOOST_AUTO_TEST_CASE(has_first_point)
{
	VerifyVector2f(line.GetPositiionFirstPoint(), firstPosition);

	line.SetPositionFirstPoint(expectedPosition);
	VerifyVector2f(line.GetPositiionFirstPoint(), expectedPosition);
}

BOOST_AUTO_TEST_CASE(has_second_point)
{
	VerifyVector2f(line.GetPositiionSecondPoint(), secondPosition);

	line.SetPositionSecondPoint(expectedPosition);
	VerifyVector2f(line.GetPositiionSecondPoint(), expectedPosition);
}

BOOST_AUTO_TEST_CASE(has_a_length)//"$(TargetPath)" --log_level=test_suite
{
	BOOST_CHECK(IsEqual(line.GetPerimeter(), expectedLength));
}

BOOST_AUTO_TEST_CASE(not_has_a_area)
{
	BOOST_CHECK(IsEqual(line.GetArea(), expectedArea));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Line:
	Fill color = #101010
	Perimeter = 1.41
	Area = 0
	Position first point = (0, 0)
	Position second point = (1, 1)
)";
	BOOST_CHECK_EQUAL(line.GetStringPresentation(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()


struct DefaultLineSegment_
{
	const float expectedLength = 0.f;
	const float expectedArea = 0.f;
	const SColor expectedFillColor;
	const CLineSegment line;
	DefaultLineSegment_()
		: expectedFillColor(0, 0, 0)
	{}

};
BOOST_FIXTURE_TEST_SUITE(DefaultLineSegment, DefaultLineSegment_)
BOOST_AUTO_TEST_CASE(is_a_shape)
{
	BOOST_CHECK(static_cast<const CShape*>(&line));
}

BOOST_AUTO_TEST_CASE(has_color)
{
	BOOST_CHECK_EQUAL(line.GetFillColor(), expectedFillColor);
}

BOOST_AUTO_TEST_CASE(not_has_a_length)//"$(TargetPath)" --log_level=test_suite
{
	BOOST_CHECK(IsEqual(line.GetPerimeter(), expectedLength));
}

BOOST_AUTO_TEST_CASE(not_has_a_area)
{
	BOOST_CHECK(IsEqual(line.GetArea(), expectedArea));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Line:
	Fill color = #000000
	Perimeter = 0
	Area = 0
	Position first point = (0, 0)
	Position second point = (0, 0)
)";
	BOOST_CHECK_EQUAL(line.GetStringPresentation(), expectedString);
}

BOOST_AUTO_TEST_SUITE_END()

