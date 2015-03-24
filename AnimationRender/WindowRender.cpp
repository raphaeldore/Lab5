#include  "stdafx.h"
#include <algorithm>

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
	bool quit = false;

	while (quit == false)
	{
		while (windowApi->hasEvent())
		{
			// Nécessaire pour éviter un memory leak
			unique_ptr<IWindowEvent> event(&windowApi->getEvent());
			if (event.get()->getEventType() == QUIT)
			{
				quit = true;
			}
		}

		windowApi->clearScreen();

		for (auto& shape : shapes)
		{
			shape.get()->draw();
		}

		windowApi->displayScreen();
		windowApi->wait(waitTime);
	}

}

void WindowsRender::attach(Shape & _shape)
{
	shapes.push_back(unique_ptr<Shape>(&_shape));
}

void WindowsRender::putOnTop(Shape& _shape)
{
	// TODO: Algo de recherche plus optimisée

	int position = 0;
	for (auto& i : shapes)
	{
		if (i.get() == &_shape)
		{
			break;
		}
		position++;
	}

	// Le unique_ptr ne contrôle plus le pointeur. 
	// On libère au unique_ptr la responsabilité de gérer
	// le contenu du pointeur. Le unique_ptr est maintenant
	// null, mais le contenu pointé (la forme) existe toujours
	// en mémoire.
	shapes.at(position).release();
	shapes.erase(shapes.begin() + position);

	// Et on réajoute la forme, cette fois-ci à la fin du vector
	shapes.push_back(unique_ptr<Shape>(&_shape));
}