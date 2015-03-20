#include "stdafx.h"

using namespace ShapeLibrary;

Shape::Shape(IWindowAPI& _windowApi) : windowApi(&_windowApi)
{
}

const Color & Shape::getFillColor() const
{
	return fillColor;
}

const Color & Shape::getLineColor() const
{
	return lineColor;
}

void Shape::setFillColor(const Color& _fillColor)
{
	fillColor = _fillColor;
}

void Shape::setLineColor(const Color& _lineColor)
{
	lineColor = _lineColor;
}

const vector<Point> & Shape::getPoints() const
{
	return points;
}

const Point & Shape::getPoint(const int& _index) const
{
	if (points.empty()) throw runtime_error("Le vecteur de points est vide!");
	if (_index < 0) throw invalid_argument("Index négatif invalide.");

	return points.at(_index);
}

void Shape::add(const Point& _point)
{
	points.push_back(_point);
}