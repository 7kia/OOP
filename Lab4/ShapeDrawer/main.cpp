#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "main.h"


void Render(sf::RenderWindow & window, ListRenderShapes& shapes)
{
	window.clear();

	for (auto& shape : shapes)
	{
		window.draw(*shape);
	}

	window.display();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 600), "SFML works!", sf::Style::Close);

	CShapeReader reader("composition.txt");
	ListRenderShapes renderShapes = ConvertDataShapesToRenderShapes(reader.GetShapes());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Render(window, renderShapes);
	}

	return 0;
}