#pragma once

#include "MyCPoint.h"

class CLineSegment final :
	public IShape
{
public:
	CLineSegment();
	CLineSegment(sf::Vector2f firstPoint, sf::Vector2f secondPoint, SColor color);
	~CLineSegment();

	float				GetPerimeter() const override;
	float				GetArea() const override;
	std::string			GetStringPresentation() const override;

	void				SetPositionFirstPoint(sf::Vector2f position);
	void				SetPositionFirstPoint(float x, float y);
	sf::Vector2f		GetPositiionFirstPoint() const;

	void				SetPositionSecondPoint(sf::Vector2f position);
	void				SetPositionSecondPoint(float x, float y);
	sf::Vector2f		GetPositiionSecondPoint() const;

private:
	MyCPoint			m_firstPoint;
	MyCPoint			m_secondPoint;
};