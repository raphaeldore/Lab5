#pragma once

namespace ShapeLibrary
{
	class Point
	{
	public:

		Point(const double _x, const double _y);

		double x;
		double y;

		bool Point::operator == (const Point & _point) const;
		bool Point::operator != (const Point & _point) const;
	};

}



