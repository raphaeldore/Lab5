#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{
	class Shape
	{
	public:
		Shape(IWindowAPI& _windowApi);
		virtual ~Shape() {}
		
		const Color & getFillColor() const;
		const Color & getLineColor() const;
		void setFillColor(const Color& _fillColor);
		void setLineColor(const Color& _lineColor);
		
		const vector<Point> & getPoints() const;
		const Point & getPoint(const int& _index) const;
		
		virtual void add(const Point& _point);
		virtual void draw() const = 0;
	protected:
		IWindowAPI * windowApi;
	private:
		vector<Point> points;
		Color fillColor = Color::VISIBLE;
		Color lineColor = Color::WHITE;
	};
}
