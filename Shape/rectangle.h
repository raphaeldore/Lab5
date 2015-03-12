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
		void setFillColor(const Color& _fillcolor);

		void draw(const Color& _color = Color::WHITE);
	private:
		IWindowAPI * windowApi;
		Point position;
		Color fillColor;
		int height;
		int width;
	};
}