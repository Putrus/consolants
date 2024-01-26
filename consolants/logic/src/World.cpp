#include "../inc/Ant.h"
#include "../inc/Anthill.h"
#include "../inc/World.h"

namespace ants::logic
{
   World::World(int x, int y) : size(x, y) {}

   World::World(const math::Point& size) : size(size)
   {
      for(int i = 0; i < 200; ++i)
      {
         int x = std::rand() % size.x;
         int y = std::rand() % size.y;
         foods.push_back(std::make_unique<Food>(x, y));
      }
      anthills.push_back(std::make_unique<Anthill>(0, 10, 10, *this));
      anthills.push_back(std::make_unique<Anthill>(1, 100, 40, *this));
   }

   void World::update(float dt)
   {
      for (auto& ant : ants)
      {
         ant->update(dt);
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