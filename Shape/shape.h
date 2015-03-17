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
		virtual ~Shape() {}

		void setFillColor(const Color& _fillColor);
		void setLineColor(const Color& _fillColor);
		Point getPoint(const int& _index);
		virtual void add(const Point& _point);
		virtual void draw() {};
	protected:
		IWindowAPI * windowApi;
		vector<Point> points;
		Color fillColor = Color::INVISIBLE;
		Color lineColor;
	};
}
