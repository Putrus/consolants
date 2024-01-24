#pragma once

#include "Window.h"

namespace ca
{
   class Simulation
   {
   public:
      Simulation();

      void run();

   private:
      void display();
      void update(float dt);
      Window window;
   };
}