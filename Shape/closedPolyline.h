#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class ClosedPolyline : public OpenPolyline
	{
	public:
		ClosedPolyline(IWindowAPI& _windowApi);
		virtual ~ClosedPolyline();

		virtual void draw() const override;
	};
}