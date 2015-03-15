#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI& _windowApi);
		~Polygon();

		void add(Point& _point) override;
	private:
		bool isOnPreviousLine(const Point& _previousPoint, const Point& _currentPoint, const Point& _nextPoint) const;
		bool isBetween(const double& _a, const double& _b, const double& _c) const;
	};
}
