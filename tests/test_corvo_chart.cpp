#include <gtest/gtest.h>
#include "corvo_chart.hpp"
#include <fstream>

using namespace std;

TEST(TestBaseChart, createBackground) {
  shared_ptr<vector<double>> x{new vector<double>{1.4, 5.6, 9.2, 0.4, 5.6, 2.9, 4.4, 9.5, 2.3, 5.6, 10.2, 2.5, 0.3, 5}};
  HistoChart chart{"histo", 800, 600, "Hello Chart"};
  chart.add_data(x);
  fstream f{"../test_svg.svg", fstream::out};
  f << chart.draw();
  EXPECT_EQ(chart.draw(), "xxx");
}