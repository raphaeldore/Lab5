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
		void draw();
	protected:
		IWindowAPI * windowApi;
		Color fillColor = Color::INVISIBLE;
		Color lineColor;
	};
}
