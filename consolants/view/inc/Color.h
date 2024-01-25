#pragma once

#include <ostream>

namespace ants::view
{
   enum class Color : int
   {
      Black = 30,
      Red = 31,
      Green = 32,
      Gold = 33,
      Blue = 34,
      Purple = 35,
      Arctic = 36,
      Normal = 37,
      Gray = 90,
      Blush = 91,
      Shamrock = 92,
      Parmesean = 93,
      Sky = 94,
      Magenta = 95,
      Cyan = 96,
      White = 97
   };

   std::ostream& operator<<(std::ostream& os, Color color);
}