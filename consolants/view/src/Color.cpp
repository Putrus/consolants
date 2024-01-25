#include "../inc/Color.h"

namespace ants::view
{
   std::ostream& operator<<(std::ostream& os, Color color)
   {
      os << (int)color;
      return os;
   }
}