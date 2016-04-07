#include "stdafx.h"
#include "RenderShapes.h"

void Render(sf::RenderWindow & window, listRenderShapes& shapes)
{
	for (auto& shape : shapes)
	{
		window.draw(*shape);
	}
}

listRenderShapes ConvertDataShapesToRenderShapes(listDataShapes & data)
{
	listRenderShapes renderShapes;

	std::string type;
	for (const auto& shape : data)
	{
		type = shape->GetType();
		if (type == "Point")
		{
			renderShapes.push_back(ConvertInRenderPoint(dynamic_cast<MyCPoint*>(shape.get())));
		}
		else if(type == "Line")
		{
			renderShapes.push_back(ConvertInRenderLine(dynamic_cast<CLineSegment*>(shape.get())));
		}
		else if (type == "Circle")
		{
			renderShapes.push_back(ConvertInRenderCircle(dynamic_cast<CCircle*>(shape.get())));
		}
	}
	return renderShapes;
}

std::shared_ptr<sf::RectangleShape> ConvertInRenderLine(const CLineSegment *data)
{
	std::shared_ptr<sf::RectangleShape> line(new sf::RectangleShape);

	SColor color = data->GetFillColor();
	line->setFillColor(sf::Color(color.red, color.blue, color.green));
	line->setSize(sf::Vector2f(DefaultParametresShape::thiknessLine, data->GetPerimeter()));
	line->setOrigin(DefaultParametresShape::originLine);
	line->setPosition(data->GetPositiionFirstPoint());

	sf::Vector2f coordinateSecondPointInZeroSystemCoordinates = data->GetPositiionSecondPoint();
	coordinateSecondPointInZeroSystemCoordinates -= data->GetPositiionFirstPoint();

	float angle = (atan2(coordinateSecondPointInZeroSystemCoordinates.x, coordinateSecondPointInZeroSystemCoordinates.y)) * 180 / M_PI;
	if (angle < 0) {
		angle += 360;
	}

	line->setRotation(angle);

	return line;
}

std::shared_ptr<sf::CircleShape> ConvertInRenderPoint(const MyCPoint * data)
{
	std::shared_ptr<sf::CircleShape> circle(new sf::CircleShape);

	SColor fillColor = data->GetFillColor();
	circle->setFillColor(sf::Color(fillColor.red, fillColor.blue, fillColor.green));

	circle->setOrigin(DefaultParametresShape::radiusePoint / 2, DefaultParametresShape::radiusePoint / 2);
	circle->setPosition(data->GetPosition());

	circle->setRadius(DefaultParametresShape::radiusePoint);

	return circle;
}

std::shared_ptr<sf::CircleShape> ConvertInRenderCircle(const CCircle * data)
{
	std::shared_ptr<sf::CircleShape> circle(new sf::CircleShape);

	SColor fillColor = data->GetFillColor();
	circle->setFillColor(sf::Color(fillColor.red, fillColor.blue, fillColor.green));

	SColor outlineColor = data->GetOutlineColor();
	circle->setOutlineColor(sf::Color(outlineColor.red, outlineColor.blue, outlineColor.green));
	circle->setOutlineThickness(DefaultParametresShape::thiknessLine);
	circle->setOrigin(data->GetRadiuse(), data->GetRadiuse());
	circle->setPosition(data->GetPosition());

	circle->setRadius(data->GetRadiuse());

	return circle;
}
