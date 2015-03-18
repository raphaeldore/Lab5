#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class	ShapeFactory
	{
	public:

		ShapeFactory(IWindowAPI & _windowApi);

		Shape & createOpenPolyLine() const;
		Shape & createCircle(const Point& _center, const int& _radius) const;
		Shape & createRectangle(const Point& _position, const int& _width, const int& _height) const;
		Shape & createClosedPolyLine() const;
		Shape & createPolygone() const;
	private:
		IWindowAPI * windowApi;
	};
}