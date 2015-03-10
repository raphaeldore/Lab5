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
	if (points.size() < 2) throw runtime_error("Pas assez de poits pour dessiner une ligne!");

	windowApi->setDrawingColor(_color);

	for (auto it = points.begin(); it < points.end(); ++it)
	{
		if (next(it) != points.end())
		{
			windowApi->drawLine(*it, *next(it));
		}
		
	}
}