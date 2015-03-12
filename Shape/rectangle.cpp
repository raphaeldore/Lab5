#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI& _windowApi) : windowApi(&_windowApi), position(0, 0), fillColor(Color::INVISIBLE)
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
	height = _height;
}

void Rectangle::setWidth(const int& _width)
{
	width = _width;
}

void Rectangle::setFillColor(const Color& _fillcolor)
{
	fillColor = _fillcolor;
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