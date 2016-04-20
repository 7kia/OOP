#include "stdafx.h"
#include "TestDrawer.h"



struct Drawer_
{
	CShapeReader reader;

	ListRenderShapes renderShapes;
	const float THIKNESS_LINE = 5;
	const sf::Vector2f ORIGIN_LINE = { THIKNESS_LINE / 2.f, 0.f };
	const float RADIUSE_POINT = 2.f;

	const int amountShapes = 5;
	const int indexPoint = 0;
	const int indexRectangle = 1;
	const int indexCircle = 2;
	const int indexTriangle = 3;
	const int indexLine = 4;

	sf::CircleShape point;
	sf::CircleShape circle;
	float expectedRadiuse = 40.f;

	sf::RectangleShape line;
	sf::Vector2f firstPositionLine = { 250.f, 250.f };
	sf::Vector2f secondPositionLine = { 300.f, 300.f };

	sf::ConvexShape triangle;
	sf::Vector2f firstPositionTriangle = { 200.f, 100.f };
	sf::Vector2f secondPositionTriangle = { 300.f, 200.f };
	sf::Vector2f thirdPositionTriangle = { 100.f, 200.f };

	sf::RectangleShape rectangle;

	Drawer_()
	{
		reader.ReadShapes("renderShapes.txt");
		renderShapes = ConvertDataShapesToRenderShapes(reader.GetShapes());
	}
};

BOOST_FIXTURE_TEST_SUITE(Drawer, Drawer_)

BOOST_AUTO_TEST_CASE(size_shape_list_is_correct)
{
	BOOST_CHECK_EQUAL(reader.GetShapes().size(), amountShapes);
}

BOOST_AUTO_TEST_CASE(indexes_shape_is_correct)
{
	BOOST_CHECK_EQUAL(reader.GetShapes()[indexPoint]->GetType(), "Point");
	BOOST_CHECK_EQUAL(reader.GetShapes()[indexLine]->GetType(), "Line");
	BOOST_CHECK_EQUAL(reader.GetShapes()[indexRectangle]->GetType(), "Rectangle");
	BOOST_CHECK_EQUAL(reader.GetShapes()[indexCircle]->GetType(), "Circle");
	BOOST_CHECK_EQUAL(reader.GetShapes()[indexTriangle]->GetType(), "Triangle");
}


///////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(ConvertToPointTestModule)

BOOST_AUTO_TEST_CASE(fill_color_is_correct)
{
	sf::CircleShape* pPoint = dynamic_cast<sf::CircleShape*>(&*renderShapes[indexPoint]);

	sf::Color expectedFillColor(16, 240, 48);
	point.setFillColor(expectedFillColor);
	VerifyColor(point.getFillColor(), pPoint->getFillColor());
}

BOOST_AUTO_TEST_CASE(origin_is_correct)
{
	sf::Vector2f expectedOrigin(RADIUSE_POINT / 2, RADIUSE_POINT / 2);
	point.setOrigin(expectedOrigin);
	VerifyVector2f(point.getOrigin(), expectedOrigin);
}

BOOST_AUTO_TEST_CASE(position_is_correct)
{
	sf::CircleShape* pPoint = dynamic_cast<sf::CircleShape*>(&*renderShapes[indexPoint]);

	sf::Vector2f expectedPosition(25.f, 25.f);
	point.setPosition(expectedPosition);
	VerifyVector2f(point.getPosition(), pPoint->getPosition());
}

BOOST_AUTO_TEST_CASE(radiuse_is_correct)
{
	point.setRadius(RADIUSE_POINT);
	BOOST_CHECK_EQUAL(point.getRadius(), RADIUSE_POINT);
}

BOOST_AUTO_TEST_SUITE_END()

/////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(ConvertToLineTestModule)

BOOST_AUTO_TEST_CASE(fill_color_is_correct)
{
	sf::RectangleShape* pRectangle = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexLine]);

	sf::Color expectedFillColor(255, 255, 255);
	line.setFillColor(expectedFillColor);
	VerifyColor(line.getFillColor(), pRectangle->getFillColor());
}

BOOST_AUTO_TEST_CASE(size_is_correct)
{
	sf::RectangleShape* pRectangle = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexLine]);

	sf::Vector2f difference = secondPositionLine - firstPositionLine;

	float length = std::sqrt(difference.x * difference.x + difference.y * difference.y);
	sf::Vector2f expectedSize(THIKNESS_LINE, length);

	line.setSize(expectedSize);
	VerifyVector2f(line.getSize(), pRectangle->getSize());
}

BOOST_AUTO_TEST_CASE(origin_is_correct)
{
	sf::RectangleShape* pRectangle = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexLine]);

	sf::Vector2f expectedOrigin(ORIGIN_LINE);

	line.setOrigin(expectedOrigin);
	VerifyVector2f(line.getOrigin(), pRectangle->getOrigin());
}

BOOST_AUTO_TEST_CASE(position_is_correct)
{
	sf::RectangleShape* pRectangle = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexLine]);

	sf::Vector2f expectedPosition(firstPositionLine);
	line.setPosition(expectedPosition);
	VerifyVector2f(line.getPosition(), pRectangle->getPosition());
}

BOOST_AUTO_TEST_CASE(angle_is_correct)
{
	float expectedAngle = 45.f;

	sf::Vector2f coordinateSecondPointInZeroSystemCoordinates = secondPositionLine;
	coordinateSecondPointInZeroSystemCoordinates -= firstPositionLine;

	float angle = (atan2(coordinateSecondPointInZeroSystemCoordinates.x,
		coordinateSecondPointInZeroSystemCoordinates.y))
		* 180.f
		/ static_cast<float>(M_PI);
	if (angle < 0) {
		angle += 360;
	}

	BOOST_CHECK(IsEqual(angle, expectedAngle));
}

BOOST_AUTO_TEST_SUITE_END()
///////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(ConvertToTriangleTestModule)

BOOST_AUTO_TEST_CASE(positions_points_is_correct)
{
	sf::ConvexShape* pTriangle = dynamic_cast<sf::ConvexShape*>(&*renderShapes[indexTriangle]);

	triangle.setPointCount(3);

	triangle.setPoint(0, firstPositionTriangle);
	VerifyVector2f(pTriangle->getPoint(0), triangle.getPoint(0));

	triangle.setPoint(1, secondPositionTriangle);
	VerifyVector2f(pTriangle->getPoint(1), triangle.getPoint(1));

	triangle.setPoint(2, thirdPositionTriangle);
	VerifyVector2f(pTriangle->getPoint(2), triangle.getPoint(2));
}

BOOST_AUTO_TEST_CASE(fill_color_is_correct)
{
	sf::ConvexShape* pTriangle = dynamic_cast<sf::ConvexShape*>(&*renderShapes[indexTriangle]);

	sf::Color expectedFillColor(160, 160, 160);
	triangle.setFillColor(expectedFillColor);
	VerifyColor(triangle.getFillColor(), pTriangle->getFillColor());
}

BOOST_AUTO_TEST_CASE(outline_color_is_correct)
{
	sf::ConvexShape* pTriangle = dynamic_cast<sf::ConvexShape*>(&*renderShapes[indexTriangle]);

	sf::Color expectedOutlineColor(192, 2, 2);
	triangle.setOutlineColor(expectedOutlineColor);
	VerifyColor(triangle.getOutlineColor(), pTriangle->getOutlineColor());
}

BOOST_AUTO_TEST_CASE(thikness_is_correct)
{
	float expectedThikness = THIKNESS_LINE;
	triangle.setOutlineThickness(expectedThikness);
	BOOST_CHECK_EQUAL(triangle.getOutlineThickness(), expectedThikness);
}

BOOST_AUTO_TEST_SUITE_END()
///////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(ConvertToRectangleTestModule)

BOOST_AUTO_TEST_CASE(fill_color_is_correct)
{
	sf::RectangleShape* pRectangle = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexRectangle]);

	sf::Color expectedFillColor(51, 68, 85);
	rectangle.setFillColor(expectedFillColor);
	VerifyColor(rectangle.getFillColor(), pRectangle->getFillColor());
}

BOOST_AUTO_TEST_CASE(outline_color_is_correct)
{
	sf::RectangleShape* pRectangle = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexRectangle]);

	sf::Color expectedOutlineColor(170, 255, 221);
	rectangle.setOutlineColor(expectedOutlineColor);
	VerifyColor(rectangle.getOutlineColor(), pRectangle->getOutlineColor());
}

BOOST_AUTO_TEST_CASE(size_is_correct)
{
	sf::RectangleShape* pRectangle = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexRectangle]);

	sf::Vector2f expectedSize(200.f, 300.f);
	rectangle.setSize(expectedSize);
	VerifyVector2f(pRectangle->getSize(), rectangle.getSize());
}

BOOST_AUTO_TEST_CASE(origin_is_correct)
{
	sf::RectangleShape* pRectangle = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexRectangle]);

	sf::Vector2f expectedOrigin(0.f, 0.f);
	rectangle.setOrigin(expectedOrigin);
	VerifyVector2f(pRectangle->getOrigin(), rectangle.getOrigin());
}

BOOST_AUTO_TEST_CASE(position_is_correct)
{
	sf::RectangleShape* pRectangle = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexRectangle]);

	sf::Vector2f expectedPosition(100.f, 100.f);
	rectangle.setPosition(expectedPosition);
	VerifyVector2f(pRectangle->getPosition(), rectangle.getPosition());
}

BOOST_AUTO_TEST_SUITE_END()
///////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(ConvertToCircleTestModule)

BOOST_AUTO_TEST_CASE(fill_color_is_correct)
{
	sf::CircleShape* pCircle = dynamic_cast<sf::CircleShape*>(&*renderShapes[indexCircle]);

	sf::Color expectedFillColor(170, 9, 144);
	circle.setFillColor(expectedFillColor);
	VerifyColor(circle.getFillColor(), pCircle->getFillColor());
}

BOOST_AUTO_TEST_CASE(outline_color_is_correct)
{
	sf::CircleShape* pCircle = dynamic_cast<sf::CircleShape*>(&*renderShapes[indexCircle]);

	sf::Color expectedOutlineColor(173, 173, 173);
	circle.setOutlineColor(expectedOutlineColor);
	VerifyColor(circle.getOutlineColor(), pCircle->getOutlineColor());
}

BOOST_AUTO_TEST_CASE(position_is_correct)
{
	sf::CircleShape* pCircle = dynamic_cast<sf::CircleShape*>(&*renderShapes[indexCircle]);

	sf::Vector2f expectedPosition(450.f, 450.f);
	circle.setPosition(expectedPosition);
	VerifyVector2f(pCircle->getPosition(), circle.getPosition());
}

BOOST_AUTO_TEST_CASE(radiuse_is_correct)
{
	sf::CircleShape* pCircle = dynamic_cast<sf::CircleShape*>(&*renderShapes[indexCircle]);

	circle.setRadius(expectedRadiuse);
	BOOST_CHECK_EQUAL(circle.getRadius(), pCircle->getRadius());
}

BOOST_AUTO_TEST_CASE(origin_is_correct)
{
	sf::CircleShape* pCircle = dynamic_cast<sf::CircleShape*>(&*renderShapes[indexCircle]);

	sf::Vector2f expectedOrigin(expectedRadiuse / 2, expectedRadiuse / 2);
	circle.setOrigin(expectedOrigin);
	VerifyVector2f(circle.getOrigin(), pCircle->getOrigin());
}

BOOST_AUTO_TEST_CASE(thikness_is_correct)
{
	float expectedThikness = THIKNESS_LINE;
	circle.setOutlineThickness(expectedThikness);
	BOOST_CHECK_EQUAL(circle.getOutlineThickness(), expectedThikness);
}

BOOST_AUTO_TEST_SUITE_END()
///////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
