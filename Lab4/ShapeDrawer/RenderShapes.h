#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "SorterShapes\ShapeReader.h"

typedef std::vector<std::shared_ptr<sf::Shape>> ListRenderShapes;

class CShapeConverter
{
public:
	CShapeConverter();
	CShapeConverter(const ListDataShapes & data);
	~CShapeConverter();


	ListRenderShapes						GetShapes() const;
	ListRenderShapes						ConvertDataShapesToRenderShapes(const ListDataShapes & data);

public:
	const float THIKNESS_LINE = 5;
	const sf::Vector2f ORIGIN_LINE = { THIKNESS_LINE / 2.f, 0.f };
	const float RADIUSE_POINT = 2.f;
private:

	std::shared_ptr<sf::CircleShape>		ConvertInRenderPoint(const MyCPoint * data);
	std::shared_ptr<sf::RectangleShape>		ConvertInRenderLine(const CLineSegment *data);
	std::shared_ptr<sf::RectangleShape>		ConvertInRenderRectangle(const CRectangle *data);
	std::shared_ptr<sf::CircleShape>		ConvertInRenderCircle(const CCircle *data);
	std::shared_ptr<sf::ConvexShape>		ConvertInRenderTriangle(const CTriangle * data);
private:
	ListRenderShapes						m_renderShapes;
};


void Render(sf::RenderWindow & window, ListRenderShapes &shapes);