#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Close);

	CShapeReader reader("composition.txt");
	listRenderShapes renderShapes = ConvertDataShapesToRenderShapes(reader.GetShapes());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();

		Render(window, renderShapes);
	}

	return 0;
}