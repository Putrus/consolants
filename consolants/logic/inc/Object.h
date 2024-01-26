#pragma once

#include "../../math/inc/Point.h"

#include <memory>

namespace ants::logic
{
   class Object
   {
   public:
      Object(int x, int y);
      Object(const math::Point& position);

      bool isCollision(const std::shared_ptr<Object>& other);
      virtual void update(float dt) = 0;

      const math::Point& getPosition() const;
      void setPosition(int x, int y);
      void setPosition(const math::Point& position);

   protected:
      math::Point position;
   };
}