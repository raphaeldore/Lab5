#include "stdafx.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline(IWindowAPI& _windowApi) : OpenPolyline(_windowApi)
{
}

ClosedPolyline::~ClosedPolyline()
{
}

void ClosedPolyline::draw() const
{
	if (points.size() < 3) throw runtime_error("Pas assez de points pour dessiner un polygone (3 min. Ex: Triangle).");

	OpenPolyline::draw();

	// Il ne reste qu'à fermer le polygone
	windowApi->drawLine(points.back(), points.front());
}