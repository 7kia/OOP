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
			CLineSegment* dataLine = dynamic_cast<CLineSegment*>(shape.get());
			std::shared_ptr<sf::RectangleShape> line(new sf::RectangleShape);

			SColor color = shape->GetFillColor();
			line->setFillColor(sf::Color(color.red, color.blue, color.green));

			line->setSize(sf::Vector2f(DefaultParametresShape::thiknessLine, shape->GetPerimeter()));

			line->setOrigin(DefaultParametresShape::originLine);
			//
			float angle = atan2(DefaultParametresShape::originLine.x, DefaultParametresShape::originLine.y);

			sf::Vector2f coordinateSecondPointInZeroSystemCoordinates = dataLine->GetPositiionSecondPoint();
			coordinateSecondPointInZeroSystemCoordinates -= dataLine->GetPositiionFirstPoint();

			angle -= angle + atan2(coordinateSecondPointInZeroSystemCoordinates.x, coordinateSecondPointInZeroSystemCoordinates.y);

			line->setRotation(angle);
			//
			line->setPosition(dataLine->GetPositiionFirstPoint());
			////////////
			renderShapes.push_back(line);
		}

	}
	return renderShapes;
}
