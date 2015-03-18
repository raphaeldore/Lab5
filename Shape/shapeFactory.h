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
	private:
		IWindowAPI * windowApi;
	};
}