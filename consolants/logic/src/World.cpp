#include "../inc/Ant.h"
#include "../inc/Anthill.h"
#include "../inc/World.h"

#include <algorithm>

namespace ants::logic
{
   World::World(int x, int y, int colonies, int feed) : size(x, y) {}

   World::World(const math::Point& size, int colonies, int feed) : size(size)
   {
      srand(time(NULL));
      for(int i = 0; i < feed; ++i)
      {
         int x = std::rand() % size.x;
         int y = std::rand() % size.y;
         foods.push_back(std::make_unique<Food>(x, y));
      }

      for (int i = 0; i < colonies; ++i)
      {
         math::Point anthillPosition;
         while (true)
         {
            anthillPosition.x = std::rand() % size.x;
            anthillPosition.y = std::rand() % size.y;
            auto find = std::find_if(anthills.begin(), anthills.end(),
               [anthillPosition](const auto& anthill)
               {
                  return anthillPosition == anthill->getPosition();
               });
            if (find == anthills.end())
            {
               anthills.push_back(std::make_unique<Anthill>(i, anthillPosition.x,
                  anthillPosition.y, *this));
               break;
            }
         }
      }
   }

   void World::update(float dt)
   {
      for (auto antIt = ants.begin(); antIt != ants.end();)
      {
         if (antIt->get()->isDead())
         {
            antIt = ants.erase(antIt);
         }
         else
         {
            antIt->get()->update(dt);
            ++antIt;
         }
      }

      for (auto& anthill : anthills)
      {
         anthill->update(dt);
      }
   }

   void World::addAnt(Anthill& anthill, int x, int y)
   {
      ants.push_back(std::make_shared<Ant>(x, y, anthill, *this));
   }

   void World::addAnthill(int colonyId, int x, int y)
   {
      anthills.push_back(std::make_shared<Anthill>(colonyId, x, y, *this));
   }

   bool World::isFoodOutsideAnthills() const
   {
      if (!foods.empty())
      {
         return true;
      }

      for(const auto& ant : ants)
      {
         if (ant->getFood() != 0)
         {
            return true;
         }
      }
      return false;
   }

   int World::getBestColonyId() const
   {
      auto best = std::max_element(anthills.begin(), anthills.end(),
         [](const auto &lhs, const auto &rhs)
         {
            return lhs->getFood() < rhs->getFood();
         });
      return best->get()->getColonyId();
   }

   const std::vector<std::shared_ptr<Ant>>& World::getAnts() const
   {
      return ants;
   }

   const std::vector<std::shared_ptr<Anthill>>& World::getAnthills() const
   {
      return anthills;
   }

   const std::vector<std::shared_ptr<Food>>& World::getFoods() const
   {
      return foods;
   }
}