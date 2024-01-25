#pragma once

#include "../inc/Color.h"

#include <vector>

namespace ants::view
{
   class CoutStringPreparator
   {
   public:
      std::string prepareCoutString(
         const std::vector<std::vector<Color>>& canvas) const;
   };
}