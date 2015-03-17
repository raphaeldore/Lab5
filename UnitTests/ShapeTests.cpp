#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ShapeLibrary;

namespace UnitTests
{
	TEST_CLASS(ShapeTests)
	{
	public:
		FakeWindowAPI * fakeWindowAPI;

		TEST_METHOD_INITIALIZE(ShapeTests_Initialize)
		{
			fakeWindowAPI = new FakeWindowAPI(640,480,"Super beau dessin");
		}
		TEST_METHOD_CLEANUP(ShapeTests_CleanUp)
		{
			delete fakeWindowAPI;
		}
		
		TEST_METHOD(getPoint_should_return_the_point)
		{
			//Arrange
			const Point POINT_ATTENDU = Point(150, 175);
			const int INDEX_DEUXIEME_POINT = 1;

			Shape * closedPolyline = new ClosedPolyline(*fakeWindowAPI);
			
			closedPolyline->add(Point(90, 90)); 
			closedPolyline->add(POINT_ATTENDU); 
			closedPolyline->add(Point(275, 100)); 

			//Action
			Point pointObtenu = closedPolyline->getPoint(INDEX_DEUXIEME_POINT);

			//Assert
			Assert::AreEqual(POINT_ATTENDU.x, pointObtenu.x);
			Assert::AreEqual(POINT_ATTENDU.y, pointObtenu.y);
			delete closedPolyline;
		}

		TEST_METHOD(getPoint_should_throw_exception_if_no_points)
		{
			//Arrange
			Shape * closedPolyline = new ClosedPolyline(*fakeWindowAPI);

			//Action
			bool exceptionThrown = false;

			try
			{
				closedPolyline->getPoint(1);
			}
			catch (runtime_error ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(getPoint_should_throw_exception_if_index_negative)
		{
			//Arrange
			Shape * closedPolyline = new ClosedPolyline(*fakeWindowAPI);

			//Action
			bool exceptionThrown = false;

			closedPolyline->add(Point(90, 90));

			try
			{
				closedPolyline->getPoint(-1);
			}
			catch (invalid_argument ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}
	};
}