#include "stdafx.h"
#include "TestDrawer.h"



struct Drawer_
{
	CShapeReader reader;
	CShapeConverter converter;
	Drawer_()
	{
		reader.ReadShapes("shapes1.txt");
	}
};

BOOST_FIXTURE_TEST_SUITE(Drawer, Drawer_)

BOOST_AUTO_TEST_CASE(convert_point)
{
	BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(convert_line)
{
	BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(convert_triangle)
{
	BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(convert_rectangle)
{
	BOOST_CHECK(false);
}

BOOST_AUTO_TEST_CASE(convert_circle)
{
	BOOST_CHECK(false);
}

BOOST_AUTO_TEST_SUITE_END()
