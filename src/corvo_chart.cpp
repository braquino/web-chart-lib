#include "corvo_chart.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>

BaseChart::BaseChart(const string& id, int width, int height, const string& title) 
    : id{id}, width{width}, height{height}, title{title}, svg{shared_ptr<Svg>{new Svg{id, width, height}}} {
}

void BaseChart::create_bg() {
  this->svg->add_child(shared_ptr<XmlElmt>{new Rect{this->id + "_rect_bg", 0, 0, this->width, this->height, "#555555", 0}});
  int font_size = (float)this->width * 0.05f;
  int title_x = (float)this->width / 2.0f - (float)this->title.size() * (float)font_size / 4.0f;
  int title_y = (float)font_size * 1.3f;
  this->svg->add_child(shared_ptr<XmlElmt>{new Text{this->id + "_title", this->title, title_x, title_y, font_size, "#ffffff", true}});
  int border = this->height * 0.05f;
  this->plot_rect = {border, (int)(border * 2 + title_y), (int)(this->width - border), (int)(this->height - (border * 2))};
  this->svg->add_child(shared_ptr<XmlElmt>{new Rect{this->id + "_plot_area", plot_rect[0], plot_rect[1], plot_rect[2], plot_rect[3], "none", 1, "#bbbbbb"}});
}

HistoChart::HistoChart(const string& id, int width, int height, const string& title) : BaseChart(id, width, height, title), bars{10} {

}

void HistoChart::add_data(shared_ptr<vector<double>> _data) {
  this->data = _data;
}

void HistoChart::add_data(shared_ptr<vector<double>> _data, int bars) {
  this->bars = bars;
  this->add_data(data);
}

string HistoChart::draw() {
  if (this->data == nullptr) throw std::runtime_error("To draw chart data must be populated first calling HistoChart<T>.add_data()");
  this->create_bg();
  double min_data = std::min_element(this->data->begin(), this->data->end())[0];
  double max_data = std::max_element(this->data->begin(), this->data->end())[0];
  double range = max_data - min_data;
  double bin = range / (double)this->bars;
  vector<uint32_t> bars_count;
  bars_count.resize(this->bars, 0);
  for (double& v : *this->data) {
    int idx = (v - min_data) / range * bars;
    std::cout << idx << std::endl;
    bars_count[std::min((int)idx, bars)]++;
  }
  uint32_t max_bar = std::max_element(bars_count.begin(), bars_count.end())[0];
  int bar_width = (this->plot_rect[2] - this->plot_rect[0]) / (float)bars;
  for (int i = 0; i < bars; i++) {
    int pad_rect_y1 = this->plot_rect[1] + this->height * 0.05f;
    int x1 = this->plot_rect[0] + i * bar_width;
    int x2 = x1 + bar_width;
    int y2 = this->plot_rect[3];
    int y1 = pad_rect_y1 + (this->plot_rect[3] - pad_rect_y1) / max_bar * bars_count[i];
    std::cout << std::endl << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 << std::endl;
    this->svg->add_child(shared_ptr<XmlElmt>{new Rect{this->id + "_hist_bar_" + std::to_string(i), x1, y1, x2, y2, "#3354a5", 1}});
  }
  return this->svg->gen_xml();
}