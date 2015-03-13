#pragma once
#include "stdafx.h"
#include <memory>

namespace ShapeLibrary
{
	class OpenPolyline : public Shape
	{
	public:
		OpenPolyline(IWindowAPI& _windowApi);
		~OpenPolyline();

		void add(const Point& _point);
		void draw(const Color& _color = Color::WHITE);

	private:
		vector<Point> points;
	};
}
