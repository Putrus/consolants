#pragma once

#include "Window.h"

namespace ca
{
   class Drawable
   {
   public:
      virtual void draw(Window& window) const = 0;
   };
}