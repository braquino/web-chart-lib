#ifndef CORVO_CHART_HPP_
#define CORVO_CHART_HPP_

#include "corvo_svg.hpp"

class BaseChart {
public:
  BaseChart(const string& id, int width, int height, const string& title);
  virtual string draw() = 0;
protected:
  const string id;
  const string title;
  int width;
  int height;
  shared_ptr<Svg> svg;
  vector<int> plot_rect;
  void create_bg();
  void add_x_axis(int x_lab_1, int x_lab_2, double min_data, double max_data, int bins);
  void add_y_axis(int y_lab_1, int y_lab_2, double min_data, double max_data, int bins);
};

class HistoChart : public BaseChart {
public:
  HistoChart(const string& id, int width = 800, int height = 600, const string& title = "");
  string draw();
  void add_data(shared_ptr<vector<double>> _data);
  void add_data(shared_ptr<vector<double>> _data, int bars);
protected:
  shared_ptr<vector<double>> data;
  int bars;
  void plot_bars(double range, int max_bar, const vector<int>& bars_count);
  vector<int> calculate_bars(double min_data, double range);
};

#endif // CORVO_CHART_HPP_