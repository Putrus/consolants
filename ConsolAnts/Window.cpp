#include "Drawable.h"
#include "Window.h"

#ifdef _WIN32
#include <Windows.h>
#endif

namespace ca
{
   Window::Window(int x, int y)
   {
      hideCursor();
      for (int i = 0; i < y; ++i)
      {
         std::vector<Color> row;
         for (int j = 0; j < x; ++j)
         {
            row.push_back(Color::Black);
         }
         canvas.push_back(row);
      }
   }

   void Window::clear()
   {
      for (int y = 0; y < canvas.size(); ++y)
      {
         for (int x = 0; x < canvas[y].size(); ++x)
         {
            canvas[y][x] = Color::Black;
         }
      }
   }

   void Window::draw(const Drawable& drawable)
   {
      draw(&drawable);
   }

   void Window::display() const
   {
      std::string coutString = prepareCoutString();
#ifdef _WIN32
      COORD cursorPosition;
      cursorPosition.X = 0;
      cursorPosition.Y = 0;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
#else
      system("clear");
#endif
      std::cout << coutString;
   }

   void Window::setPixelColor(Color color, int x, int y)
   {
      canvas[y][x] = color;
   }

   void Window::draw(const Drawable* drawable)
   {
      drawable->draw(*this);
   }

   void Window::hideCursor() const
   {
#ifdef _WIN32
      HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_CURSOR_INFO cursorInfo;
      GetConsoleCursorInfo(out, &cursorInfo);
      cursorInfo.bVisible = false;
      SetConsoleCursorInfo(out, &cursorInfo);
#endif
   }

   std::string Window::prepareCoutString() const
   {
      std::stringstream ss;
      for (size_t y = 0; y < canvas.size(); y += 2)
      {
         for (size_t x = 0; x < canvas[y].size(); ++x)
         {
            ss << "\033[" << canvas[y][x] << ';' <<
               (int)canvas[y + 1][x] + OFFSET_BACKGROUND_COLOR << 'm' << (char)-33;
         }
         ss << "\n";
      }
      return ss.str();
   }
}