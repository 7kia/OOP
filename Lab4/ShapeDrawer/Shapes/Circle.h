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

	void				SetPositionCenter(float x, float y);
	void				SetPositionCenter(sf::Vector2f position);
	sf::Vector2f		GetPosition() const;
private:
	void				AppendProperties(std::ostream & strm) const;
private:
	sf::Vector2f		m_positionCenter;
	float				m_radiuse = 0.f;
};

