// Tests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "../Rectangle.h"

BOOST_AUTO_TEST_SUITE(RectangleTestModule)

BOOST_AUTO_TEST_CASE(Check_empty_rectangle)
{
	CRectangle rect;

	BOOST_CHECK(rect.GetLeftTopPoint() == Vector2I(0, 0));
	BOOST_CHECK(rect.GetWidth() == 0);
	BOOST_CHECK(rect.GetHeight() == 0);
}

BOOST_AUTO_TEST_CASE(Check_rectangle_with_negative_members)
{
	CRectangle rect(Vector2I(1,1), -1, -1);

	BOOST_CHECK(rect.GetWidth() == 0);
	BOOST_CHECK(rect.GetHeight() == 0);
}

BOOST_AUTO_TEST_CASE(Check_rectangle_set_and_get_functions)
{
	int x = 1;
	int y = 1;
	int width = 2;
	int height = 3;
	CRectangle rect(Vector2I(x, y), width, height);

	BOOST_CHECK(rect.GetLeftTopPoint() == Vector2I(x, y));
	BOOST_CHECK(rect.GetWidth() == width);
	BOOST_CHECK(rect.GetHeight() == height);

	BOOST_CHECK(rect.GetArea() == (width * height));
	BOOST_CHECK(rect.GetPerimeter() == ((width + height) * 2));

	BOOST_CHECK(rect.GetTop() == y);
	BOOST_CHECK(rect.GetBottom() == (y + height));
	BOOST_CHECK(rect.GetLeft() == x);
	BOOST_CHECK(rect.GetRight() == (x + width));
}

BOOST_AUTO_TEST_SUITE_END()

