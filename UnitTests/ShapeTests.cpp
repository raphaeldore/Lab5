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
	};
}