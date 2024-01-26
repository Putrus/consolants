#include "../inc/Consolants.h"

#include "../../logic/inc/Ant.h"
#include "../../logic/inc/Anthill.h"

constexpr float NANOSECONDS_PER_FRAME = 16666666.f;
constexpr float SECONDS_PER_FRAME = 0.016f;

namespace ants::main
{
   Consolants::Consolants() : Simulation(math::Point(110, 50), 4, NANOSECONDS_PER_FRAME,
      SECONDS_PER_FRAME), window(110, 50)
   {
      
   }

   void Consolants::display()
   {
      window.clear();
      const auto& foods = world.getFoods();
      for(const auto& food : foods)
      {
         window.setPixel(view::Color::Green, food->getPosition());
      }

      const auto& anthills = world.getAnthills();
      for(const auto& anthill : anthills)
      {
         if (anthill->getColonyId() == 0)
         {
            window.setPixel(view::Color::Sky, anthill->getPosition());
         }
         else
         {
            window.setPixel(view::Color::Blush, anthill->getPosition());
         }
      }

      const auto& ants = world.getAnts();
      for(const auto& ant : ants)
      {
         if (ant->getColonyId() == 0)
         {
            window.setPixel(view::Color::Blue, ant->getPosition());
         }
         else
         {
            window.setPixel(view::Color::Red, ant->getPosition());
         }
      }
      window.display();
      std::cout << "\033[94m" << anthills[0]->getFood() << "\033[0m : \033[91m" << anthills[1]->getFood() << std::endl; 
   }
}