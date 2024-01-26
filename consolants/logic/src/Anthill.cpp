#include "../inc/Anthill.h"

namespace ants::logic
{
   Anthill::Anthill(int colonyId, int x, int y, World& world)
      : colonyId(colonyId), Object(x, y), world(world) {}

   Anthill::Anthill(int colonyId, const math::Point& position, World& world)
      : colonyId(colonyId), Object(position), world(world) {}

   void Anthill::update(float dt)
   {
      time += dt;
      std::cout << time << std::endl;
      if (food > 0 && time > creationTime)
      {
         time -= creationTime;
         --food;
         world.addAnt(*this, getPosition().x, getPosition().y);
      }
   }

   void Anthill::addFood(int food)
   {
      this->food += food;
   }

   int Anthill::getColonyId() const
   {
      return colonyId;
   }
}