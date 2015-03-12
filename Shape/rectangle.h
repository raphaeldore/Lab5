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

		void draw(const Color& _color = Color::BLACK);
	private:
		IWindowAPI * windowApi;
		Point position;
		int height;
		int width;
	};
}