#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "SorterShapes\ShapeReader.h"

typedef std::vector<std::shared_ptr<sf::Shape>> listRenderShapes;

namespace DefaultParametresShape
{
	static const float thiknessLine = 5;
	sf::Vector2f originLine = { DefaultParametresShape::thiknessLine / 2.f, 0.f };

};

listRenderShapes ConvertDataShapesToRenderShapes(const listDataShapes & data);
void Render(sf::RenderWindow & window, listDataShapes &shapes);