#pragma once

#include <iostream>

namespace ants::math
{
   struct Point
   {
      Point();
      Point(int value);
      Point(int x, int y);
      Point(const Point& other);
      virtual ~Point();

      Point operator+(const Point& other) const;
      Point operator-(const Point& other) const;
      Point operator*(int num) const;
      Point operator/(int num) const;

      Point& operator+=(const Point& other);
      Point& operator-=(const Point& other);
      Point& operator*=(int num);

      int x;
      int y;
   };

   std::istream& operator>>(std::istream& is, Point& vec);

   std::ostream& operator<<(std::ostream& os, const Point& vec);

   bool operator==(const Point& lhs, const Point& rhs);

   bool operator!=(const Point& lhs, const Point& rhs);
}