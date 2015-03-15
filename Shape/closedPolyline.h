#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class ClosedPolyline : public OpenPolyline
	{
	public:
		ClosedPolyline(IWindowAPI& _windowApi);
		~ClosedPolyline();

		//virtual void add(Point& _point) {};
		void draw(const Color& _color = Color::WHITE) const;
	};
}