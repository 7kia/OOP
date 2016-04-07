#include "stdafx.h"
#include "TestDrawer.h"



struct Drawer_
{
	CShapeReader reader;
	CShapeConverter converter;

	listRenderShapes renderShapes;
	const float THIKNESS_LINE = 5;
	const sf::Vector2f ORIGIN_LINE = { THIKNESS_LINE / 2.f, 0.f };
	const float RADIUSE_POINT = 2.f;

	const int amountShapes = 5;
	const int indexPoint = 0;
	const int indexRectangle = 1;
	const int indexCircle = 2;
	const int indexTriangle = 3;

	const int indexLine = 4;

	Drawer_()
	{
		reader.ReadShapes("renderShapes.txt");
		renderShapes = converter.ConvertDataShapesToRenderShapes(reader.GetShapes());
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

BOOST_AUTO_TEST_CASE(convert_point)
{
	sf::CircleShape* pPoint = dynamic_cast<sf::CircleShape*>(&*renderShapes[indexPoint]);
	MyCPoint* pDataPoint = dynamic_cast<MyCPoint*>(&*reader.GetShapes()[indexPoint]);

	sf::CircleShape circle;
	sf::Color expectedFillColor(16, 240, 48);
	sf::Vector2f expectedOrigin(RADIUSE_POINT / 2, RADIUSE_POINT / 2);
	sf::Vector2f expectedPosition(25.f, 25.f);
	float expectedRadiuse = RADIUSE_POINT;

	circle.setFillColor(expectedFillColor);
	VerifyColor(circle.getFillColor(), pDataPoint->GetFillColor());

	circle.setOrigin(expectedOrigin);
	VerifyVector2f(circle.getOrigin(), expectedOrigin);

	circle.setPosition(expectedPosition);
	VerifyVector2f(circle.getPosition(), pDataPoint->GetPosition());

	circle.setRadius(expectedRadiuse);
	BOOST_CHECK_EQUAL(circle.getRadius(), expectedRadiuse);
}

BOOST_AUTO_TEST_CASE(convert_line)
{
	sf::RectangleShape* pPoint = dynamic_cast<sf::RectangleShape*>(&*renderShapes[indexLine]);
	CLineSegment* pDataLine = dynamic_cast<CLineSegment*>(&*reader.GetShapes()[indexLine]);


	sf::RectangleShape line;
	sf::Color expectedFillColor(255, 255, 255);
	sf::Vector2f expectedOrigin(ORIGIN_LINE);

	sf::Vector2f firstPosition = { 250.f, 250.f };
	sf::Vector2f secondPosition = { 300.f, 300.f };
	sf::Vector2f difference = secondPosition - firstPosition;

	float length = std::sqrt(difference.x * difference.x + difference.y * difference.y);
	sf::Vector2f expectedSize(THIKNESS_LINE, length);
	float expectedRadiuse = RADIUSE_POINT;

	sf::Vector2f expectedPosition(firstPosition);

	line.setFillColor(expectedFillColor);
	VerifyColor(line.getFillColor(), pDataLine->GetFillColor());

	line.setSize(expectedSize);
	VerifyVector2f(line.getSize(), sf::Vector2f(THIKNESS_LINE, pDataLine->GetPerimeter()));

	line.setOrigin(expectedOrigin);
	VerifyVector2f(line.getOrigin(), expectedOrigin);

	line.setPosition(expectedPosition);
	VerifyVector2f(line.getPosition(), pDataLine->GetPositiionFirstPoint());



	float expectedAngle = 45.f;

	sf::Vector2f coordinateSecondPointInZeroSystemCoordinates = secondPosition;
	coordinateSecondPointInZeroSystemCoordinates -= firstPosition;

	float angle = (atan2(coordinateSecondPointInZeroSystemCoordinates.x,
		coordinateSecondPointInZeroSystemCoordinates.y))
		* 180.f
		/ M_PI;
	if (angle < 0) {
		angle += 360;
	}

	BOOST_CHECK(IsEqual(angle, expectedAngle));
}

BOOST_AUTO_TEST_CASE(convert_triangle)
{
	sf::ConvexShape* pTriangle = dynamic_cast<sf::ConvexShape*>(&*renderShapes[indexTriangle]);
	CTriangle* pDataTriangle = dynamic_cast<CTriangle*>(&*reader.GetShapes()[indexTriangle]);

	sf::Vector2f firstPosition = { 200.f, 100.f };
	sf::Vector2f secondPosition = { 300.f, 200.f };
	sf::Vector2f thirdPosition = { 100.f, 200.f };

	pTriangle->setPointCount(3);

	pTriangle->setPoint(0, pDataTriangle->GetFirstPoint());
	VerifyVector2f(pTriangle->getPoint(0), firstPosition);

	pTriangle->setPoint(1, pDataTriangle->GetSecondPoint());
	VerifyVector2f(pTriangle->getPoint(1), secondPosition);

	pTriangle->setPoint(2, pDataTriangle->GetThirdPoint());
	VerifyVector2f(pTriangle->getPoint(2), thirdPosition);


	sf::Color expectedFillColor(160, 160, 160);
	sf::Color expectedOutlineColor(192, 2, 2);

	pTriangle->setFillColor(expectedFillColor);
	VerifyColor(pTriangle->getFillColor(), pDataTriangle->GetFillColor());
	
	pTriangle->setFillColor(expectedOutlineColor);
	VerifyColor(pTriangle->getOutlineColor(), pDataTriangle->GetOutlineColor());

	float expectedThikness = THIKNESS_LINE;
	pTriangle->setOutlineThickness(expectedThikness);
	BOOST_CHECK_EQUAL(pTriangle->getOutlineThickness(), THIKNESS_LINE);

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
