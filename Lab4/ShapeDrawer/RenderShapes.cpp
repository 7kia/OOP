#include "stdafx.h"
#include "RenderShapes.h"

void Render(sf::RenderWindow & window, listRenderShapes& shapes)
{
	for (auto& shape : shapes)
	{
		window.draw(*shape);
	}
}


CShapeConverter::CShapeConverter()
{
}

CShapeConverter::CShapeConverter(const listDataShapes & data)
{
	m_renderShapes = ConvertDataShapesToRenderShapes(data);
}

CShapeConverter::~CShapeConverter()
{
}

listRenderShapes CShapeConverter::GetShapes() const
{
	return m_renderShapes;
};


listRenderShapes CShapeConverter::ConvertDataShapesToRenderShapes(const listDataShapes & data)
{
	std::string type;
	for (const auto& shape : data)
	{
		type = shape->GetType();
		if (type == "Point")
		{
			m_renderShapes.push_back(ConvertInRenderPoint(dynamic_cast<MyCPoint*>(shape.get())));
		}
		else if(type == "Line")
		{
			m_renderShapes.push_back(ConvertInRenderLine(dynamic_cast<CLineSegment*>(shape.get())));
		}
		else if (type == "Circle")
		{
			m_renderShapes.push_back(ConvertInRenderCircle(dynamic_cast<CCircle*>(shape.get())));
		}
		else if (type == "Rectangle")
		{
			m_renderShapes.push_back(ConvertInRenderRectangle(dynamic_cast<CRectangle*>(shape.get())));
		}
		else if (type == "Triangle")
		{
			m_renderShapes.push_back(ConvertInRenderTriangle(dynamic_cast<CTriangle*>(shape.get())));
		}
	}
	return m_renderShapes;
}

std::shared_ptr<sf::RectangleShape> CShapeConverter::ConvertInRenderLine(const CLineSegment *data)
{
	std::shared_ptr<sf::RectangleShape> line(new sf::RectangleShape);

	SColor color = data->GetFillColor();
	line->setFillColor(sf::Color(color.red, color.green, color.blue));
	line->setSize(sf::Vector2f(THIKNESS_LINE, data->GetPerimeter()));
	line->setOrigin(ORIGIN_LINE);
	line->setPosition(data->GetPositiionFirstPoint());

	sf::Vector2f coordinateSecondPointInZeroSystemCoordinates = data->GetPositiionSecondPoint();
	coordinateSecondPointInZeroSystemCoordinates -= data->GetPositiionFirstPoint();

	float angle = (atan2(coordinateSecondPointInZeroSystemCoordinates.x,
						coordinateSecondPointInZeroSystemCoordinates.y)) 
					* 180.f 
					/ M_PI;
	if (angle < 0) {
		angle += 180;
	}

	line->setRotation(angle);

	return line;
}


std::shared_ptr<sf::RectangleShape> CShapeConverter::ConvertInRenderRectangle(const CRectangle *data)
{
	std::shared_ptr<sf::RectangleShape> rectangle(new sf::RectangleShape);

	SColor fillColor = data->GetFillColor();
	rectangle->setFillColor(sf::Color(fillColor.red, fillColor.green, fillColor.blue));
	
	SColor outlineColor = data->GetOutlineColor();
	rectangle->setOutlineColor(sf::Color(outlineColor.red, outlineColor.green, outlineColor.blue));
	rectangle->setOutlineThickness(THIKNESS_LINE);

	rectangle->setSize(sf::Vector2f(data->GetWidth(), data->GetHeight()));
	rectangle->setOrigin(0.f, 0.f);// in SFML default anchor point in left top angle
	rectangle->setPosition(data->GetLeftTopPoint());

	return rectangle;
}


std::shared_ptr<sf::CircleShape> CShapeConverter::ConvertInRenderPoint(const MyCPoint * data)
{
	std::shared_ptr<sf::CircleShape> circle(new sf::CircleShape);

	SColor fillColor = data->GetFillColor();
	circle->setFillColor(sf::Color(fillColor.red, fillColor.green, fillColor.blue));

	circle->setOrigin(RADIUSE_POINT / 2, RADIUSE_POINT / 2);
	circle->setPosition(data->GetPosition());

	circle->setRadius(RADIUSE_POINT);

	return circle;
}


std::shared_ptr<sf::CircleShape> CShapeConverter::ConvertInRenderCircle(const CCircle * data)
{
	std::shared_ptr<sf::CircleShape> circle(new sf::CircleShape);

	SColor fillColor = data->GetFillColor();
	circle->setFillColor(sf::Color(fillColor.red, fillColor.green, fillColor.blue));

	SColor outlineColor = data->GetOutlineColor();
	circle->setOutlineColor(sf::Color(outlineColor.red, outlineColor.green, outlineColor.blue));
	circle->setOutlineThickness(THIKNESS_LINE);
	circle->setOrigin(data->GetRadiuse() / 2.f, data->GetRadiuse() / 2.f);
	circle->setPosition(data->GetPosition());

	circle->setRadius(data->GetRadiuse());

	return circle;
}


std::shared_ptr<sf::ConvexShape> CShapeConverter::ConvertInRenderTriangle(const CTriangle * data)
{
	std::shared_ptr<sf::ConvexShape> triangle(new sf::ConvexShape);

	triangle->setPointCount(3);

	triangle->setPoint(0, data->GetFirstPoint());
	triangle->setPoint(1, data->GetSecondPoint());
	triangle->setPoint(2, data->GetThirdPoint());

	SColor fillColor = data->GetFillColor();
	triangle->setFillColor(sf::Color(fillColor.red, fillColor.green, fillColor.blue));

	SColor outlineColor = data->GetOutlineColor();
	triangle->setOutlineColor(sf::Color(outlineColor.red, outlineColor.green, outlineColor.blue));
	triangle->setOutlineThickness(THIKNESS_LINE);

	return triangle;
}
