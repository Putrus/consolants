#include "../inc/Object.h"
#include "../inc/World.h"

namespace ants::logic
{
   Object::Object(int x, int y) : position(x, y) {}

   Object::Object(const math::Point& position) : position(position) {}

   bool Object::isCollision(const std::shared_ptr<Object>& other)
   {
      return position == other->getPosition();
   }

   const math::Point& Object::getPosition() const
   {
      return position;
   }

   void Object::setPosition(int x, int y)
   {
      position.x = x;
      position.y = y;
   }

   void Object::setPosition(const math::Point& position)
   {
      this->position = position;
   }
}