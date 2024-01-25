#include "../inc/Consolants.h"

constexpr float NANOSECONDS_PER_FRAME = 16666666.f;

namespace ants::main
{
   Consolants::Consolants() : Simulation(NANOSECONDS_PER_FRAME,
      NANOSECONDS_PER_FRAME), window(110, 50) {}

   void Consolants::display()
   {
      window.clear();
      window.setPixel(view::Color::Sky, 5, 5);
      window.setPixel(view::Color::Sky, 6, 10);
      window.setPixel(view::Color::Sky, 5, 15);
      window.setPixel(view::Color::Sky, 7, 18);
      window.setPixel(view::Color::Red, 100, 45);
      window.setPixel(view::Color::Red, 101, 43);
      window.setPixel(view::Color::Red, 102, 46);
      window.setPixel(view::Color::Red, 100, 47);
      window.setPixel(view::Color::Green, 50, 26);
      window.setPixel(view::Color::Green, 53, 27);
      window.setPixel(view::Color::Green, 60, 29);
      window.setPixel(view::Color::Green, 54, 23);
      window.display();
   }
}