#include "corvo_svg.hpp"
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;

Svg::Svg(const string& id, int width, int height) : XmlElmt("svg", id) {
  this->add_props("xmlns", "http://www.w3.org/2000/svg");
  this->add_props("xmlns:xlink", "http://www.w3.org/1999/xlink");
  this->add_props("shape-rendering", "geometricPrecision");
  this->add_props("text-rendering", "geometricPrecision");
  this->add_props("viewBox", "0 0 " + std::to_string(width) + " " + std::to_string(height));
}

Rect::Rect(const string& id, int x1, int y1, int x2, int y2, const string& fill_hex, int stroke_width, const string& stroke_color) : XmlElmt("rect", id) {
  //if (x2 < x1) throw std::runtime_error("x2 cant be minor than x1");
  //if (y2 < y1) throw std::runtime_error("y2 cant be minor than y1");
  this->add_props("width", std::to_string(x2 - x1));
  this->add_props("height", std::to_string(y2 - y1));
  this->add_props("x", std::to_string(x1));
  this->add_props("y", std::to_string(y1));
  this->add_props("fill", fill_hex);
  this->add_props("stroke", stroke_color);
  this->add_props("stroke-width", std::to_string(stroke_width));
}

Line::Line(const string& id, int x1, int y1, int x2, int y2, int stroke_width, const string& stroke_color) : XmlElmt("line", id) {
  this->add_props("x1", std::to_string(x1));
  this->add_props("y1", std::to_string(y1));
  this->add_props("x2", std::to_string(x2));
  this->add_props("y2", std::to_string(y2));
  this->add_props("stroke", stroke_color);
  this->add_props("stroke-width", std::to_string(stroke_width));
}

Text::Text(const string& id, const string& text, int x, int y, int font_size, const string& font_color, bool bold, bool italic) : XmlElmt("text", id) {
  std::stringstream ss_style;
  ss_style << "font: ";
  if (bold) ss_style << "bold ";
  if (italic) ss_style << "italic ";
  ss_style << std::to_string(font_size) << "px arial; fill: " << font_color;
  this->add_props("x", std::to_string(x));
  this->add_props("y", std::to_string(y));
  this->add_props("style", ss_style.str());
  this->inner_text = text;
}
