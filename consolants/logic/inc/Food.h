#pragma once

#include "../inc/Object.h"

namespace ants::logic
{
   class Food : public Object
   {
   public:
      Food(int x, int y);
      Food(const math::Point& position);

      virtual void update(float dt) override;
   };
}