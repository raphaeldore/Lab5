#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI& _windowApi) : Shape(_windowApi)
{
}

OpenPolyline::~OpenPolyline()
{

}

void OpenPolyline::draw(const Color& _color) const
{
	if (points.size() < 2) throw runtime_error("Pas assez de points pour dessiner une ligne!");

	windowApi->setDrawingColor(_color);

	for (auto it = points.begin(); next(it) < points.end(); ++it)
	{
		windowApi->drawLine(*it, *next(it));	
	}
}