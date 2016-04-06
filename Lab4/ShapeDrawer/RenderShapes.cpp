#include "RenderShapes.h"

void Render(sf::RenderWindow & window, const listRenderShapes& shapes)
{
	for (auto& shape : shapes)
	{
		window.draw(*shape);
	}
}

listRenderShapes ConvertDataShapesToRenderShapes(listDataShapes & data)
{
	std::string type;
	for (const auto& shape : data)
	{
		type = shape->GetType();
		if (type == "Point")
		{
			
		}
		else if(type == "Line")
		{
			sf::RectangleShape line;
			SColor color = shape->GetFillColor();
			line.setFillColor(sf::Color(color.red, color.blue, color.green));
			line.setSize(sf::Vector2f(DefaultParametresShape::thiknessLine, shape->GetPerimeter()));

			line.setOrigin(DefaultParametresShape::originLine);

			float angle = atan2(DefaultParametresShape::originLine.x, DefaultParametresShape::originLine.y);
			angle -= angle + ;

			line.setRotation()
		}

	}
	//return std::vector<std::shared_ptr<IShape>>();
}
