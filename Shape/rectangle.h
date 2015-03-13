#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(IWindowAPI& _windowApi);
		~Rectangle();

		void setPosition(const Point& _position);
		void setHeight(const int& _height);
		void setWidth(const int& _width);

		void draw(const Color& _color = Color::WHITE) const;
	private:
		unique_ptr<Point> position = nullptr;
		int height;
		int width;
	};
}