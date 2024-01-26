#include "../inc/Food.h"

namespace ants::logic
{
   Food::Food(int x, int y) : Object(x, y) {}

   Food::Food(const math::Point& position) : Object(position) {}

   void Food::update(float dt) {}
}