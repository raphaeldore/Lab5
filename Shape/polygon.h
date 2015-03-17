#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : virtual public ClosedPolyline
	{
	public:
		Polygon(IWindowAPI& _windowApi);
		~Polygon();

		virtual void add(const Point& _point) override;
	private:
		bool isOnPreviousLine(const Point& _point) const;
		bool crossesPreviousLines(const Point& _point) const;
		bool isColineaire(const Point& _previousPoint, const Point& _currentPoint, const Point& _nextPoint) const;
		bool intersectsSegment(const Point& _A, const Point& _B, const Point& _C, const Point& _D) const;
		bool isBetween(const double& _a, const double& _b, const double& _c) const;
		bool areNearlyEqual(const double& _a, const double& _b) const;
	};
}
