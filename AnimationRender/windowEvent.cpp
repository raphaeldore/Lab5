#include  "stdafx.h"

using namespace WindowRender;

WindowEvent::WindowEvent()
{
	eventType = NONE;

}

WindowEvent::WindowEvent( const WIN_EVENEMENT & _eventType )
{
	eventType = _eventType;
}

WIN_EVENEMENT WindowEvent::getEventType() const
{
	return eventType;
}


