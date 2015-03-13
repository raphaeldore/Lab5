#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Rectangle : Shape
	{
	public:
		Rectangle(IWindowAPI& _windowApi);
		~Rectangle();

		void setPosition(const Point& _position);
		void setHeight(const int& _height);
		void setWidth(const int& _width);
		void setFillColor(const Color& _fillColor);
		void setLineColor(const Color& _lineColor);

		void draw(const Color& _color = Color::WHITE) const;
	private:
		IWindowAPI * windowApi;
		unique_ptr<Point> position = nullptr;
		int height;
		int width;
	};
}