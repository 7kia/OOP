#include "stdafx.h"
#include "TestApplication.h"

BOOST_AUTO_TEST_SUITE(ApplicationTestModule)

BOOST_AUTO_TEST_CASE(Check_empty_rectangle)
{
	CRectangle rect;

	BOOST_CHECK(rect.GetLeftTopPoint() == Vector2I(0, 0));
	BOOST_CHECK(rect.GetWidth() == 0);
	BOOST_CHECK(rect.GetHeight() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
