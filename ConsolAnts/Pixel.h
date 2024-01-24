#pragma once

#include "Color.h"
#include "Drawable.h"
#include "Point.h"

namespace ca
{
   class Pixel : public Drawable
   {
   public:
      Pixel(Color color, const Point& position);
      Pixel(Color color, int x, int y);

      virtual void draw(Window& window) const;

   private:
      Color color;
      Point position;
   };
}