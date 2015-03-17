#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : virtual public Shape
	{
	public:
		Circle(IWindowAPI &_windowApi);
		~Circle() override;

		void setCenter(Point& _center);
		void setRadius(const int& _radius);

		virtual void draw(const Color& _color = Color::WHITE) const override;
		//void draw(const Color& _color) override;
	private:
		unsigned int radius;
	};
}
