#pragma once

#include "../inc/Color.h"

#include "../../math/inc/Point.h"

#include <iostream>
#include <sstream>
#include <vector>

namespace ants::view
{
   class Drawable;
   class Pixel;

   class Window final
   {
   public:
      Window(size_t x, size_t y);

      void clear();
      void draw(const Drawable& drawable);
      void display() const;
      void setPixel(Color color, int x, int y);
      void setPixel(Color color, const math::Point& position);
      void setPixel(const Pixel& pixel);

      void setClearColor(Color color);

   private:
      void draw(const Drawable* drawable);
      void hideCursor() const;
      std::string prepareCoutString() const;

      std::vector<std::vector<Color>> canvas;
      Color clearColor = Color::Black;
};
}