#pragma once
#include "../../../../consolants/view/inc/CoutStringPreparator.h"

#include <gtest/gtest.h>

namespace ants::view::ut
{
   class CoutStringPreparatorTest : public testing::Test
   {
   protected:
      void SetUp() override;

      void TearDown() override;

      CoutStringPreparator preparator;
      std::vector<std::vector<Color>> canvas;
   };
}