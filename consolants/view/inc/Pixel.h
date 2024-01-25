#pragma once

#include "../inc/Color.h"
#include "../inc/Drawable.h"

#include "../../math/inc/Point.h"

namespace ants::view
{
   class Pixel : public Drawable
   {
   public:
      Pixel(Color color, int x, int y);
      Pixel(Color color, const math::Point& position);

      virtual void draw(Window& window) const;

      Color getColor() const;
      
      const math::Point& getPosition() const;

   private:
      Color color;
      math::Point position;
   };
}