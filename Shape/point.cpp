#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;

Point::Point(double _x, double _y) :
x(_x),
y(_y)
{
	if (_x < 0 || _y < 0) throw invalid_argument("X and Y must be positive");
}

bool Point::operator == (const Point & _point) const
{
	return x == _point.x && y == _point.y;
}

bool Point::operator != (const Point & _point) const
{
	return !(*this == _point);
}