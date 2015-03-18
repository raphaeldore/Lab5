#include "../Shape/stdafx.h"
#include "../AnimationRender/stdafx.h"

#include "SDLWindowAPI.h"

#include <iostream>
#include <vld.h>

using namespace	SDL_WINDOW_UI;
using namespace WindowRender;

int main( int argc, char* args[] )
{
	// NE COMMENCEZ PAS PAR LE MAIN. COMMENCEZ PAR LES TESTS !

	try
	{
		unique_ptr<IWindowAPI> windowAPI(new SDLWindowAPI(640, 480, "Afficher des formes"));
		unique_ptr<WindowsRender> windowRender(new WindowsRender(*windowAPI));

		ShapeFactory shapeFactory(*windowAPI); 

		// On ajoute un openPolyLine
		Shape & openPolyLine = shapeFactory.createOpenPolyLine();
		openPolyLine.add(Point(200,200));
		openPolyLine.add(Point(250,275));
		openPolyLine.add(Point(375,225));
		openPolyLine.setLineColor(Color::FUCHSIA);
		//openPolyLine.setLineColor(Color::INVISIBLE);
		windowRender->attach(openPolyLine);  

		// On ajoute un cercle
		Shape & circle1 = shapeFactory.createCircle(Point(300, 300), 15);
		circle1.setLineColor(Color::BLUE);
		circle1.setFillColor(Color::RED);
		windowRender->attach(circle1);

		// On ajoute un cercle
		Shape & circle2  = shapeFactory.createCircle(Point(300,300),30);
		circle2.setLineColor(Color::CYAN);
		circle2.setFillColor(Color::BROWN);
		windowRender->attach(circle2);         

		// On ajoute un rectangle
		Shape & rectangle = shapeFactory.createRectangle(Point(280,50),100,50);
		rectangle.setLineColor(Color::YELLOW);
		rectangle.setFillColor(Color::BLUE);
		windowRender->attach(rectangle); 

		// On ajoute un closedPolyLine
		Shape & closedPolyLine = shapeFactory.createClosedPolyLine();
		closedPolyLine.add(Point(90,90));
		closedPolyLine.add(Point(150,175));
		closedPolyLine.add(Point(275,100));
		closedPolyLine.setLineColor(Color::LIME);
		closedPolyLine.setFillColor(Color::OLIVE);
		windowRender->attach(closedPolyLine);         

		// On ajoute un polygone
		Shape & poly = shapeFactory.createPolygone();
		poly.add(Point(100,200));
		poly.add(Point(150,300));
		poly.add(Point(250,350));
		poly.add(Point(175,175));
		windowRender->attach(poly);

		windowRender->putOnTop(circle1);
	
		// On fait le rendu de tout ça
		windowRender->render();       // Donne le contrôle à Window

	}
	catch (exception & e)
	{
		std::cout << e.what() << std::endl;
		system("pause");

	}
		return 0;
}