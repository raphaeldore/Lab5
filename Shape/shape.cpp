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

Point Shape::getPoint(const int& _index)
{
	if (points.empty()) throw runtime_error("Le vecteur de points est vide!");

	return points.at(_index);
}

void Shape::add(const Point& _point)
{
	points.push_back(_point);
}