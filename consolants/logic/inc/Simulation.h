#pragma once

namespace ants::logic
{
   class Simulation
   {
   public:
      Simulation(float nanosecondsPerFrame, float updateDeltaTime);

      void run();

   private:
      virtual void display();
      void update();

      float nanosecondsPerFrame;
      float updateDeltaTime;
   };
}