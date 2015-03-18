#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ShapeLibrary;

namespace UnitTests
{
	TEST_CLASS(ShapeFactoryTests)
	{
	public:
		FakeWindowAPI * fakeWindowAPI;
		ShapeFactory * shapeFactory;

		TEST_METHOD_INITIALIZE(ShapeFactoryTests_Initialize)
		{
			fakeWindowAPI = new FakeWindowAPI(640,480,"Super beau dessin");
			shapeFactory  = new ShapeFactory(*fakeWindowAPI);
		}
		TEST_METHOD_CLEANUP(ShapeTests_CleanUp)
		{
			delete fakeWindowAPI;
			delete shapeFactory;
		}
		
		TEST_METHOD(should_create_an_OpenPolyLine)
		{
			//Arrange

			//Action
			Shape & openPolyLine = shapeFactory->createOpenPolyLine();

			//Assert
			Assert::IsTrue(dynamic_cast<OpenPolyline*>(&openPolyLine));
		}

		TEST_METHOD(should_create_a_circle)
		{
			//Arrange

			//Action
			Shape & circle = shapeFactory->createCircle(Point(300, 300), 30);

			//Assert
			Assert::IsTrue(dynamic_cast<Circle*>(&circle));
		}

		TEST_METHOD(should_create_a_rectangle)
		{
			//Arrange

			//Action
			Shape & rectangle = shapeFactory->createRectangle(Point(280, 50), 100, 50);

			//Assert
			Assert::IsTrue(dynamic_cast<Rectangle*>(&rectangle));
		}

		TEST_METHOD(should_create_a_ClosedPolyLine)
		{
			//Arrange

			//Action
			Shape & clodePolyLine = shapeFactory->createClosedPolyLine();

			//Assert
			Assert::IsTrue(dynamic_cast<ClosedPolyline*>(&clodePolyLine));
		}

		TEST_METHOD(should_create_a_Polygon)
		{
			//Arrange

			//Action
			Shape & polygon = shapeFactory->createPolygone();

			//Assert
			Assert::IsTrue(dynamic_cast<Polygon*>(&polygon));
		}
	};
}
