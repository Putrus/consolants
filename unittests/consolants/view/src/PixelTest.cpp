#include "../../../../consolants/view/inc/Pixel.h"

#include <gtest/gtest.h>

namespace ants::view::ut
{
   TEST(PixelTest, ConstructorThreeArguments)
   {
      Pixel pixel(Color::Red, 10, 15);
      ASSERT_EQ(10, pixel.getPosition().x);
      ASSERT_EQ(15, pixel.getPosition().y);
      ASSERT_EQ(Color::Red, pixel.getColor());
   }

   TEST(PixelTest, ConstructorTwoArguments)
   {
      Pixel pixel(Color::Red, math::Point(10, 15));
      ASSERT_EQ(10, pixel.getPosition().x);
      ASSERT_EQ(15, pixel.getPosition().y);
      ASSERT_EQ(Color::Red, pixel.getColor());
   }

   TEST(PixelTest, Draw)
   {
      Window window(100, 50);
      Pixel pixel(Color::Parmesean, 10, 15);
      pixel.draw(window);
      ASSERT_EQ(Color::Parmesean, window.getCanvas()[15][10]);
   }
}