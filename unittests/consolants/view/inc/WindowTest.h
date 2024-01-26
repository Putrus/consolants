#pragma once
#include "../../../../consolants/view/inc/Window.h"

#include <gtest/gtest.h>

namespace ants::view::ut
{
   class WindowTest : public testing::Test
   {
   protected:
      void SetUp() override;

      void TearDown() override;

      Window window = Window(100, 50);
   };
}