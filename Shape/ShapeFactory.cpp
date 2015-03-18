#include "stdafx.h"

using namespace ShapeLibrary;

ShapeFactory::ShapeFactory(IWindowAPI &_windowApi) : windowApi(&_windowApi)
{
}

Shape & ShapeFactory::createOpenPolyLine() const
{
	return *new OpenPolyline(*windowApi);
}

Shape & ShapeFactory::createCircle(const Point& _center, const int& _radius) const
{
	Circle * circle = new Circle(*windowApi);
	circle->setCenter(_center);
	circle->setRadius(_radius);
	return *circle;
}

Shape & ShapeFactory::createRectangle(const Point& _position, const int& _width, const int& _height) const
{
	Rectangle * rectangle = new Rectangle(*windowApi);
	rectangle->setPosition(_position);
	rectangle->setWidth(_width);
	rectangle->setHeight(_height);
	return *rectangle;
}

Shape & ShapeFactory::createClosedPolyLine() const
{
	return *new ClosedPolyline(*windowApi);
}

Shape & ShapeFactory::createPolygone() const
{
	return *new Polygon(*windowApi);
}