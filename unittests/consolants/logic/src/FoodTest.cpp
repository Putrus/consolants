#include "../../../../consolants/logic/inc/Food.h"

#include <gtest/gtest.h>

namespace ants::logic::ut
{
   TEST(FoodTest, FoodTwoArgumentsConstructor)
   {
      Food food(10, 9);
      ASSERT_EQ(10, food.getPosition().x);
      ASSERT_EQ(9, food.getPosition().y);
   }

   TEST(FoodTest, FoodOneArgumentConstructor)
   {
      Food food(math::Point(10, 9));
      ASSERT_EQ(10, food.getPosition().x);
      ASSERT_EQ(9, food.getPosition().y);
   }

   TEST(FoodTest, IsCollisionTwoFoodsTrue)
   {
      std::shared_ptr<Object> food1 = std::make_unique<Food>(10, 10);
      std::shared_ptr<Object> food2 = std::make_unique<Food>(10, 10);
      ASSERT_TRUE(food1->isCollision(food2));
      ASSERT_TRUE(food2->isCollision(food1));
   }

   TEST(FoodTest, IsCollisionTwoFoodsFalse)
   {
      std::shared_ptr<Object> food1 = std::make_unique<Food>(10, 10);
      std::shared_ptr<Object> food2 = std::make_unique<Food>(8, 10);
      ASSERT_FALSE(food1->isCollision(food2));
      ASSERT_FALSE(food2->isCollision(food1));
   }

   TEST(FoodTest, SetPositionTwoArguments)
   {
      std::shared_ptr<Object> food = std::make_unique<Food>(10, 10);
      food->setPosition(5, 6);
      ASSERT_EQ(5, food->getPosition().x);
      ASSERT_EQ(6, food->getPosition().y);
   }

   TEST(FoodTest, SetPositionOneArgument)
   {
      std::shared_ptr<Object> food = std::make_unique<Food>(10, 10);
      food->setPosition(math::Point(5, 6));
      ASSERT_EQ(5, food->getPosition().x);
      ASSERT_EQ(6, food->getPosition().y);
   }

   TEST(FoodTest, UpdateNothingChange)
   {
      std::shared_ptr<Object> food = std::make_unique<Food>(10, 7);
      food->update(10.f);
      ASSERT_EQ(10, food->getPosition().x);
      ASSERT_EQ(7, food->getPosition().y);
   }
}