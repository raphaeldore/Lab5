#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ShapeLibrary;

namespace UnitTests
{
	TEST_CLASS(PolygonTests)
	{
	public:
		FakeWindowAPI * fakeWindowAPI;
		Polygon * polygon;

		TEST_METHOD_INITIALIZE(PolygonTests_Initialize)
		{
			fakeWindowAPI = new FakeWindowAPI(640,480,"Super beau dessin");
			polygon = new Polygon(*fakeWindowAPI);
		}

		TEST_METHOD_CLEANUP(PolygonTests_CleanUp)
		{
			delete fakeWindowAPI;
			delete polygon;
		}

		TEST_METHOD(add_point_to_a_polygon_that_is_on_previous_line_should_throw_excpetion)
		{
			//Arrange
			polygon->add(Point(0, 0));
			polygon->add(Point(50, 50));

			//Action
			bool exceptionThrown = false;
		
			try
			{
				polygon->add(Point(25, 25));
				//polygon->add(Point(20, 15));
			}
			catch (runtime_error ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}
		
		TEST_METHOD(add_point_to_a_polygon_that_cross_preivous_lines_should_throw_excpetion)
		{
			//Arrange
			polygon->add(Point(25, 25));
			polygon->add(Point(25, 75));
			polygon->add(Point(75, 100));

			//Action
			bool exceptionThrown = false;

			try
			{
				polygon->add(Point(0, 50));
			}
			catch (runtime_error ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(add_point_to_a_polygon_that_does_not_cross_preivous_lines_but_is_close_should_throw_excpetion)
		{
			//Arrange
			polygon->add(Point(25, 25));
			polygon->add(Point(25, 75));
			polygon->add(Point(75, 100));

			//Action
			bool exceptionThrown = false;

			try
			{
				polygon->add(Point(30, 60));
			}
			catch (runtime_error ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsFalse(exceptionThrown);
		}

		TEST_METHOD(draw_Poloygon_should_draw_lines_on_windowAPI)
		{
			//Arrange	
			const int NOMBRE_DE_LIGNE_DESSINEES = 4;

			polygon->add(Point(100, 100));
			polygon->add(Point(150, 200));
			polygon->add(Point(250, 250));
			polygon->add(Point(175, 175));

			//Action
			polygon->draw();

			//Assert
			Assert::IsTrue(fakeWindowAPI->setDrawingColor_hasBeenCalled());
			Assert::AreEqual(NOMBRE_DE_LIGNE_DESSINEES, fakeWindowAPI->drawLine_getnumberOfCall());
		}
	};
}