#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI& _windowApi) : Shape(_windowApi)
{
}

Circle::~Circle()
{
}

void Circle::setCenter(const Point& _center)
{
	center = make_unique<Point>(_center);
}

void Circle::setRadius(const int& _radius)
{
	if (_radius < 0) throw invalid_argument("Radius négatif non permis");
	radius = _radius;
}

void Circle::draw(const Color& _color) const
{
	if (center == nullptr) throw runtime_error("Aucun centre n'a été configuré");
	windowApi->setDrawingColor(_color);
	windowApi->drawCircle(*center, radius);

	if (fillColor.isVisible())
	{
		windowApi->fillCircle(*center, radius);
	}
}