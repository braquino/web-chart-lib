#ifndef CORVO_SVG_HPP_
#define CORVO_SVG_HPP_

#include "corvo_xml.hpp"


class Svg : public XmlElmt {
public:
  Svg(const string& id, int width, int height);
};

class Rect : public XmlElmt {
public:
  Rect(const string& id, int x1, int y1, int x2, int y2, const string& fill_hex = "none", int stroke_width = 1, const string& stroke_color="#000000");
};

class Line : public XmlElmt {
public:
  Line(const string& id, int x1, int y1, int x2, int y2, int stroke_width = 1, const string& stroke_color="#000000");
};

class Text : public XmlElmt {
public:
  Text(const string& id, const string& text, int x, int y, int font_size = 10, const string& font_color = "#000000", bool bold = false, bool italic = false);
};

#endif // CORVO_SVG_HPP_