#include "../inc/Consolants.h"

#include <windows.h>

int main()
{
   HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
   DWORD consoleMode;
   GetConsoleMode(out, &consoleMode);
   consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
   SetConsoleMode(out, consoleMode);

   ants::math::Point worldSize;
   int colonies = 0;
   int feed = 0;
   std::cout << "-- ConsolAnts - Ants simulation in the console line --" << std::endl;

   while (true)
   {
      std::cout << "Enter the world width (1 - 111): ";
      std::cin >> worldSize.x;
      if (worldSize.x < 1 || worldSize.x > 111)
      {
         std::cout << "\x1B[31mWrong world size. Try again.\x1B[0m" << std::endl;
         continue;
      }
      else
      {
         break;
      }
   }

   while (true)
   {
      std::cout << "Enter the world height (1 - 52): ";
      std::cin >> worldSize.y;
      if (worldSize.y < 1 || worldSize.y > 52)
      {
         std::cout << "\x1B[31mWrong world size. Try again.\x1B[0m" << std::endl;
         continue;
      }
      else
      {
         break;
      }
   }

   while (true)
   {
      std::cout << "Enter the number of ant colonies (1 - 7): ";
      std::cin >> colonies;
      if (colonies < 1 || colonies > 7)
      {
         std::cout << "\x1B[31mWrong colonies number. Try again.\x1B[0m" << std::endl;
         continue;
      }
      else
      {
         break;
      }
   }

   while (true)
   {
      std::cout << "Enter the amount of food (1 - 10000): ";
      std::cin >> feed;
      if (feed < 1 || feed > 10000)
      {
         std::cout << "\x1B[31mWrong food amount. Try again.\x1B[0m" << std::endl;
         continue;
      }
      else
      {
         break;
      }
   }
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
   ants::main::Consolants consolants(worldSize, colonies, feed);
   consolants.run();
   consolants.showSummary();
   system("pause");
   return 0;
}