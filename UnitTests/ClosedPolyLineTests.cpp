#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ShapeLibrary;

namespace UnitTests
{
	TEST_CLASS(ClosedPolylineTests)
	{
	public:
		FakeWindowAPI * fakeWindowAPI;
		ClosedPolyline * closedPolyLine;

		TEST_METHOD_INITIALIZE(ClosedPolyLineTests_Initialize)
		{
			fakeWindowAPI = new FakeWindowAPI(640,480,"Super beau dessin");
			closedPolyLine = new ClosedPolyline(*fakeWindowAPI);
		}
		TEST_METHOD_CLEANUP(ClosedPolyLineTests_CleanUp)
		{
			delete fakeWindowAPI;
			delete closedPolyLine;
		}

		TEST_METHOD(draw_closedPoloyLine_should_draw_lines_on_windowAPI)
		{
			//Arrange	
			const int NOMBRE_DE_LIGNE_DESSINEES = 3;
			
			closedPolyLine->add(Point(90, 90));
			closedPolyLine->add(Point(150, 175));
			closedPolyLine->add(Point(275, 100));

			//Action
			closedPolyLine->draw();

			//Assert
			Assert::IsTrue(fakeWindowAPI->setDrawingColor_hasBeenCalled());
			Assert::AreEqual(NOMBRE_DE_LIGNE_DESSINEES, fakeWindowAPI->drawLine_getnumberOfCall());
		}

		TEST_METHOD(draw_closedPoloyLine_with_less_than_3_points_should_throw_exception)
		{
			//Arrange
			closedPolyLine->add(Point(90, 90));
			closedPolyLine->add(Point(150, 175));

			//Action
			bool exceptionThrown = false;
			try
			{
				closedPolyLine->draw();
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