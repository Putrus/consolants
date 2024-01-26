#pragma once

#include "../../logic/inc/Simulation.h"

#include "../../view/inc/Window.h"

namespace ants::main
{
   class Consolants : public logic::Simulation
   {
   public:
      Consolants(const math::Point &worldSize, int colonies, int feed);

      void showSummary() const;

   protected:
      void display() override;
      virtual void showAnthillsStatistics() const;
      virtual void drawFoods();
      virtual void drawAnthills();
      virtual void drawAnts();

      std::shared_ptr<view::Window> window;
   };
}