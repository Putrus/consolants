#pragma once

#include "../../logic/inc/Simulation.h"

#include "../../view/inc/Window.h"

namespace ants::main
{
   class Consolants final : public logic::Simulation
   {
   public:
      Consolants(const math::Point &worldSize, int colonies, int feed);

      void showSummary() const;

   private:
      void display() override;
      void showAnthillsStatistics() const;

      view::Window window;
   };
}