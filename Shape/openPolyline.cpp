#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::~OpenPolyline()
{
	//delete windowApi;
}

void OpenPolyline::add(Point _point)
{
	points.push_back(_point);
}

void OpenPolyline::draw(const Color& _color)
{
	windowApi->setDrawingColor(_color);

	for (auto it = points.begin(); it < points.end(); ++it)
	{
		if (next(it) != points.end())
		{
			windowApi->drawLine(*it, *next(it));
		}
		
	}
}