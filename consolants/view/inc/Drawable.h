#pragma once

#include "../inc/Window.h"

namespace ants::view
{
   class Drawable
   {
   public:
      virtual void draw(Window& window) const = 0;
   };
}