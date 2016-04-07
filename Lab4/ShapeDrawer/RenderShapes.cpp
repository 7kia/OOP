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
			
		}
		else if(type == "Line")
		{
			renderShapes.push_back(ConvertDataLineInRenderLine(dynamic_cast<CLineSegment*>(shape.get())));
		}

	}
	return renderShapes;
}

std::shared_ptr<sf::RectangleShape> ConvertDataLineInRenderLine(const CLineSegment *data)
{
	std::shared_ptr<sf::RectangleShape> line(new sf::RectangleShape);

	SColor color = data->GetFillColor();
	line->setFillColor(sf::Color(color.red, color.blue, color.green));
	line->setSize(sf::Vector2f(DefaultParametresShape::thiknessLine, data->GetPerimeter()));
	line->setOrigin(DefaultParametresShape::originLine);
	line->setPosition(data->GetPositiionFirstPoint());

	float angle = atan2(DefaultParametresShape::originLine.x, DefaultParametresShape::originLine.y);

	sf::Vector2f coordinateSecondPointInZeroSystemCoordinates = data->GetPositiionSecondPoint();
	coordinateSecondPointInZeroSystemCoordinates -= data->GetPositiionFirstPoint();

	angle -= angle + atan2(coordinateSecondPointInZeroSystemCoordinates.x, coordinateSecondPointInZeroSystemCoordinates.y);

	line->setRotation(angle);

	return line;
}