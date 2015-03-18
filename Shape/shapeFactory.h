#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class	ShapeFactory
	{
	public:

		ShapeFactory(IWindowAPI & _windowApi);

		Shape & createOpenPolyLine() const;
	private:
		IWindowAPI * windowApi;
	};
}