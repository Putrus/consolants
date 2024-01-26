#include "../inc/Ant.h"
#include "../inc/Anthill.h"

namespace ants::logic
{
   Ant::Ant(int x, int y, Anthill& anthill, World& world)
      : Object(x, y), anthill(anthill), world(world)
   {
      setRandomFoodDestination();
   }

   Ant::Ant(const math::Point& position, Anthill& anthill, World& world)
      : Object(position), anthill(anthill), world(world)
   {
      setRandomFoodDestination();
   }

   void Ant::update(float dt)
   {
      time += dt;
      for (auto antIt = world.ants.begin(); antIt != world.ants.end();)
      {
         if (getColonyId() == antIt->get()->getColonyId())
         {
            ++antIt;
            continue;
         }
         if (position == antIt->get()->getPosition())
         {
            attack(*antIt);
            if (antIt->get()->isDead())
            {
               ++food;
               antIt = world.ants.erase(antIt);
               continue;
            }
         }
         ++antIt;
      }

      if (time < moveTime)
      {
         return;
      }

      time -= moveTime;
      if (position != destination)
      {
         if (std::abs(position.x - destination.x) > std::abs(position.y - destination.y))
         {
            if (position.x > destination.x)
            {
               --position.x;
            }
            else
            {
               ++position.x;
            }
         }
         else
         {
            if (position.y > destination.y)
            {
               --position.y;
            }
            else
            {
               ++position.y;
            }
         }
      }
      else if (position == anthill.getPosition())
      {
         anthill.addFood(food);
         ++strength;
         setRandomFoodDestination();
      }
      else
      {
         auto& foods = world.foods;
         for (auto foodIt = foods.begin(); foodIt != foods.end();)
         {
            if (isCollision(*foodIt))
            {
               foodIt = foods.erase(foodIt);
               ++food;
               destination = anthill.getPosition();
               return;
            }
            else
            {
               ++foodIt;
            }
         }
         setRandomFoodDestination();
      }
   }

   void Ant::attack(const std::shared_ptr<Ant>& other) const
   {
      other->getAttacked();
   }

   void Ant::getAttacked()
   {
      --strength;
   }

   bool Ant::isDead() const
   {
      return strength < 1;
   }

   int Ant::getColonyId() const
   {
      return anthill.getColonyId();
   }

   int Ant::getFood() const
   {
      return food;
   }

   void Ant::setRandomFoodDestination()
   {
      int randomFoodDestination = std::rand() % world.foods.size();
      destination = world.foods[randomFoodDestination]->getPosition();  
   }
}