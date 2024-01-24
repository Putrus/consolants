#include "Pixel.h"

namespace ca
{
   Pixel::Pixel(Color color, const Point& position) : color(color), position(position) {}

   Pixel::Pixel(Color color, int x, int y) : color(color), position(x, y) {}

   void Pixel::draw(Window& window) const
   {
      window.setPixelColor(color, position.x, position.y);
   }
}