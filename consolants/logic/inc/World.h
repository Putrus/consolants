#pragma once

#include "../inc/Food.h"

#include "../../math/inc/Point.h"

#include <memory>
#include <vector>

namespace ants::logic
{
   class Ant;
   class Anthill;

   class World
   {
   public:
      World(int x, int y, int colonies, int feed);
      World(const math::Point& size, int colonies, int feed);

      void update(float dt);
      void addAnt(Anthill& anthill, int x, int y);
      void addAnthill(int colonyId, int x, int y);

      bool isFoodOutsideAnthills() const;
      int getBestColonyId() const;

      const std::vector<std::shared_ptr<Ant>>& getAnts() const;
      const std::vector<std::shared_ptr<Anthill>>& getAnthills() const;
      const std::vector<std::shared_ptr<Food>>& getFoods() const;

      friend class Ant;

   protected:
      math::Point size;

      std::vector<std::shared_ptr<Anthill>> anthills;
      std::vector<std::shared_ptr<Ant>> ants;
      std::vector<std::shared_ptr<Food>> foods;
   };
}