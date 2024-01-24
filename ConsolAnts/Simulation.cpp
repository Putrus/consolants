#include "Simulation.h"

#include <chrono>

constexpr float NANOSECONDS_PER_FRAME = 16666666.f; //60 frames per second

namespace ca
{
   Simulation::Simulation() : window(110, 50)
   {}

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
         while (time >= NANOSECONDS_PER_FRAME)
         {
            time -= NANOSECONDS_PER_FRAME;
            update(NANOSECONDS_PER_FRAME);
            display();
         }
      }
   }

   void Simulation::display()
   {
      window.clear();
      window.setPixelColor(Color::Sky, 5, 5);
      window.setPixelColor(Color::Sky, 6, 10);
      window.setPixelColor(Color::Sky, 5, 15);
      window.setPixelColor(Color::Sky, 7, 18);
      window.setPixelColor(Color::Red, 100, 45);
      window.setPixelColor(Color::Red, 101, 43);
      window.setPixelColor(Color::Red, 102, 46);
      window.setPixelColor(Color::Red, 100, 47);
      window.setPixelColor(Color::Green, 50, 26);
      window.setPixelColor(Color::Green, 53, 27);
      window.setPixelColor(Color::Green, 60, 29);
      window.setPixelColor(Color::Green, 54, 23);
      window.display();
   }

   void Simulation::update(float dt)
   {
      //update elements
   }
}