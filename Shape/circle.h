#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : Shape
	{
	public:
		Circle(IWindowAPI &_windowApi);
		~Circle();

		void setCenter(const Point& _center);
		void setRadius(const int& _radius);
		void draw(const Color& _color = Color::WHITE) const;
	private:
		IWindowAPI * windowApi;
		unique_ptr<Point> center;
		unsigned int radius;
	};
}
