#include "../inc/CoutStringPreparatorTest.h"

namespace ants::view::ut
{
   void CoutStringPreparatorTest::SetUp() {}

   void CoutStringPreparatorTest::TearDown()
   {
      canvas.clear();
   }

   TEST_F(CoutStringPreparatorTest, OneRowItaly)
   {
      canvas = { { Color::Green, Color::White, Color::Red }};
      std::string coutString = preparator.prepareCoutString(canvas);
      ASSERT_EQ("\x1B[32m\xDF\x1B[97m\xDF\x1B[31m\xDF\n\x1B[0m", coutString);
   }

   TEST_F(CoutStringPreparatorTest, TwoRowsPoland)
   {
      canvas = { { Color::White, Color::White, Color::White },
         { Color::Red, Color::Red, Color::Red }};
      std::string coutString = preparator.prepareCoutString(canvas);
      ASSERT_EQ("\x1B[97;41m\xDF\x1B[97;41m\xDF\x1B[97;41m\xDF\n\x1B[0m", coutString);
   }

   TEST_F(CoutStringPreparatorTest, ThreeRowsLithuania)
   {
      canvas = { { Color::Gold, Color::Gold, Color::Gold },
         { Color::Green, Color::Green, Color::Green },
         { Color::Red, Color::Red, Color::Red }};
      std::string coutString = preparator.prepareCoutString(canvas);
      ASSERT_EQ("\x1B[33;42m\xDF\x1B[33;42m\xDF\x1B[33;42m\xDF\n\x1B[31m\xDF\x1B[31m\xDF\x1B[31m\xDF\n\x1B[0m", coutString);
   }

   TEST_F(CoutStringPreparatorTest, NotEqualRows)
   {
      canvas = { { Color::Gold },
         { Color::Parmesean, Color::Parmesean },
         { Color::Cyan, Color::Cyan, Color::Cyan }};
      std::string coutString = preparator.prepareCoutString(canvas);
      ASSERT_EQ("\x1B[33;103m\xDF\n\x1B[96m\xDF\x1B[96m\xDF\x1B[96m\xDF\n\x1B[0m", coutString);
   }
}