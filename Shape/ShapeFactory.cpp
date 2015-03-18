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

