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
	do
	{
		windowApi->clearScreen();

		for (auto& shape : shapes)
		{
			shape->draw();
		}

		windowApi->displayScreen();
	}
	while (windowApi->hasEvent() && windowApi->getEvent().getEventType() != QUIT);
}