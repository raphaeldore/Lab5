#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ShapeLibrary;

namespace UnitTests
{
	TEST_CLASS(RectangleTests)
	{
	public:
		FakeWindowAPI * fakeWindowAPI;
		Rectangle * rectangle;

		TEST_METHOD_INITIALIZE(RectangleTests_Initialize)
		{
			fakeWindowAPI = new FakeWindowAPI(640, 480, "Super beau dessin");
			rectangle = new Rectangle(*fakeWindowAPI);
		}
		TEST_METHOD_CLEANUP(RectangleTests_CleanUp)
		{
			delete fakeWindowAPI;
			delete rectangle;
		}

		TEST_METHOD(draw_rectangle_should_draw_a_rectangle_on_windowAPI)
		{
			//Arrange
			rectangle->setPosition(Point(250, 500));
			rectangle->setHeight(10);
			rectangle->setWidth(80);

			//Action
			rectangle->draw();

			//Assert
			Assert::IsTrue(fakeWindowAPI->setDrawingColor_hasBeenCalled());
			Assert::IsTrue(fakeWindowAPI->drawRectangle_hasBeenCalled());
		}

		TEST_METHOD(draw_rectangle_with_fill_color_should_fill_the_rectangle)
		{
			//Arrange
			rectangle->setPosition(Point(250, 500));
			rectangle->setFillColor(Color::FUCHSIA);

			//Action
			rectangle->draw();

			//Assert
			Assert::IsTrue(fakeWindowAPI->fillRectangle_hasBeenCalled());
		}

		TEST_METHOD(draw_rectangle_with_fill_and_line_color_should_draw_fill_rectangle_with_colored_line)
		{
			//Arrange
			rectangle->setPosition(Point(250, 500));
			rectangle->setFillColor(Color::LIME);
			rectangle->setLineColor(Color::BROWN);

			//Action
			rectangle->draw();

			//Assert
			Assert::IsTrue(fakeWindowAPI->fillRectangle_hasBeenCalled());
			Assert::IsTrue(fakeWindowAPI->drawRectangle_hasBeenCalled());
		}

		TEST_METHOD(set_negative_width_should_throw_excpetion)
		{
			//Arrange
			const int INVALID_WIDTH = -1;

			//Action
			bool exceptionThrown = false;
			try
			{
				rectangle->setWidth(INVALID_WIDTH);

			}
			catch (std::invalid_argument ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(set_negative_height_should_throw_excpetion)
		{
			//Arrange
			const int INVALID_HEIGHT = -1;

			//Action
			bool exceptionThrown = false;
			try
			{
				rectangle->setWidth(INVALID_HEIGHT);
			}
			catch (std::invalid_argument ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(no_position_set_should_throw_exception)
		{
			//Arrange
			rectangle->setHeight(10);

			//Action
			bool exceptionThrown = false;
			try
			{
				rectangle->draw();
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