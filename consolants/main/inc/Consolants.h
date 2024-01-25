#pragma once

#include "../../logic/inc/Simulation.h"

#include "../../view/inc/Window.h"

namespace ants::main
{
   class Consolants final : public logic::Simulation
   {
   public:
      Consolants();
   
   private:
      void display() override;

      view::Window window;
   };
}