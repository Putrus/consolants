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
      ASSERT_EQ("\033[32m\xDF\033[97m\xDF\033[31m\xDF\n\033[0m", coutString);
   }

   TEST_F(CoutStringPreparatorTest, TwoRowsPoland)
   {
      canvas = { { Color::White, Color::White, Color::White },
         { Color::Red, Color::Red, Color::Red }};
      std::string coutString = preparator.prepareCoutString(canvas);
      ASSERT_EQ("\033[97;41m\xDF\033[97;41m\xDF\033[97;41m\xDF\n\033[0m", coutString);
   }

   TEST_F(CoutStringPreparatorTest, ThreeRowsLithuania)
   {
      canvas = { { Color::Gold, Color::Gold, Color::Gold },
         { Color::Green, Color::Green, Color::Green },
         { Color::Red, Color::Red, Color::Red }};
      std::string coutString = preparator.prepareCoutString(canvas);
      ASSERT_EQ("\033[33;42m\xDF\033[33;42m\xDF\033[33;42m\xDF\n\033[31m\xDF\033[31m\xDF\033[31m\xDF\n\033[0m", coutString);
   }

   TEST_F(CoutStringPreparatorTest, NotEqualRows)
   {
      canvas = { { Color::Gold },
         { Color::Parmesean, Color::Parmesean },
         { Color::Cyan, Color::Cyan, Color::Cyan }};
      std::string coutString = preparator.prepareCoutString(canvas);
      ASSERT_EQ("\033[33;103m\xDF\n\033[96m\xDF\033[96m\xDF\033[96m\xDF\n\033[0m", coutString);
   }
}