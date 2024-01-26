#pragma once

#include "../inc/World.h"

#include <vector>

namespace ants::logic
{
   class Simulation
   {
   public:
      Simulation(const math::Point& worldSize, int colonies, float nanosecondsPerFrame, float updateDeltaTime);

      void run();

   protected:
      World world;

   private:
      virtual void display();
      void update();

      float nanosecondsPerFrame;
      float updateDeltaTime;
   };
}