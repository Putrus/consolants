#pragma once
#include "../../../../consolants/view/inc/Color.h"

#include <gtest/gtest.h>

namespace ants::view::ut
{
   class ColorTest : public testing::Test
   {
   protected:
      void SetUp() override;

      void TearDown() override;

      std::stringstream output;
   };
}