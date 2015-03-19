#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{
	class IWindowAPI
	{
	public:

		virtual ~IWindowAPI(){};

		virtual void setDrawingColor(const Color & _color) = 0;

		virtual void drawLine(const Point & _point1, const Point & _point2) = 0;

		virtual void drawRectangle(const Point & _point, const int _width, const int _height) = 0;
		virtual void fillRectangle(const Point & _point, const int _width, const int _height) = 0;

		virtual void drawCircle(const Point & _point, const int _radius) = 0;
		virtual void fillCircle(const Point & _point, const int _radius) = 0;

		virtual IWindowEvent & getEvent() = 0;
		virtual bool hasEvent() = 0;

		virtual void clearScreen() = 0;
		virtual void displayScreen() = 0;

		virtual void wait(float _timeMillis) = 0;

		virtual void toggleFullscreen() = 0;
	};

}
