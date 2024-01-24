#include "Color.h"

namespace ca
{
   std::ostream& operator<<(std::ostream& os, Color color)
   {
      os << (int)color;
      return os;
   }
}