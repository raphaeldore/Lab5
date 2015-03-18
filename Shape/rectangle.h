#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Rectangle : virtual public Shape
	{
	public:
		Rectangle(IWindowAPI& _windowApi);
		~Rectangle();

		void setPosition(const Point& _position);
		void setHeight(const int& _height);
		void setWidth(const int& _width);

		virtual void draw() const override;
	private:
		int height;
		int width;
	};
}