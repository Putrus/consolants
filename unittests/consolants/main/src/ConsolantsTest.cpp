#include "../inc/ConsolantsTest.h"

namespace ants::main::ut
{
   MockWindow::MockWindow() : Window(5, 5) {}

   MockConsolants::MockConsolants(std::shared_ptr<view::Window> window)
      : Consolants(math::Point(50, 50), 0, 0)
   {
      this->window = window;
   }

   void MockConsolants::display()
   {
      Consolants::display();
   }

   TEST(ConsolantsTest, DisplaySequence)
   {
      std::shared_ptr<view::Window> windowPtr = std::make_shared<MockWindow>();
      MockWindow& window = *(MockWindow*)windowPtr.get();
      MockConsolants consolants(windowPtr);
      {
         ::testing::InSequence sequence;

         EXPECT_CALL(window, clear()).Times(1);
         EXPECT_CALL(consolants, drawFoods()).Times(1);
         EXPECT_CALL(consolants, drawAnthills()).Times(1);
         EXPECT_CALL(consolants, drawAnts()).Times(1);
         EXPECT_CALL(window, display()).Times(1);  
      }

      consolants.display();
   }
}