#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		void setFillColor(const Color& _fillColor);
		void setLineColor(const Color& _fillColor);
		void draw();
	protected:
		vector<Point> points;

		Color fillColor = Color::INVISIBLE;
		Color lineColor;
	};
}
