#include "../inc/WindowTest.h"

#include "../../../../consolants/view/inc/Pixel.h"

namespace ants::view::ut
{
   void WindowTest::SetUp() {}

   void WindowTest::TearDown()
   {
      window = Window(100, 50);
      window.setClearColor(Color::Black);
   }

   TEST_F(WindowTest, Constructor)
   {
      window = Window(50, 30);
      ASSERT_EQ(30, window.getCanvas().size());
      ASSERT_EQ(50, window.getCanvas()[0].size());
   }

   TEST_F(WindowTest, SetPixelThreeArguments)
   {
      window.setPixel(Color::Purple, 8, 10);
      ASSERT_EQ(Color::Purple, window.getCanvas()[10][8]);
   }

   TEST_F(WindowTest, SetPixelTwoArguments)
   {
      window.setPixel(Color::Cyan, math::Point(8, 10));
      ASSERT_EQ(Color::Cyan, window.getCanvas()[10][8]);
   }

   TEST_F(WindowTest, SetPixelOneArgument)
   {
      window.setPixel(Pixel(Color::Blush, 5, 6));
      ASSERT_EQ(Color::Blush, window.getCanvas()[6][5]);
   }

   TEST_F(WindowTest, ClearScreenShamrock)
   {
      window.setClearColor(Color::Shamrock);
      window.setPixel(Color::Purple, 10, 10);
      window.clear();
      for (const auto& row : window.getCanvas())
      {
         for (const auto& color : row)
         {
            ASSERT_EQ(Color::Shamrock, color);
         }
      }
   }
}
