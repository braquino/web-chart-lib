#include <gtest/gtest.h>
#include "corvo_svg.hpp"

TEST(SvgTest, ClassInit) {
  Svg svg{"svg_id", 800, 600};
  EXPECT_EQ(svg.gen_xml(), "<svg id=\"svg_id\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" shape-rendering=\"geometricPrecision\" text-rendering=\"geometricPrecision\" viewBox=\"0 0 800 600\"></svg>");
}

TEST(RectTest, ClassInit) {
  Rect rect{"rect_id", 5, 6, 200, 180};
  EXPECT_EQ(rect.gen_xml(), "<rect id=\"rect_id\" width=\"195\" height=\"174\" x=\"5\" y=\"6\" fill=\"none\" stroke=\"#000000\" stroke-width=\"1\"></rect>");
}

TEST(LineTest, ClassInit) {
  Line line{"line_id", 90, 20, 300, 30};
  EXPECT_EQ(line.gen_xml(), "<line id=\"line_id\" x1=\"90\" y1=\"20\" x2=\"300\" y2=\"30\" stroke=\"#000000\" stroke-width=\"1\"></line>");
}

TEST(TextTest, ClassInit) {
  Text text{"text_id", "foo", 90, 150};
  EXPECT_EQ(text.gen_xml(), "<text id=\"text_id\" x=\"90\" y=\"150\" style=\"font: 10px arial; fill: #000000\">foo</text>");
}

TEST(SvgTest, Childs) {
  Svg svg{"svg_id", 300, 200};
  shared_ptr<XmlElmt> r{new Rect{"rect_id", 5, 6, 200, 180}};
  shared_ptr<XmlElmt> l{new Line{"line_id", 90, 20, 300, 30}};
  shared_ptr<XmlElmt> t{new Text{"text_id", "foo", 90, 150}};
  svg.add_child(r);
  svg.add_child(l);
  svg.add_child(t);
  string final_svg = svg.gen_xml();
  string xml_rect = r->gen_xml();
  string xml_line = l->gen_xml();
  string xml_text = t->gen_xml();
  EXPECT_TRUE(final_svg.find(xml_rect) != string::npos);
  EXPECT_TRUE(final_svg.find(xml_line) != string::npos);
  EXPECT_TRUE(final_svg.find(xml_text) != string::npos);
}
