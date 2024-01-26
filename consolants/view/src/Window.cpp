#include "../inc/Drawable.h"
#include "../inc/Pixel.h"
#include "../inc/Window.h"

#ifdef _WIN32
#include <windows.h>
#endif

namespace ants::view
{
   Window::Window(size_t x, size_t y)
   {
      hideCursor();
      for (size_t i = 0; i < y; ++i)
      {
         std::vector<Color> row;
         for (size_t j = 0; j < x; ++j)
         {
            row.push_back(clearColor);
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
            canvas[y][x] = clearColor;
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

   void Window::setPixel(Color color, int x, int y)
   {
      if (y < 0 || y >= static_cast<int>(canvas.size()) ||
         x < 0 || x >= static_cast<int>(canvas[y].size()))
      {
         return;
      }

      canvas[y][x] = color;
   }

   void Window::setPixel(Color color, const math::Point& position)
   {
      setPixel(color, position.x, position.y);
   }

   void Window::setPixel(const Pixel& pixel)
   {
      setPixel(pixel.getColor(), pixel.getPosition().x, pixel.getPosition().y);
   }

   void Window::setClearColor(Color color)
   {
      clearColor = color;
   }

   const std::vector<std::vector<Color>>& Window::getCanvas() const
   {
      return canvas;
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
      return coutStringPreparator.prepareCoutString(canvas);
   }
}