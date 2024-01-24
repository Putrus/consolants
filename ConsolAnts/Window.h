#pragma once

#include "Color.h"

#include <iostream>
#include <sstream>
#include <vector>

constexpr int OFFSET_BACKGROUND_COLOR = 10;

namespace ca
{
   class Drawable;

   class Window final
   {
   public:
      Window(int x, int y);

      void clear();
      void draw(const Drawable& drawable);
      void display() const;
      void setPixelColor(Color color, int x, int y);

   private:
      void draw(const Drawable* drawable);
      void hideCursor() const;
      std::string prepareCoutString() const;

      std::vector<std::vector<Color>> canvas;
};
}