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
	if (getPoints().size() < 3) throw runtime_error("Pas assez de points pour dessiner un polygone (3 min. Ex: Triangle).");

	if (getLineColor().isVisible())
	{
		OpenPolyline::draw();
		// Il ne reste qu'à fermer le polygone
		windowApi->drawLine(getPoints().back(), getPoints().front());
	}
}