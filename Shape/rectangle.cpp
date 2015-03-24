#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowApi) : Shape(_windowApi)
{
	width = 0;
	height = 0;
}

Rectangle::~Rectangle()
{
}

void Rectangle::setPosition(const Point& _position)
{
	add(_position);
}

void Rectangle::setHeight(const int& _height)
{
	if (_height < 0) throw invalid_argument("Hauteur négative non permise.");
	height = _height;
}

void Rectangle::setWidth(const int& _width)
{
	if (_width < 0) throw invalid_argument("Largeur négative non permise.");
	width = _width;
}

void Rectangle::draw() const
{
	if (getPoints().size() == 0) throw runtime_error("Aucune position n'a été configurée!");

	if (getFillColor().isVisible())
	{
		windowApi->setDrawingColor(getFillColor());
		windowApi->fillRectangle(getPoints().back(), width, height);
	}

	if (getLineColor().isVisible())
	{
		windowApi->setDrawingColor(getLineColor());
		windowApi->drawRectangle(getPoints().back(), width, height);
	}
}