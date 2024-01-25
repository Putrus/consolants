#include "../inc/Simulation.h"

#include <chrono>
#include <utility>

namespace ants::logic
{
   Simulation::Simulation(float nanosecondsPerFrame, float updateDeltaTime)
    : nanosecondsPerFrame(nanosecondsPerFrame), updateDeltaTime(updateDeltaTime) {}

   void Simulation::run()
   {
      auto begin = std::chrono::steady_clock::now();
      auto end = std::chrono::steady_clock::now();
      float time = 0.f;

      while (true)
      {
         end = std::chrono::steady_clock::now();
         time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
         begin = std::move(end);
         while (time >= nanosecondsPerFrame)
         {
            time -= nanosecondsPerFrame;
            update();
            display();
         }
      }
   }

   void Simulation::display() {}

   void Simulation::update()
   {
      //update elements
   }
}