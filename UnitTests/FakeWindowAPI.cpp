#include "stdafx.h"

using namespace UnitTests;

FakeWindowAPI::FakeWindowAPI(const int _width, const int _height, const string& _windowTitle)
{
	numberOfCallToDrawLine = 0;
	drawCircleHasBeenCalled = false;
	drawRectangleHasBeenCalled = false;
	getEventHasBeenCalled = false;
	hasEventHasBeenCalled = false;
	hasClearScreenBeenCalled = false;
	hasDisplayScreenBeenCalled = false;
	hasWaitHasBeenCalled = false;
	hasfillCircleBeenCalled = false;
	hasfillRectangleBeenCalled = false;
	hasSetDrawingColorBeenCalled = false;
}

FakeWindowAPI::~FakeWindowAPI()
{
}

void FakeWindowAPI::setDrawingColor(const Color& _color)
{
	hasSetDrawingColorBeenCalled = true;
}

void FakeWindowAPI::drawLine(const Point& _point1, const Point& _point2)
{
	numberOfCallToDrawLine += 1;
}


 void FakeWindowAPI::drawRectangle(const Point& _point, const int _width, const int _height)
{
	lastDrawCall = "drawRectangle";
	drawRectangleHasBeenCalled = true;
}

 void FakeWindowAPI::fillRectangle(const Point& _point, const int _width, const int _height)
{
	hasfillRectangleBeenCalled = true;
}

 void FakeWindowAPI::drawCircle(const Point& _point, const int _radius)
{
	lastDrawCall = "drawCircle";
	drawCircleHasBeenCalled = true;
}

 void FakeWindowAPI::fillCircle(const Point& _point, const int _radius)
{
	hasfillCircleBeenCalled = true;
}

 IWindowEvent& FakeWindowAPI::getEvent()
{
	getEventHasBeenCalled = true;

	IWindowEvent * event;
	event = listEvent.front();
	listEvent.pop();

	return *event;
}

 bool FakeWindowAPI::hasEvent()
{
	hasEventHasBeenCalled = true;

	if (listEvent.empty() != true)
	{
		return true;
	}

	return false;
}

 void FakeWindowAPI::clearScreen()
{
	hasClearScreenBeenCalled = true;
}

 void FakeWindowAPI::displayScreen()
{
	hasDisplayScreenBeenCalled = true;
}

 void FakeWindowAPI::wait(float _timeMillis)
{
	hasWaitHasBeenCalled = true;
}

void FakeWindowAPI::toggleFullscreen()
{
}

int FakeWindowAPI::drawLine_getnumberOfCall()
{
	return numberOfCallToDrawLine;
}

bool FakeWindowAPI::drawCircle_hasBeenCalled()
{
	return drawCircleHasBeenCalled;
}

bool FakeWindowAPI::drawRectangle_hasBeenCalled()
{
	return drawRectangleHasBeenCalled;
}

bool FakeWindowAPI::hasEvent_hasBeenCalled()
{
	return hasEventHasBeenCalled;
}

void FakeWindowAPI::hasEvent_shouldReturn(bool valueToReturn)
{
	hasEventReturnValue = valueToReturn;
}

bool FakeWindowAPI::clearScreen_hasBeenCalled()
{
	return hasClearScreenBeenCalled;
}

bool FakeWindowAPI::displayScreen_hasBeenCalled()
{
	return hasDisplayScreenBeenCalled;
}

bool FakeWindowAPI::wait_hasBeenCalled()
{
	return hasWaitHasBeenCalled;
}

bool FakeWindowAPI::getEvent_hasBeenCalled()
{
	return getEventHasBeenCalled;
}

bool FakeWindowAPI::fillCircle_hasBeenCalled()
{
	return hasfillCircleBeenCalled;
}

bool FakeWindowAPI::setDrawingColor_hasBeenCalled()
{
	return hasSetDrawingColorBeenCalled;
}

bool FakeWindowAPI::fillRectangle_hasBeenCalled()
{
	return hasfillRectangleBeenCalled;
}

string FakeWindowAPI::draw_getLastCall()
{
	return lastDrawCall;
}

void FakeWindowAPI::addEvent(IWindowEvent & winEvenement)
{
	listEvent.push(&winEvenement);
}