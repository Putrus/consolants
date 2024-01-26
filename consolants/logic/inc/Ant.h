#pragma once

#include "../inc/Object.h"
#include "../inc/World.h"

namespace ants::logic
{
   class Ant : public Object
   {
   public:
      Ant(int x, int y, Anthill& anthill, World& world);
      Ant(const math::Point& position, Anthill& anthill, World& world);

      virtual void update(float dt);

      void attack(const std::shared_ptr<Ant>& other) const;
      void getAttacked();
      
      bool isDead() const;

      int getColonyId() const;
      int getFood() const;

   private:
      void setRandomFoodDestination();

      math::Point destination;
      int food = 0;
      int strength = 1;
      float moveTime = 0.048f;
      float time = 0.f;

      Anthill& anthill;
      World& world;
   };
}