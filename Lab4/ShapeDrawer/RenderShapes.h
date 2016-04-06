#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Shapes\Shapes.h"

typedef std::vector<std::shared_ptr<sf::Shape>> listRenderShapes;

void Render(sf::RenderWindow & window, const std::vector<std::shared_ptr<IShape>> &shapes);