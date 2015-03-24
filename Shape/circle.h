#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : public Shape
	{
	public:
		Circle(IWindowAPI &_windowApi);
		~Circle() override;

		void setCenter(const Point& _center);
		void setRadius(const int& _radius);

		virtual void draw() const override;
	private:
		unsigned int radius;
	};
}
