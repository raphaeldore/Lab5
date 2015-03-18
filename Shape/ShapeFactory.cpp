#include "stdafx.h"

using namespace ShapeLibrary;

ShapeFactory::ShapeFactory(IWindowAPI &_windowApi) : windowApi(&_windowApi)
{

}

Shape & ShapeFactory::createOpenPolyLine() const
{
	return *new OpenPolyline(*windowApi);
}
