#pragma once
#include "stdafx.h"
#include <memory>

namespace ShapeLibrary
{
	class OpenPolyline
	{
	public:
		OpenPolyline(IWindowAPI& _windowApi) : windowApi(&_windowApi) {};
		~OpenPolyline();

		void add(const Point& _point);
		void draw(const Color& _color = Color::WHITE);

	private:
		IWindowAPI * windowApi;
		vector<Point> points;
	};
}
