#include "../inc/Point.h"

namespace ants::math
{
   Point::Point() : x(0), y(0) {}

   Point::Point(int value) : x(value), y(value) {}

   Point::Point(int x, int y) : x(x), y(y) {}

   Point::Point(const Point& other) : x(other.x), y(other.y) {}

   Point::~Point() {}

   Point Point::operator+(const Point& other) const
   {
      return { x + other.x, y + other.y };
   }

   Point Point::operator-(const Point& other) const
   {
      return { x - other.x, y - other.y };
   }

   Point Point::operator*(int num) const
   {
      return { x * num, y * num };
   }

   Point Point::operator/(int num) const
   {
      return { x / num, y / num };
   }

   Point& Point::operator+=(const Point& other)
   {
      x += other.x;
      y += other.y;
      return *this;
   }

   Point& Point::operator-=(const Point& other)
   {
      x -= other.x;
      y -= other.y;
      return *this;
   }

   Point& Point::operator*=(int num)
   {
      x *= num;
      y *= num;
      return *this;
   }

   std::istream& operator>>(std::istream& is, Point& vec)
   {
      is >> vec.x >> vec.y;
      return is;
   }

   std::ostream& operator<<(std::ostream& os, const Point& vec)
   {
      os << vec.x << ' ' << vec.y;
      return os;
   }

   bool operator==(const Point& lhs, const Point& rhs)
   {
      return lhs.x == rhs.x && lhs.y == rhs.y;
   }

   bool operator!=(const Point& lhs, const Point& rhs)
   {
      return lhs.x != rhs.x || lhs.y != rhs.y;
   }
}