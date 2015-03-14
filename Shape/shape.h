#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		Shape(IWindowAPI& _windowApi);
		void setFillColor(const Color& _fillColor);
		void setLineColor(const Color& _fillColor);
		void add(Point& _point);
		void draw();
	protected:
		IWindowAPI * windowApi;
		vector<Point> points;
		Color fillColor = Color::INVISIBLE;
		Color lineColor;
	};
}
