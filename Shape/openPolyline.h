#pragma once
#include "stdafx.h"
#include <memory>

namespace ShapeLibrary
{
	class OpenPolyline : virtual public Shape
	{
	public:
		explicit OpenPolyline(IWindowAPI& _windowApi);
		virtual ~OpenPolyline();

		virtual void draw(const Color& _color = Color::WHITE) const override;
	};
}
