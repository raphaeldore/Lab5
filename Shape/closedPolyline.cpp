#include "stdafx.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline(IWindowAPI& _windowApi): OpenPolyline(_windowApi)
{
}

ClosedPolyline::~ClosedPolyline()
{
	
}

void ClosedPolyline::draw(const Color& _color) const
{
	OpenPolyline::draw(_color);

	// Il ne reste qu'à fermer le polygone
	windowApi->drawLine(points.back(), points.front());
}