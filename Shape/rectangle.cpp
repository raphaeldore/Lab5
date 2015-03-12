#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowApi) : windowApi(&_windowApi), position(0, 0)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::setPosition(const Point& _position)
{
	position = _position;
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

void Rectangle::setFillColor(const Color& _fillColor)
{
	Shape::setFillColor(_fillColor);
}

void Rectangle::setLineColor(const Color& _lineColor)
{
	Shape::setLineColor(_lineColor);
}

void Rectangle::draw(const Color& _color)
{
	windowApi->setDrawingColor(_color);
	windowApi->drawRectangle(position, width, height);

	if (fillColor.isVisible())
	{
		windowApi->fillRectangle(position, width, height);
	}
}