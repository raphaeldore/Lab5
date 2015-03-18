#include "../Shape/stdafx.h"
#include "../AnimationRender/stdafx.h"

#include "SDLWindowAPI.h"

using namespace SDL_WINDOW_UI;
using namespace WindowRender;

SDLWindowAPI::SDLWindowAPI(const int _width, const int _height, const string & _windowTitle) 
	:drawingColor(Color::WHITE)
{
	assert(_height > 0 && _width > 0);
	SDL_Init( SDL_INIT_EVERYTHING ); 
	screen = SDL_SetVideoMode( _width, _height, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption(_windowTitle.c_str(), 0 ); 
}

SDLWindowAPI::~SDLWindowAPI()
{
	SDL_Quit();
}

void SDLWindowAPI::drawLine( const Point & _point1,const Point & _point2 ) 
{
	Draw_Line(screen, (Sint16)_point1.x, (Sint16)_point1.y, (Sint16)_point2.x, (Sint16)_point2.y,drawingColor);
}

void SDLWindowAPI::drawRectangle( const Point & _point, const int _width, const int _height ) 
{
	 Draw_Rect(screen,(Sint16)_point.x, (Sint16)_point.y, _width, _height, drawingColor);
}

void SDLWindowAPI::fillRectangle( const Point & _point, const int _width, const int _height ) 
{
	 Draw_FillRect(screen, (Sint16)_point.x, (Sint16)_point.y, _width, _height, drawingColor);
}


void SDLWindowAPI::drawCircle( const Point & _point, const int _radius ) 
{
	Draw_Circle(screen, (Sint16)_point.x, (Sint16)_point.y, _radius, drawingColor);
}

void SDLWindowAPI::fillCircle( const Point & _point, const int _radius ) 
{	
	Draw_FillCircle(screen, (Sint16)_point.x, (Sint16)_point.y, _radius, drawingColor);
}
 

void SDLWindowAPI::setDrawingColor( const Color & _color )
{
	drawingColor = _color.getColorAsInt();
}

void SDLWindowAPI::clearScreen()
{
	SDL_FillRect(screen, 0, 0 );
}

void SDLWindowAPI::displayScreen()
{
	SDL_Flip(screen); 
}

void SDLWindowAPI::wait(float _timeMillis)
{
	SDL_Delay((Uint32)_timeMillis);
}

bool SDLWindowAPI::hasEvent()
{
	SDL_Event event; 
	
	while( SDL_PollEvent( &event ) ) 
	{ 
		if( event.type == SDL_QUIT ) 
		{ 
			listEvent.push(unique_ptr<IWindowEvent>(new WindowEvent(QUIT)));
		} 
	} 
	
	if (listEvent.empty())
	{
		return false;
	}
	return true;
}

IWindowEvent & SDLWindowAPI::getEvent()
{
	assert(listEvent.empty() != true);

	IWindowEvent * event = listEvent.front().release();
	listEvent.pop();
	return *event;
}