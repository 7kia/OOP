#pragma once

#include "ISolidShape.h"

class CCircle final :
	public ISolidShape
{
public:
	CCircle();
	CCircle(sf::Vector2f center, float radiuse,
			SColor fillColor, SColor outlineColor);
	~CCircle();

	float				GetPerimeter() const override;
	float				GetArea() const override;
	std::string			GetStringPresentation() const override;

	void				SetRadiuse(float radiuse);
	float				GetRadiuse() const;
private:
	sf::Vector2f		m_positionCenter;
	float				m_radiuse = 0.f;
};

