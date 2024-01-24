#pragma once

#pragma once

#include <iostream>

namespace ca
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
}