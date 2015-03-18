#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ShapeLibrary;
using namespace WindowRender;

namespace UnitTests
{
	TEST_CLASS(WindowRenderTests)
	{
	public:

		FakeWindowAPI * fakeWindowAPI;
		WindowsRender * windowRender;
		WindowEvent * eventNone;
		WindowEvent * eventQuit;
	
		TEST_METHOD_INITIALIZE(WindowRenderTests_Initialize)
		{
			fakeWindowAPI = new FakeWindowAPI(640, 480, "Super beau dessin");
			windowRender = new WindowsRender(*fakeWindowAPI);

			eventNone = new WindowEvent();
			eventQuit = new WindowEvent(WIN_EVENEMENT::QUIT);
		}
		TEST_METHOD_CLEANUP(WindowRenderTests_CleanUp)
		{
			delete fakeWindowAPI;
			delete windowRender;
			// On ne delete pas les évenements. Ils sont effacés dans le render.
			
		}

		TEST_METHOD(render_should_look_for_event_on_windowApi)
		{
			//arrange
			fakeWindowAPI->addEvent(*eventQuit);

			//action 
			windowRender->render();

			//assert
			Assert::IsTrue(fakeWindowAPI->hasEvent_hasBeenCalled());
			Assert::IsTrue(fakeWindowAPI->getEvent_hasBeenCalled());
		}

		TEST_METHOD(render_should_clear_screen)
		{
			//arrange
			fakeWindowAPI->addEvent(*eventNone);
			fakeWindowAPI->addEvent(*eventQuit);
			
			//action 
			windowRender->render();

			//assert
			Assert::IsTrue(fakeWindowAPI->clearScreen_hasBeenCalled());
		}

		TEST_METHOD(render_should_display_screen)
		{
			//arrange
			fakeWindowAPI->addEvent(*eventQuit);

			//action 
			windowRender->render();

			//assert
			Assert::IsTrue(fakeWindowAPI->displayScreen_hasBeenCalled());
		}

		TEST_METHOD(render_should_wait_for_window_regulation)
		{
			//arrange
			fakeWindowAPI->addEvent(*eventNone);
			fakeWindowAPI->addEvent(*eventQuit);

			//action 
			windowRender->render();

			//assert
			Assert::IsTrue(fakeWindowAPI->wait_hasBeenCalled());
		}


		TEST_METHOD(attached_shape_should_be_rendered)
		{
			//arrange
			fakeWindowAPI->addEvent(*eventNone);
			fakeWindowAPI->addEvent(*eventQuit);
			Circle * circle = new Circle(*fakeWindowAPI);
			circle->setCenter(Point(100, 100));
			circle->setRadius(20);

			windowRender->attach(*circle);

			//action 
			windowRender->render();

			//assert
			Assert::IsTrue(fakeWindowAPI->drawCircle_hasBeenCalled());
		}

		TEST_METHOD(putOnTop_a_shape_should_render_it_after_others_shapes)
		{
			//arrange
			const string LAST_DRAW_CALL = "drawCircle";
			fakeWindowAPI->addEvent(*eventNone);
			fakeWindowAPI->addEvent(*eventQuit);
			
			Circle * circle = new Circle(*fakeWindowAPI);
			circle->setCenter(Point(100, 100));
			circle->setRadius(20);

			Rectangle * rectangle = new Rectangle(*fakeWindowAPI);
			rectangle->setPosition(Point(280, 50));
			rectangle->setWidth(100);
			rectangle->setHeight(50);


			windowRender->attach(*circle); 
			windowRender->attach(*rectangle);

			//action 
			windowRender->putOnTop(*circle);
			windowRender->render();

			//assert
			Assert::AreEqual(LAST_DRAW_CALL, fakeWindowAPI->draw_getLastCall());
		}

	};
}