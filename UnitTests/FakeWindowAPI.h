#pragma once
#include "stdafx.h"

#include <queue>

using namespace std;
using namespace ShapeLibrary;


namespace UnitTests
{


	class FakeWindowAPI : public IWindowAPI
	{
	public:

		FakeWindowAPI(const int _width, const int _height, const string & _windowTitle);
		~FakeWindowAPI();

		void setDrawingColor(const Color & _color);
		void drawLine(const Point & _point1, const Point & _point2);
		void drawRectangle(const Point & _point, const int _width, const int _height);
		void fillRectangle(const Point & _point, const int _width, const int _height);
		void drawCircle(const Point & _point, const int _radius);
		void fillCircle(const Point & _point, const int _radius);

		IWindowEvent & getEvent();
		bool hasEvent();

		void clearScreen();
		void displayScreen();

		void wait(float _timeMillis);

		void toggleFullscreen();

		// Méthodes pour le FAKE
		int drawLine_getnumberOfCall();
		bool drawCircle_hasBeenCalled();
		bool drawRectangle_hasBeenCalled();
		bool hasEvent_hasBeenCalled();
		void hasEvent_shouldReturn(bool valueToReturn);
		bool clearScreen_hasBeenCalled();
		bool displayScreen_hasBeenCalled();
		bool wait_hasBeenCalled();
		bool getEvent_hasBeenCalled();
		bool fillCircle_hasBeenCalled();
		bool setDrawingColor_hasBeenCalled();
		bool fillRectangle_hasBeenCalled();
		string draw_getLastCall();
		void addEvent(IWindowEvent & winEvenement);

	private:
		// Attributs pour le FAKE
		int numberOfCallToDrawLine;
		bool drawCircleHasBeenCalled;
		bool drawRectangleHasBeenCalled;
		bool hasEventHasBeenCalled;
		bool hasEventReturnValue;
		bool getEventHasBeenCalled;
		bool hasClearScreenBeenCalled;
		bool hasDisplayScreenBeenCalled;
		bool hasWaitHasBeenCalled;
		bool hasfillCircleBeenCalled;
		bool hasfillRectangleBeenCalled;
		bool hasSetDrawingColorBeenCalled;
		string lastDrawCall;
		queue<IWindowEvent *> listEvent;


		
	};
}
