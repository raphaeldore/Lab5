#pragma once
#include "../Shape/stdafx.h"
#include "../AnimationRender/stdafx.h"

#include "SDL.h"
#include "SDL_draw.h"

#include <string>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

namespace SDL_WINDOW_UI
{

	class SDLWindowAPI : public IWindowAPI
	{
	public:

		SDLWindowAPI(const int _width, const int _height, const string & _windowTitle);
		~SDLWindowAPI();

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

	private:

		SDL_Surface* screen;
		Uint32 drawingColor; // Couleur pour dessiner

		std::queue<unique_ptr<IWindowEvent>> listEvent;
	};
}