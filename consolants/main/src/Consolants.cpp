#include "../inc/Consolants.h"

#include "../../logic/inc/Ant.h"
#include "../../logic/inc/Anthill.h"

constexpr float NANOSECONDS_PER_FRAME = 16666666.f;
constexpr float SECONDS_PER_FRAME = 0.016f;

namespace ants::main
{
   Consolants::Consolants(const math::Point &worldSize, int colonies, int feed)
      : Simulation(worldSize, colonies, feed, NANOSECONDS_PER_FRAME,
      SECONDS_PER_FRAME), window(new view::Window(worldSize.x, worldSize.y))
   {}

   void Consolants::showSummary() const
   {
      int bestColonyId = world.getBestColonyId();
      std::cout << "There is no food on the screen. Simulation has ended!" << std::endl;
      std::cout << "\x1B[" << bestColonyId + (int)view::Color::Blush << "mAnt colony " <<
         bestColonyId << " won!"  << "\x1B[0m" << std::endl;
   }

   void Consolants::display()
   {
      window->clear();
      drawFoods();
      drawAnthills();
      drawAnts();
      window->display();
      showAnthillsStatistics();
   }

   void Consolants::showAnthillsStatistics() const
   {
      std::cout << ": ";
      for (const auto& anthill : world.getAnthills())
      {
         std::cout << "\x1B[" << anthill->getColonyId() +
            (int)view::Color::Blush << "m" << anthill->getFood() << "\x1B[0m : ";
      }
      std::cout << std::endl;
   }

   void Consolants::drawFoods()
   {
      for(const auto& food : world.getFoods())
      {
         window->setPixel(view::Color::Gray, food->getPosition());
      }
   }

   void Consolants::drawAnthills()
   {
      for(const auto& anthill : world.getAnthills())
      {
         window->setPixel((view::Color)(anthill->getColonyId() +
            (int)view::Color::Blush), anthill->getPosition());
      }
   }

   void Consolants::drawAnts()
   {
      for(const auto& ant : world.getAnts())
      {
         window->setPixel((view::Color)(ant->getColonyId() +
            (int)view::Color::Red), ant->getPosition());
      }
   }
}