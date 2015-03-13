#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI& _windowApi) : windowApi(&_windowApi)
{
}

void Shape::setFillColor(const Color& _fillColor)
{
	fillColor = _fillColor;
}

void Shape::setLineColor(const Color& _lineColor)
{
	lineColor = _lineColor;
}
