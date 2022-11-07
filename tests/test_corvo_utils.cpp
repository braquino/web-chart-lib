#include <gtest/gtest.h>
#include "corvo_utils.hpp"

TEST(TestCorvoUtils, Round) {
  EXPECT_EQ(format_num<double>(2.76234, 2), "2.76");
  EXPECT_EQ(format_num<double>(540.999999, 5), "540.99999");
  EXPECT_EQ(format_num<double>(540.999999, 0), "540");
}
