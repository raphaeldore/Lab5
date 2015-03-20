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
	add(_center);
}

void Circle::setRadius(const int& _radius)
{
	if (_radius < 0) throw invalid_argument("Radius négatif non permis");
	radius = _radius;
}

void Circle::draw() const
{
	if (getPoints().size() == 0) throw runtime_error("Aucun centre n'a été configuré");

	if (getFillColor().isVisible())
	{
		windowApi->setDrawingColor(getFillColor());
		windowApi->fillCircle(getPoints().back(), radius);
	}

	windowApi->setDrawingColor(getLineColor());
	windowApi->drawCircle(getPoints().back(), radius);
}