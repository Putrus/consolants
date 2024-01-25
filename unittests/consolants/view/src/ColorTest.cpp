#include "../inc/ColorTest.h"

namespace ants::view::ut
{
   void ColorTest::SetUp() {}

   void ColorTest::TearDown()
   {
      output.str("");
   }

   TEST_F(ColorTest, OutputOperatorBlack)
   {
      output << Color::Black;
      ASSERT_EQ("30", output.str());
   }

   TEST_F(ColorTest, OutputOperatorRed)
   {
      output << Color::Red;
      ASSERT_EQ("31", output.str());
   }

   TEST_F(ColorTest, OutputOperatorGreen)
   {
      output << Color::Green;
      ASSERT_EQ("32", output.str());
   }

   TEST_F(ColorTest, OutputOperatorGold)
   {
      output << Color::Gold;
      ASSERT_EQ("33", output.str());
   }

   TEST_F(ColorTest, OutputOperatorBlue)
   {
      output << Color::Blue;
      ASSERT_EQ("34", output.str());
   }

   TEST_F(ColorTest, OutputOperatorPurple)
   {
      output << Color::Purple;
      ASSERT_EQ("35", output.str());
   }

   TEST_F(ColorTest, OutputOperatorArctic)
   {
      output << Color::Arctic;
      ASSERT_EQ("36", output.str());
   }

   TEST_F(ColorTest, OutputOperatorNormal)
   {
      output << Color::Normal;
      ASSERT_EQ("37", output.str());
   }

   TEST_F(ColorTest, OutputOperatorGray)
   {
      output << Color::Gray;
      ASSERT_EQ("90", output.str());
   }

   TEST_F(ColorTest, OutputOperatorBlush)
   {
      output << Color::Blush;
      ASSERT_EQ("91", output.str());
   }

   TEST_F(ColorTest, OutputOperatorShamrock)
   {
      output << Color::Shamrock;
      ASSERT_EQ("92", output.str());
   }

   TEST_F(ColorTest, OutputOperatorParmesean)
   {
      output << Color::Parmesean;
      ASSERT_EQ("93", output.str());
   }

   TEST_F(ColorTest, OutputOperatorSky)
   {
      output << Color::Sky;
      ASSERT_EQ("94", output.str());
   }

   TEST_F(ColorTest, OutputOperatorMagenta)
   {
      output << Color::Magenta;
      ASSERT_EQ("95", output.str());
   }

   TEST_F(ColorTest, OutputOperatorCyan)
   {
      output << Color::Cyan;
      ASSERT_EQ("96", output.str());
   }

   TEST_F(ColorTest, OutputOperatorWhite)
   {
      output << Color::White;
      ASSERT_EQ("97", output.str());
   }
}