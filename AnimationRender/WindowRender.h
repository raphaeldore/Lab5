#pragma once
#include "stdafx.h"

using namespace std;
using namespace ShapeLibrary;

namespace WindowRender
{
	class WindowsRender
	{
	public:
		WindowsRender(IWindowAPI& _windowApi);
		~WindowsRender();
		void render() const;
		void attach(Shape& _shape);
		void putOnTop(Shape& _shape);
	private:
		IWindowAPI * windowApi;
		vector<unique_ptr<Shape>> shapes;
	};
}