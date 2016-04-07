#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "main.h"

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(960, 600), "SFML works!", sf::Style::Close);

	CShapeReader reader("composition.txt");
	CShapeConverter converter(reader.GetShapes());
	listRenderShapes renderShapes = converter.GetShapes();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();

		Render(window, renderShapes);

		window.display();

	}

	return 0;
}