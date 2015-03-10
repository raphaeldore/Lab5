#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ShapeLibrary;

namespace UnitTests
{
	TEST_CLASS(OpenPolylineTests)
	{
	public:
		
		FakeWindowAPI * fakeWindowAPI;
		OpenPolyline * openPolyLine;

		TEST_METHOD_INITIALIZE(OpenPolylineTests_Initialize)
		{
			fakeWindowAPI = new FakeWindowAPI(640,480,"Super beau dessin");
			openPolyLine = new OpenPolyline(*fakeWindowAPI);
		}

		TEST_METHOD_CLEANUP(OpenPolylineTests_CleanUp)
		{
			delete fakeWindowAPI;
			delete openPolyLine;
		}

		TEST_METHOD(draw_openPolLine_should_draw_lines_on_windowAPI)
		{
			//Arrange
			const int NOMBRE_DE_LIGNE_DESSINEES = 2;
		
			openPolyLine->add(Point(200, 200));
			openPolyLine->add(Point(250, 275));
			openPolyLine->add(Point(375, 225));
					
			//Action
			openPolyLine->draw();
			
			//Assert
			Assert::IsTrue(fakeWindowAPI->setDrawingColor_hasBeenCalled());
			Assert::AreEqual(NOMBRE_DE_LIGNE_DESSINEES, fakeWindowAPI->drawLine_getnumberOfCall());
		}

		//TEST_METHOD(openPloyLine_with_less_than_2_points_should_throw_exception)
		//{
		//	//Arrange
		//	openPolyLine->add(Point(200, 200));

		//	//Action
		//	bool exceptionThrown = false;
		//	try
		//	{
		//		openPolyLine->draw();
		//	}
		//	catch (std::runtime_error ex)
		//	{
		//		exceptionThrown = true;
		//	}

		//	//Assert
		//	Assert::IsTrue(exceptionThrown);
		//}
	};
}