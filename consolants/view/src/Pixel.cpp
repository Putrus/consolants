#include "../inc/Pixel.h"

namespace ants::view
{
   Pixel::Pixel(Color color, int x, int y) : color(color), position(x, y) {}

   Pixel::Pixel(Color color, const math::Point& position) : color(color), position(position) {}

   void Pixel::draw(Window& window) const
   {
      window.setPixel(color, position);
   }

   Color Pixel::getColor() const
   {
      return color;
   }

   const math::Point& Pixel::getPosition() const
   {
      return position;
   }
}