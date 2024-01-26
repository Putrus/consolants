#include "../inc/CoutStringPreparator.h"

#include <sstream>

constexpr int OFFSET_BACKGROUND_COLOR = 10;

namespace ants::view
{
   std::string CoutStringPreparator::prepareCoutString(
      const std::vector<std::vector<Color>>& canvas) const
   {
      std::stringstream ss;
      for (size_t y = 0; y < canvas.size(); y += 2)
      {
         for (size_t x = 0; x < canvas[y].size(); ++x)
         {
            ss << "\x1B[" << canvas[y][x];
            if (y + 1 < canvas.size())
            { 
              ss << ';' << (int)canvas[y + 1][x] + OFFSET_BACKGROUND_COLOR;
            }
            ss << "m\xDF";
         }
         ss << "\n";
      }
      ss << "\x1B[0m";
      return ss.str();
   }
}