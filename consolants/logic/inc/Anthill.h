#pragma once

#include "../inc/Object.h"
#include "../inc/World.h"

namespace ants::logic
{
   class Anthill : public Object
   {
   public:
      Anthill(int colonyId, int x, int y, World& world);
      Anthill(int colonyId, const math::Point& position, World& world);
      
      virtual void update(float dt);

      void addFood(int food);
      int getColonyId() const;
      int getFood();

   private:
      int colonyId;
      int food = 5;
      float creationTime = 2.f;
      float time = 0.f;

      World& world;
   };
}