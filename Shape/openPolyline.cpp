#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI& _windowApi) : Shape(_windowApi)
{
}

OpenPolyline::~OpenPolyline()
{
}

void OpenPolyline::draw() const
{
	if (getPoints().size() < 2) throw runtime_error("Pas assez de points pour dessiner une ligne!");

	windowApi->setDrawingColor(getLineColor());

	if (getLineColor().isVisible())
	{
		for (auto it = getPoints().begin(); next(it) < getPoints().end(); ++it)
		{
			windowApi->drawLine(*it, *next(it));
		}
	}
}