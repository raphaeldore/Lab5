#include "stdafx.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ShapeLibrary;

namespace UnitTests
{
	TEST_CLASS(CircleTests)
	{
	public:
		FakeWindowAPI * fakeWindowAPI;
		Circle * circle;

		TEST_METHOD_INITIALIZE(CircleTests_Initialize)
		{
			fakeWindowAPI = new FakeWindowAPI(640,480,"Super beau dessin");
			circle = new Circle(*fakeWindowAPI);
		}
		TEST_METHOD_CLEANUP(CircleTests_CleanUp)
		{
			delete fakeWindowAPI;
			delete circle;
		}

		TEST_METHOD(draw_circle_should_draw_circle_on_windowAPI)
		{
			//Arrange
			circle->setCenter(Point(300, 300));
			circle->setRadius(30);
			
			//Action
			circle->draw();

			//Assert
			Assert::IsTrue(fakeWindowAPI->setDrawingColor_hasBeenCalled());
			Assert::IsTrue(fakeWindowAPI->drawCircle_hasBeenCalled());
		}

		TEST_METHOD(draw_circle_with_fillColor_should_draw_fill_circle)
		{
			//Arrange
			circle->setCenter(Point(300, 300));
			circle->setFillColor(Color::LIME);

			//Action
			circle->draw();

			//Assert
			Assert::IsTrue(fakeWindowAPI->setDrawingColor_hasBeenCalled());
			Assert::IsTrue(fakeWindowAPI->fillCircle_hasBeenCalled());
		}

		TEST_METHOD(draw_circle_with_fill_and_line_color_should_draw_fill_circle_with_colored_line)
		{
			//Arrange
			circle->setCenter(Point(300, 300));
			circle->setFillColor(Color::LIME);
			circle->setLineColor(Color::BROWN);

			//Action
			circle->draw();

			//Assert
			Assert::IsTrue(fakeWindowAPI->fillCircle_hasBeenCalled());
			Assert::IsTrue(fakeWindowAPI->drawCircle_hasBeenCalled());
		}


		TEST_METHOD(set_negative_radius_should_throw_excpetion)
		{
			//Arrange
			const int INVALID_RADIUS = -1;

			//Action
			bool exceptionThrown = false;
			try
			{
				Circle circle(*fakeWindowAPI);
				circle.setRadius(INVALID_RADIUS);
			}
			catch (std::invalid_argument ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(draw_circle_with_no_center_should_throw_exception)
		{
			//Arrange

			//Action
			bool exceptionThrown = false;
			try
			{
				circle->draw();
			}
			catch (std::runtime_error ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}
	};
}