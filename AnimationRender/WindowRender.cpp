#include  "stdafx.h"

using namespace WindowRender;
using namespace ShapeLibrary;

WindowsRender::WindowsRender(IWindowAPI& _windowApi): windowApi(&_windowApi)
{
	
}

WindowsRender::~WindowsRender()
{
	
}

void WindowsRender::render() const
{
	float waitTime = 1000 / 60;
	do
	{
		windowApi->clearScreen();

		for (auto& shape : shapes)
		{
			shape->draw();
		}
		
		windowApi->displayScreen();
		windowApi->wait(waitTime);

	} while (windowApi->hasEvent() && windowApi->getEvent().getEventType() != QUIT);
}

void WindowsRender::attach(Shape& _shape)
{
	shapes.push_back(make_unique<Shape>(_shape));
}