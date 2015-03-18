#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowApi) : Shape(_windowApi)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::setPosition(const Point& _position)
{
	position = make_unique<Point>(_position);
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
	if (position == nullptr) throw runtime_error("Aucune position n'a été configurée!");
	windowApi->setDrawingColor(lineColor);
	windowApi->drawRectangle(*position, width, height);

	if (fillColor.isVisible())
	{
		windowApi->fillRectangle(*position, width, height);
	}
}