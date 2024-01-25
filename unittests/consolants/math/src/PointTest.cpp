#include "../../../../consolants/math/inc/Point.h"

#include <gtest/gtest.h>

namespace ants::math::ut
{
   TEST(PointTest, DefaultConstructor)
   {
      Point p;
      ASSERT_EQ(0, p.x);
      ASSERT_EQ(0, p.y);
   }

   TEST(PointTest, ValueConstructor)
   {
      Point p(5);
      ASSERT_EQ(5, p.x);
      ASSERT_EQ(5, p.y);
   }

   TEST(PointTest, TwoArgConstructor)
   {
      Point p(2, 3);
      ASSERT_EQ(2, p.x);
      ASSERT_EQ(3, p.y);
   }

   TEST(PointTest, CopyConstructor)
   {
      Point original(4, 7);
      Point copy(original);
      ASSERT_EQ(original.x, copy.x);
      ASSERT_EQ(original.y, copy.y);
   }

   TEST(PointTest, AdditionOperator)
   {
      Point p1(2, 3);
      Point p2(4, 5);
      Point result = p1 + p2;
      ASSERT_EQ(6, result.x);
      ASSERT_EQ(8, result.y);
   }

   TEST(PointTest, SubtractionOperator)
   {
      Point p1(5, 8);
      Point p2(2, 3);
      Point result = p1 - p2;
      ASSERT_EQ(3, result.x);
      ASSERT_EQ(5, result.y);
   }

   TEST(PointTest, MultiplicationOperator)
   {
      Point p(3, 4);
      Point result = p * 2;
      ASSERT_EQ(6, result.x);
      ASSERT_EQ(8, result.y);
   }

   TEST(PointTest, DivisionOperator)
   {
      Point p(6, 8);
      Point result = p / 2;
      ASSERT_EQ(3, result.x);
      ASSERT_EQ(4, result.y);
   }

   TEST(PointTest, AdditionAssignmentOperator)
   {
      Point p1(2, 3);
      Point p2(4, 5);
      p1 += p2;
      ASSERT_EQ(6, p1.x);
      ASSERT_EQ(8, p1.y);
   }

   TEST(PointTest, SubtractionAssignmentOperator)
   {
      Point p1(5, 8);
      Point p2(2, 3);
      p1 -= p2;
      ASSERT_EQ(3, p1.x);
      ASSERT_EQ(5, p1.y);
   }

   TEST(PointTest, MultiplicationAssignmentOperator)
   {
      Point p(3, 4);
      p *= 2;
      ASSERT_EQ(6, p.x);
      ASSERT_EQ(8, p.y);
   }

   TEST(PointTest, InputOperator)
   {
      Point p;
      std::stringstream input("12 15");
      input >> p;
      ASSERT_EQ(12, p.x);
      ASSERT_EQ(15, p.y);
   }

   TEST(PointTest, OutputOperator)
   {
      Point p(8, 10);
      std::stringstream output;
      output << p;
      ASSERT_EQ("8 10", output.str());
   }

   TEST(PointTest, EqualityOperator)
   {
      Point p1(3, 5);
      Point p2(3, 5);
      ASSERT_EQ(p1, p2);
   }

   TEST(PointTest, InequalityOperator)
   {
      Point p1(3, 5);
      Point p2(4, 5);
      ASSERT_NE(p1, p2);
   }
}